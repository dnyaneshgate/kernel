#!/bin/sh

export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

export CC=${TARGET}-gcc
export CXX=${TARGET}-g++
export CPP=${TARGET}-cpp
export AS=${TARGET}-as
export LD=${TARGET}-ld
export ADDR2LINE=${TARGET}-addr2line
export AR=${TARGET}-ar
export OBJDUMP=${TARGET}-objdump
export OBJCOPY=${TARGET}-objcopy
export RANLIB=${TARGET}-ranlib
export READELF=${TARGET}-readelf
export SIZE=${TARGET}-size
export STRINGS=${TARGET}-strings
export STRIP=${TARGET}-strip
export GCC_NM=${TARGET}-gcc-nm
export ELFEDIT=${TARGET}-elfedit
