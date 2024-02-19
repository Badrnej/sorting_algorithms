#include "sort.h"
#include <stdio.h>

void print(int *arr, int r1, int r2) {
    int i;
    for (i = r1; i <= r2; i++) {
        if (i > r1) printf(", ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

void swap(int *arr, int i, int j, int dir) {
    int tmp;
    if (dir == (arr[i] > arr[j])) {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

void bitonic_merge(int *arr, int low, int size, int dir, const int r_size) {
    int k = size, i = low;
    if (size > 1) {
        k = size / 2;
        for (i = low; i < low + k; i++)
            swap(arr, i, i + k, dir);
        bitonic_merge(arr, low, k, dir, r_size);
        bitonic_merge(arr, low + k, k, dir, r_size);
    }
}

void sort(int *arr, int low, int size, int dir, const int r_size) {
    int k = size;
    if (size > 1) {
        if (dir == 1) printf("Merging [%d/%d] (UP):\n", size, r_size);
        if (dir == 0) printf("Merging [%d/%d] (DOWN):\n", size, r_size);
        print(arr, low, low + k - 1);
        k = size / 2;
        sort(arr, low, k, 1, r_size);
        sort(arr, low + k, k, 0, r_size);
        bitonic_merge(arr, low, size, dir, r_size);
        if (dir == 1) {
            printf("Result [%d/%d] (UP):\n", size, r_size);
            print(arr, low, low + 2 * k - 1);
        }
        if (dir == 0) {
            printf("Result [%d/%d] (DOWN):\n", size, r_size);
            print(arr, low, low + 2 * k - 1);
        }
    }
}

void bitonic_sort(int *arr, size_t size) {
    int up = 1;
    const int r_size = (int)size;
    if (size < 2 || !arr) return;
    sort(arr, 0, (int)size, up, r_size);
}

