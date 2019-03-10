project(zia)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

# Connan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

# Modules
add_subdirectory(modules/PHPModule PHPModule)
add_subdirectory(modules/DEBUGModule DEBUGModule)
add_subdirectory(lib/ZiaModuleAPISpec ZiaModuleAPISpec)

# Zia
include_directories(
    incs
    lib/ZiaModuleAPISpec/include/Zia
)

set(SOURCE_FILES
    srcs/main.cpp
    srcs/Server.cpp
    srcs/ServerClient.cpp
    srcs/Zia.cpp
    srcs/Cmd.cpp
    srcs/RequestsHandler.cpp
    srcs/LoadModules.cpp
    srcs/ParseRequest.cpp
)

add_executable(zia ${SOURCE_FILES})

# DEBUG ONLY!!
target_link_libraries(zia ZiaModuleAPISpec ${CONAN_LIBS} dl)
