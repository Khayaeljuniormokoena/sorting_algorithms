#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size) {
    if (array == NULL || size < 2) {
        return;
    }

    size_t gap, i, j;

    for (gap = 1; gap < size / 3; gap = gap * 3 + 1);

    for (; gap > 0; gap /= 3) {
        for (i = gap; i < size; i++) {
            int temp = array[i];

            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
        print_array(array, size);
    }
}
