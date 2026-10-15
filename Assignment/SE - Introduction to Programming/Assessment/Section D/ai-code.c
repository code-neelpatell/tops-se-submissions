/*
Write a c program that:
- Accepts exactly 10 integers from the user using a loop and stores them in an array.
- Finds and displays the maximum value, minimum value, and arithmetic mean (displayed as a\
  float with 2 decimal places).
- Sorts the array in ascending order using any sorting method and displays the sorted list.
- Prints whether the mean is closer to the minimum, closer to the maximum, or exactly midway\
  between them.
*/

#include <stdio.h>

int main() {
    int arr[10];
    int i, j, temp;
    int max, min;
    int sum = 0;
    float mean;

    // 1. Accept exactly 10 integers
    printf("Enter 10 integers:\n");

    for (i = 0; i < 10; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // 2. Initialize minimum and maximum
    min = arr[0];
    max = arr[0];

    // 3. Find minimum, maximum, and sum
    for (i = 0; i < 10; i++) {
        sum += arr[i];

        if (arr[i] < min) {
            min = arr[i];
        }

        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // 4. Calculate arithmetic mean
    mean = sum / 10.0f;

    printf("\nMaximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    printf("Arithmetic mean: %.2f\n", mean);

    // 5. Sort the array in ascending order using bubble sort
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // 6. Display the sorted array
    printf("\nSorted array in ascending order:\n");

    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    // 7. Compare the mean's distance from minimum and maximum
    if (mean - min < max - mean) {
        printf("The mean is closer to the minimum.\n");
    }
    else if (mean - min > max - mean) {
        printf("The mean is closer to the maximum.\n");
    }
    else {
        printf("The mean is exactly midway between the minimum and maximum.\n");
    }

    return 0;
}

