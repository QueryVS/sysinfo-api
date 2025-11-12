#!/bin/bash

if [ "$1" == "prod" ]; then
    git clone https://github.com/QueryVS/sysinfo-api/ -b main
elif [ "$1" == "test" ]; then
    git clone https://github.com/QueryVS/sysinfo-api/ -b develop/anc
else
    git clone https://github.com/QueryVS/sysinfo-api/ -b "$1"
fi

cd sysinfo-api/

make
make install
