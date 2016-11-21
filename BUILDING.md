To build the kernel, you need a cross c compiler. I personally use gcc for this.

## Building an i686-elf cross compiler

First, you need to download gcc and binutils, and other required stuff. Assuming you will build gcc in `~/cross/bin`.

    mkdir -p ~/cross/src
    cd src
    wget ftp://ftp.gnu.org/gnu/gcc/gcc-6.2.0/gcc-6.2.0.tar.bz2
    wget https://ftp.gnu.org/gnu/binutils/binutils-2.27.tar.bz2
    wget http://mirror.rackdc.com/gnu/mpfr/mpfr-3.1.5.tar.xz
    wget http://mirror.rackdc.com/gnu/gmp/gmp-6.1.1.tar.xz
    wget http://mirror.rackdc.com/gnu/mpc/mpc-1.0.3.tar.gz
    wget ftp://gcc.gnu.org/pub/gcc/infrastructure/isl-0.16.1.tar.bz2
    wget ftp://gcc.gnu.org/pub/gcc/infrastructure/cloog-0.18.1.tar.gz

Then, ready the environment, untar all packages:

    export PREFIX="/opt/cross"
    export TARGET=i686-elf
    export PATH="$PREFIX/bin:$PATH"
    for f in *.tar*; do tar xf $f; done
    cd gcc-6.2.0
    ln -s ../mpfr-3.1.5 mpfr
    ln -s ../gmp-6.1.1 gmp
    ln -s ../mpc-1.0.3 mpc
    ln -s ../isl-0.16.1 isl
    ln -s ../cloog-0.18.1 cloog

Build binutils:

    mkdir -p build-binutils
    cd build-binutils
    ../binutils-2.27/configure --target=$TARGET --prefix="$PREFIX" --with-sysroot --disable-nls --disable-werror
    linux32 make
    linux32 make install
    cd ..

Build gcc (This takes a bit of time):

    mkdir -p build-gcc
    cd build-gcc
    linux32 ../gcc-6.2.0/configure --target=$TARGET --prefix="$PREFIX" --disable-nls --enable-languages=c,c++ --without-headers
    linux32 make all-gcc
    linux32 make all-target-libgcc
    linux32 make install
    linux32 make install-target-libgcc

Make sure you add this line to your `.bashrc`, `.zshrc` or whatever shell you use.

    export PATH=/home/USERNAME/cross/bin:$PATH

## Building the kernel

Make sure you have **qemu** installed. `cd` into the directory you've downloaded the kernel code and enter `make` to build the kernel and `make qemu` to start virtual machine.
