# CPP_zia_2018

Communication is key

## Install & Build

### Conan

Follow instructions on [https://docs.conan.io/en/latest/installation.html](https://docs.conan.io/en/latest/installation.html)

### Add conan repositories

```sh
conan remote add conan https://api.bintray.com/conan/conan/conan-center
conan remote add epitech https://api.bintray.com/conan/epitech/public-conan
conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan
```

### Pull submodules

```sh
git submodule update --init --recursive
```

### Build

In the project root dir :

```sh
mkdir build && cd build && conan install .. && cmake .. -G "Unix Makefiles" && cmake --build .
```
