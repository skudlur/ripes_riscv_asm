#include <stdio.h>
#include <uart.h>
#include <float.h>

unsigned long read_cycles(void) {
    unsigned long cycles;
    asm volatile ("rdcycle %0" : "=r" (cycles));
    return cycles;
}

void main() {
	unsigned long start, end, total;
	start = read_cycles();
	int i = 10;
	printf("%d", i);
}
