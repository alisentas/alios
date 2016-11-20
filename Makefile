CC=i686-elf-gcc
AS=i686-elf-as
LD=i686-elf-gcc
WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wuninitialized -Wconversion -Wstrict-prototypes
CFLAGS=-std=gnu99 -ffreestanding -O2 -fdiagnostics-color $(WARNINGS)
LDFLAGS=-ffreestanding -O2 -nostdlib -lgcc
ROOT_DIR=$$(pwd)
INCLUDES=-I$(ROOT_DIR)/kernel/include -I$(ROOT_DIR)/libc/include
BUILD_DIR=build

PROJDIRS=kernel libc
SRC=$(shell find $(PROJDIRS) -type f -name "*.c")
HDR=$(shell find $(PROJDIRS) -type f -name "*.h")
OBJ=$(patsubst %.c,%.o,$(SRC))

.PHONY: clean prepare qemu

all: prepare alios.iso

%.o: %.c
	$(CC) $(INCLUDES) -c $(CFLAGS) -o $(BUILD_DIR)/$(notdir $@) $<

%.o: %.s
	$(AS) $(ASFLAGS) -o $(BUILD_DIR)/$(notdir $@) $<

alios.bin: $(OBJ)
	$(AS) kernel/arch/i686/boot.s -o $(BUILD_DIR)/boot.o
	$(LD) $(LDFLAGS) -T kernel/arch/i686/linker.ld -o alios.bin build/*.o

alios.iso: alios.bin
	mkdir -p isodir/boot/grub
	cp grub.cfg isodir/boot/grub/grub.cfg
	cp alios.bin isodir/boot/alios.bin
	grub-mkrescue -o alios.iso isodir -d /usr/lib/grub/i386-pc

prepare:
	mkdir -p ${BUILD_DIR}

qemu:
	qemu-system-x86_64 -cdrom alios.iso

clean:
	rm alios.bin alios.iso
	rm -rf build isodir
