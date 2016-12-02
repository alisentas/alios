#include "tty.h"
#include "stdio.h"
#include "string.h"
#include "kernel.h"

/* We will use this later on for reading from the I/O ports to get data
*  from devices such as the keyboard. We are using what is called
*  'inline assembly' in these routines to actually do the work */
unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ (/*assembler template */"inb %1, %0" :/* output operands */ "=a" (rv) :/* input operands */ "dN" (_port));
    return rv;
}

/* We will use this to write to I/O ports to send bytes to devices. This
*  will be used in the next tutorial for changing the textmode cursor
*  position. Again, we use some inline assembly for the stuff that simply
*  cannot be done in C */
void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

void kmain(void* multiboot_structure, unsigned int magicnumber) {
	/* Initialize terminal interface */
	terminal_initialize();

	int i;
	for(i = 0; i < 20; i++){
		printf("printing: %d\n", i);
	}
	//printf("VGA_WIDTH=%d\nVGA_HEIGHT=%d", VGA_WIDTH, VGA_HEIGHT);
}
