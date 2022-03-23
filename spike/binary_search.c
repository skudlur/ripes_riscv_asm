// Program to run a binary search on a 1-D array on Spike Sim

#include<stdio.h>

int BinarySearch(int arr[], int start_in, int end_in, int elem) {
   while (start_in <= end_in){
      int middle = start_in + (end_in- start_in )/2;
      if (arr[middle] == elem)
         return middle;
      if (arr[middle] < elem)
         start_in = middle + 1;
      else
         end_in = middle - 1;
   }
   return -1;
}

int main(void) {
   int arr[] = {
     1,7,4,2,3,4,5,3,1,100,2,3,213,23,56,3,1,434,3432,43,234,1,235,12,9569,54,334,958,6969,
     1234,23,2,23,4,565,3,43,12,4,6,8,888,65,45,4334,312,39893,32,56,65
   };
  
   int n = 50;
   int elem = 12;
   int found_in = BinarySearch(arr, 0, n-1, elem);
   if(found_in == -1 ) {
      printf("Element not found in the array ");
   }
   else {
      printf("Element found at index : %d",found_in);
   }
   return 0;
}
