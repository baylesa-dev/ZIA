CMAKE_MINIMUM_REQUIRED(VERSION 3.0.2)

project(zia)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(Modules/PHPModule PHPModule)

if (MSVC)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}")
endif()

include_directories(
    incs
    Modules/incs
    lib/ZiaModuleAPISpec/include/Zia
)

set(SOURCE_FILES
    srcs/main.cpp
)

add_executable(zia ${SOURCE_FILES})

target_link_libraries(zia PHPModule ${CONAN_LIBS})
