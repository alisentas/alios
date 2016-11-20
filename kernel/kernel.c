#include "tty.h"
#include "stdio.h"

void kmain(void);

void kmain(void) {
	/* Initialize terminal interface */
	terminal_initialize();

	// cowsay
	//printf(" _______\n< Ali OS >\n -------- \n        \\   ^__^\n         \\  (oo)\\_______\n            (__)\\       )\\/\\\n                ||----w |\n                ||     ||");
	printf("|%d", printf("%d %c %s", -234, 'a', "sdfg"));
}
