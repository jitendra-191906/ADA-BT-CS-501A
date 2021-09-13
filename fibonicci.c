#include <stdio.h>
#include <time.h> // for clock_t, clock(), CLOCKS_PER_SEC

int main()
{

    // to store the execution time of code
    double total_time;
    clock_t begin = clock();
//START MAIN LOGIC OF FIBONACCI SERIES
    int n, i, a = -1, b = 1, c;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Fibonacci Series: ");
    if (n < 0)
    {
        printf("enter grater than 0");
    }
    else
    {
        for (i = 0; i <= n - 1; i++)
        {
            c = a + b;
            printf("\n%d", c);
            a = b;
            b = c;
        }
       clock_t end = clock();

        // calculate excuted  time by finding difference (end - begin) and
        // dividing the difference by CLOCKS_PER_SEC to convert to seconds
        total_time = (double)(end - begin) / CLOCKS_PER_SEC;
        printf("\nThe program excuted  time is %f seconds", total_time);
         return 0;
    }
}
