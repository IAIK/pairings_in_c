#!/bin/sh
mkdir build/dump
arm-none-eabi-objdump -S $1 > build/dump/main_main.dump
arm-none-eabi-objdump -x $1 > build/dump/header_main.dump
arm-none-eabi-nm -nS $1 > build/dump/main.dump
arm-none-eabi-objcopy -O ihex $1 build/dump/main.ihex
arm-none-eabi-size $1 > build/dump/main.size
