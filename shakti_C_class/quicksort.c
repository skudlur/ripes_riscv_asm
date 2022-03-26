/* This program explores quicksort algo on a RISCV core.
 * */

#include<stdio.h>
#include<uart.h>

void quicksort(int numarr[20], int first, int last) {
    int i, j, p, t;

    if (first<last) {
        p = first;
        i = first;
        j = last;

        while(i<j) {
            while(numarr[i]<=numarr[p]&&i<last)
                i++;
            while(numarr[j]>numarr[p])
                j--;
            if(i<j) {
                t = numarr[i];
                numarr[i] = numarr[j];
                numarr[j] = t;
            }
        }

        t = numarr[p];
        numarr[p] = numarr[j];
        numarr[j] = t;
        quicksort(numarr,first,j-1);
        quicksort(numarr,j+1,last);
    }
}

unsigned long read_cycles(void) {
    unsigned long cycles;
    asm volatile ("rdcycle %0" : "=r" (cycles));
    return cycles;
}

int main() {
    unsigned long start, end, total;
    start = read_cycles();
    int i;
    int count = 0;

    int numarr[20] = {54,23,12,65,21,4,13,12,77,65,98,78,56,23,32,49,11,2,0,21};

    quicksort(numarr,0,19);
    
    end = read_cycles();
    total = (double)(end - start);
    printf("Total time taken on computation: %lu\n", total);
    
    for(i=0;i<count;i++)
        printf(" %d", numarr[i]);
}
