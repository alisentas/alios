#include "tty.h"
#include "vga.h"
#include "string.h"

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;

/* Updates the hardware cursor: the little blinking line
*  on the screen under the last character pressed! */
void move_cursor(size_t row, size_t col)
{
    unsigned temp;

    /* The equation for finding the index in a linear
    *  chunk of memory can be represented by:
    *  Index = [(y * width) + x] */
    temp = row * 80 + col;

    /* This sends a command to indicies 14 and 15 in the
    *  CRT Control Register of the VGA controller. These
    *  are the high and low bytes of the index that show
    *  where the hardware cursor is to be 'blinking'. To
    *  learn more, you should look up some VGA specific
    *  programming documents. A great start to graphics:
    *  http://www.brackeen.com/home/vga */
    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}

void terminal_initialize(void) {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = vga_entry_color(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = vga_entry(' ', terminal_color);
		}
	}
}

void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}

void terminal_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = vga_entry(c, color);
}

void terminal_putchar(unsigned char c) {
	if(c == '\n'){
		if(++terminal_row == VGA_HEIGHT){
			scroll_terminal();
		}
		terminal_column = 0;
	}else if(c == '\r'){
		terminal_column = 0;
	}else{
		terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
		if (++terminal_column == VGA_WIDTH) {
			terminal_column = 0;
			if (++terminal_row == VGA_HEIGHT){
				scroll_terminal();
			}
		}
	}
	move_cursor(terminal_row, terminal_column);
}

void scroll_terminal(void){
	/*uint16_t i;
	for(i = (uint16_t)VGA_WIDTH; i < (uint16_t)(VGA_WIDTH * VGA_HEIGHT); i++){
		terminal_buffer[i - VGA_WIDTH] = terminal_buffer[i];
	}
	*/
	uint16_t blank = (uint16_t)(0x20 | (terminal_color << 8));
	memcpy16(terminal_buffer, terminal_buffer + VGA_WIDTH, VGA_WIDTH * (VGA_HEIGHT - 1));
	memset16(terminal_buffer + (VGA_WIDTH) * (VGA_HEIGHT - 1), blank, VGA_WIDTH);
	terminal_row = 24;
}

void terminal_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		terminal_putchar((unsigned char)data[i]);
}

void terminal_writestring(const char* data) {
	terminal_write(data, strlen(data));
}
