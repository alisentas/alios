#ifndef KERNEL_H
#define KERNEL_H

void kmain(void* multiboot_structure, unsigned int magicnumber);
void panic(const char *restrict format, ...);

#endif
