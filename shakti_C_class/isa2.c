// This program is to test out the mini processor

#include<stdio.h>
#include<uart.h>
unsigned long read_cycles(void) {
  unsigned long cycles;
  asm volatile  ("rdcycle %0" : "=r" (cycles));
  return cycles;
}

int main() {
  unsigned long start,end, total;
  start = read_cycles();

  int *p1;
  p1 = (int *)0x00041000; //address to slave register 0
  *p1 = 0x2; //input a for slave register 0

  p1 = (int *)0x00041004; //address to slave register 1
  *p1 = 0x4; //input b for slave register 1

  p1 = (int *)0x00041008; //address to slave register 2
  *p1 = 0x5; //input a for slave register 2

  p1 = (int *)0x0004100c; //address to slave register 3

  end = read_cycles();
  printf("%x\n",*p2); //display the contents of the slave register 3 
  total = end-start;
  printf("Total time taken on computation: %lu\n", total); //measure cycle count
}
