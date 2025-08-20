#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Seed and generate random numbers
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 10000;

    clock_t start = clock();

    // Bubble sort
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Print first 10 sorted elements
    printf("First 10 sorted elements: ");
    for (int i = 0; i < 10 && i < n; i++)
        printf("%d ", arr[i]);
    printf("\nExecution time: %.6f seconds\n", time_taken);

    free(arr);
    return 0;
}
