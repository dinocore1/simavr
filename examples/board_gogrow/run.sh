#!/bin/bash

pushd ../../../gogrow/software/microcontroller
make
popd

cp ../../../gogrow/software/microcontroller/gogrow.elf gogrow.axf
./obj-x86_64-linux-gnu/gogrowsim.elf
