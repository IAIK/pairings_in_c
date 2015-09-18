#!/bin/sh
BUILD_DIRECTORY=../build
mkdir $BUILD_DIRECTORY/dump
arm-none-eabi-objdump -S $1 > $BUILD_DIRECTORY/dump/main_main.dump
arm-none-eabi-objdump -x $1 > $BUILD_DIRECTORY/dump/header_main.dump
arm-none-eabi-nm -nS $1 > $BUILD_DIRECTORY/dump/main.dump
arm-none-eabi-objcopy -O ihex $1 $BUILD_DIRECTORY/dump/main.ihex
arm-none-eabi-size $1 > $BUILD_DIRECTORY/dump/main.size
