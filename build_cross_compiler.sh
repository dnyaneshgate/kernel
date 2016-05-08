#!/bin/sh

export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

function build_binutils()
{
    mkdir build-binutils
    pushd build-binutils
    ../../Downloads/binutils-2.26/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror \
    && make \
    && make install \
    popd
}

function build_gcc()
{
    mkdir build-gcc
    pushd build-gcc

    # The $PREFIX/bin dir _must_ be in the PATH. We did that above.
    which -- $TARGET-as || echo $TARGET-as is not in the PATH

    ../../Downloads/gcc-5.3.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers \
    && make all-gcc \
    && make all-target-libgcc \
    && make install-gcc \
    && make install-target-libgcc
    popd
}


$1
