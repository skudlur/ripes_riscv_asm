/*
 * This is a program to run a sequence of Fibonacci Numbers
 * on RISC-V.
 * */

#include<stdio.h>
#include<uart.h>

unsigned long read_cycles(void) {
    unsigned long cycles;
    asm volatile ("rdcycle %0" : "=r" (cycles));
    return cycles;
}

int main() {
    start = read_cycles();
    int i, n=100;
    int t1 = 0, t2 = 1;

    int nt = t1 + t2;

    printf("%d, %d, ", t1, t2);

    for(i = 3; i <=100; i++) {
        printf("%d, ", nt);
        t1 = t2;
        t2 = nt;
        nt = t1 + t2;
    }
    
    end = read_cycles();
    total = (double)(end - start);
    printf("Total time taken on computation: %lu\n", total);
    
    return 0;
}
