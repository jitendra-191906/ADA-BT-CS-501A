// Recursive Merge sort for sorting random integers.
#include <stdlib.h>
#include <stdio.h>
#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC

// Merge Function
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
// Functions to Print Elements of Array

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("n");
}
int main()
{
    double total_time;
    clock_t begin = clock();
    int x; //for store number of array from user`.
    printf("enter the size of array::");
    scanf("%d", &x);
    int randarray[x];
    for (int i = 0; i < x; i++)
        randarray[i] = rand() % 3000;
    printf("\nElements of the array::");
    for (int i = 0; i < x; i++)
        printf("\t%d", randarray[i]);
    mergeSort(randarray, 0, x - 1);//call merge function 
    printf("\nSorted array is \n");
    printArray(randarray, x);//call printAarray function
    clock_t end = clock();

    // calculate excuted  time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    total_time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nThe program excuted  time is %f seconds", total_time);

    return 0;
}