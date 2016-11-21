#include <stdint.h>
#include "vga.h"

const size_t VGA_WIDTH = 80;
const size_t VGA_HEIGHT = 25;

uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
	return (uint8_t)(fg | bg << 4);
}

uint16_t vga_entry(unsigned char uc, uint8_t color) {
	return (uint16_t)(uc | color << 8);
}
