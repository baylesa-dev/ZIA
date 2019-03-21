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

This module is a basic SSL module. It allows encrypted communication, using SSL from [Boost Asio](https://www.boost.org/)


### PHP

### Debug

## Create your own module

You can create your own module to implement a new HTTP process.

```c++
class MyModule : public API::Module {
    /* methods */
};
```