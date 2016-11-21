#include "tty.h"
#include "stdio.h"
#include "string.h"

void kmain(void);

void kmain(void) {
	/* Initialize terminal interface */
	terminal_initialize();

	// cowsay
	//printf(" _______\n< Ali OS >\n -------- \n        \\   ^__^\n         \\  (oo)\\_______\n            (__)\\       )\\/\\\n                ||----w |\n                ||     ||");
	//printf("|%d", printf("%d %c %s", -234, 'a', "sdfg"));
	printf("PRINTF TESTS\n============\n");
	printf("Number test: %d\n", -12345);
	printf("Char test: %c\n", 'c');
	printf("String test: %s\n", "test string");
	printf("Others: %%\n");
	printf("STRING TESTS\n============\n");
	const char *a = "abc";
	const char *b = "abd";
	printf("memcmp: %d\n", memcmp(a, b, 3));
	memcpy((void*)b, a, 3);
	printf("%s\n", b);
	memset((void*)a, '0', 3);
	printf("%s\n", a);
}
