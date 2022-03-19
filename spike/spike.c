/*
 * This is a program to run a sequence of Fibonacci Numbers
 * on RISC-V Spike CLI simulator.
 * */

#include<stdio.h>

int main() {
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
    return 0;
}
