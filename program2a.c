#include <stdio.h>
#include<stdlib.h>
#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC

//TO PERFORM BUBBLE SORT SORTING METHOD
// Utility function to swap values 
void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to print `n` elements of array `arr`
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Function to perform bubble sort on a given array `arr[]`
void bubbleSort(int arr[], int n)//
{
    // `n-1` passes
    for (int k = 0; k < n - 1; k++)
    {
        // last `k` items are already sorted, so the inner loop can
        // avoid looking at the last `k` items
        for (int i = 0; i < n - 1 - k; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr, i, i + 1);
            }
        }

        // the algorithm can be terminated if the inner loop didn't do any swap
    }
}

int main(void)
{
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
         printf("\nThe sorted array is ");
  
    bubbleSort(randarray, x);
    printArray(randarray, x);
     clock_t end = clock();

        // calculate excuted  time by finding difference (end - begin) and
        // dividing the difference by CLOCKS_PER_SEC to convert to seconds
        total_time = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\nThe program excuted  time is %f seconds", total_time);

    return 0;
}
