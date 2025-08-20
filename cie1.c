#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    srand(time(NULL)); // Seed for random numbers

    // Generate random array
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;

    double start = omp_get_wtime();

    // Bubble sort
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }

    double end = omp_get_wtime();

    printf("First 10 sorted elements: ");
    for (int i = 0; i < 10 && i < n; i++) // print only first 10
        printf("%d ", arr[i]);

    printf("\nExecution time: %.6f seconds\n", end - start);

    free(arr);
    return 0;
}
