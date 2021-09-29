#include <stdio.h>
#include<stdlib.h>
#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC
//to perform insertion sort method
void recursive_Insertion_Sort(int arr[], int n){
   if (n <= 1)
      return;
   recursive_Insertion_Sort( arr, n-1 );//recursive apporach
   int nth = arr[n-1];
   int j = n-2;
   while (j >= 0 && arr[j] > nth){
      arr[j+1] = arr[j];
      j--;
   }
   arr[j+1] = nth;
}
int main(){
    double total_time;
    clock_t begin = clock();

  int x; //for store number of array from user`.
     printf("enter the size of array::");
     scanf("%d",&x);
     int randarray[x];
     for (int i = 0; i < x; i++)
         randarray[i] = rand() % 3000;
     printf("\nElements of the array::");
     for (int i = 0; i < x; i++)
         printf("\t%d",randarray[i]);
      recursive_Insertion_Sort(randarray, x);
   printf("\nSorted Array:\t");
   for (int i=0; i < x; i++)
      printf("%d ",randarray[i]);
       clock_t end = clock();

        // calculate excuted  time by finding difference (end - begin) and
        // dividing the difference by CLOCKS_PER_SEC to convert to seconds
        total_time = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\nThe program excuted  time is %f seconds", total_time);
   return 0;
}