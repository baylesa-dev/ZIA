# Modules

## Overview

A module is an atomic processing unit that can receive input from other modules and send output to them. It is possible to use any number of modules together to create a processing line that will handle an HTTP request and create an appropriate HTTP response.

> If you're a developper, you can [create your own module](#create-your-own-module).

Modules must be declared in a [*config.xml*](configuration.md) file.

All modules in modules path must be name this way: *zia-YOUR_MODULE_NAME.so*

> Some modules are embedded in Zia project. Check out the [List of modules](#list-of-modules).

You can use modules as below:

```shell
./zia --config="./config.xml" --modules="./modules/"
```

where _"./modules/"_ is a directory containing all your *Shared Objects* libraries.


## List of modules

This is the list of modules delivered with Zia.

### SSL

This module is a basic SSL module. It allows encrypted communication, using SSL from [Boost Asio](https://www.boost.org/).

> By default, Zia provide a certificat and a private key for symmetric cryptography. You can use them to test Zia, but for your security, you have to replace theses files. Learn how to generate a self-signed certificat using OpenSSL [here](https://www.ibm.com/support/knowledgecenter/en/SSWHYP_4.0.0/com.ibm.apimgmt.cmc.doc/task_apionprem_gernerate_self_signed_openSSL.html)


### Static

This module allows to serve static files (images, HTML, text, ...).

### Debug

Debug module logs requests informations on standard output to help you debug your application.

## Create your own module

You can create your own module to implement a new HTTP process.

#### Architecture

You have to create a directory containing few files :

    .
    +-- MyModule
    |   +-- CMakeLists.txt
    |   +-- factory.cpp
    |   +-- MyModule.hpp
    |   +-- MyRequestHandler.hpp


*CMakelists.txt*
```cmake
add_library(MyModule MODULE
    factory.cpp
)
set_target_properties(MyModule PROPERTIES PREFIX "zia-")
target_link_libraries(MyModule
    ${CONAN_LIBS_BOOST}
    ZiaModuleAPISpec
)
```

*factory.cpp*
```cpp
#include <iostream>
#include <Zia/API.hpp>

#include "Module.hpp"

ZIA_API_EXPORT Zia::API::Module::pointer factory() {
    return new Zia::Modules::Log::Module;
}

ZIA_API_EXPORT void recycler(Zia::API::Module::pointer instance) {
    delete instance;
}
```

*MyModule.hpp*
```cpp
#pragma once

#include <iostream>
#include <string>
#include <Zia/API.hpp>

#include "RequestHandler.hpp"

namespace Zia {
    namespace Modules {
        class Module : public API::Module {
            public:
            const std::string& getName() const override {
                return _name;
            }
            API::RequestHandler::pointer newRequestHandler() override {
                return std::make_shared<RequestHandler>();
            }
            private:
            std::string _name = "log";
        };
    }
}
```
*RequestHandler.hpp*
```cpp
#pragma once

#include <iostream>
#include <chrono>
#include <boost/asio.hpp>
#include <Zia/API.hpp>

using boost::asio::ip::tcp;

namespace Zia {
    namespace Modules {
        class RequestHandler : public API::RequestHandler {
            public:
            API::HookResultType onConnectionStart(const API::Connection& conn tcp::socket& sock) override;
            API::HookResultType onRequest(const API::Connection& conn, const API::Request& req, API::Response& res) override;
            API::HookResultType onResponse(const API::Connection& conn,API::Response& res) override;
            API::HookResultType onConnectionEnd(const API::Connection& conn,tcp::socket& sock) override;
        };
    }
}

```

> If you want to compile your module with Zia, remind to add it in root CMakeList.txt. **Check out below**

```cmake
/** **/
# Modules
add_subdirectory(modules/MyModule MyModule)
/** **/
```