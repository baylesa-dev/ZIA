# Build and Start

## 	Prerequisites

You need a few packages to build Zia. Depending on your platform you will have to use differents ways.

#### Linux (Debian and derivated)

###### Install CMake and Conan

```bash
sudo apt update && sudo apt install cmake
```

```bash
curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
python get-pip.py
pip install conan
```

#### Windows

- Download [CMake Installer](https://cmake.org/download/)
- Download [get-pip.py](https://bootstrap.pypa.io/get-pip.py)
```bash
python get-pip.py
pip install conan
```

## Cloning

```bash
git clone https://gitlab.si0ls.fr/epitech/CPP_zia_2018.git
cd CPP_zia_2018
git submodule update --init --recursive
```

## Build

```bash
mkdir build && cd build
conan install .. && cmake .. -G "Unix Makefiles" && cmake --build .
```