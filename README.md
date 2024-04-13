# Bubble Sort Algorithm

## Overview

Bubble Sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted. It is named for the way smaller or larger elements "bubble" to the top of the list.

### Algorithm Steps:

1. Start from the first element (index 0) and compare it with the next element.
2. If the current element is greater than the next element, swap them.
3. Move to the next element and repeat step 2.
4. Continue this process until the end of the list.
5. Repeat the above steps for each element in the list, excluding the last sorted element.

## Example

Let's consider an unsorted list: `[5, 3, 8, 4, 2]`

### First Pass:
- Compare `5` and `3`. Since `5` > `3`, swap them.
- Compare `5` and `8`. No swap needed.
- Compare `8` and `4`. Swap them.
- Compare `8` and `2`. Swap them.
- List after the first pass: `[3, 5, 4, 2, 8]`

### Second Pass:
- Compare `3` and `5`. No swap needed.
- Compare `5` and `4`. Swap them.
- Compare `5` and `2`. Swap them.
- List after the second pass: `[3, 4, 2, 5, 8]`

### Third Pass:
- Compare `3` and `4`. No swap needed.
- Compare `4` and `2`. Swap them.
- List after the third pass: `[3, 2, 4, 5, 8]`

### Fourth Pass:
- Compare `3` and `2`. Swap them.
- List after the fourth pass: `[2, 3, 4, 5, 8]`

Now, the list is sorted!

## Implementation

The following C code demonstrates the Bubble Sort algorithm:

```c
#include <stdbool.h>
#include <stdio.h>

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
