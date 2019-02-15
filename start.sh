#!/usr/bin/env sh

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${PWD}/build/modules
export DYLD_LIBRARY_PATH=$LD_LIBRARY_PATH:${PWD}/build/modules

./build/bin/zia