#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sorted sub-arrays into a single sorted array
 * @array: The original array containing the sub-arrays
 * @left: The left sub-array
 * @right: The right sub-array
 * @start: Starting index of the left sub-array in the original array
 * @mid: Ending index of the left sub-array and starting index
 * of the right sub-array
 * @end: Ending index of the right sub-array in the original array
 */
void merge(int *array, int *left, int *right, size_t start,
		   size_t mid, size_t end)
{
	size_t i = 0, j = 0, k = start;
	size_t nL = mid - start;
	size_t nR = end - mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, nL);
	printf("[right]: ");
	print_array(right, nR);

	while (i < nL && j < nR)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}
	while (i < nL)
		array[k++] = left[i++];
	while (j < nR)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array + start, end - start);
}

/**
 * top_down_split_merge - Recursively splits the array and merges
 * the sorted sub-arrays
 * @array: The original array
 * @temp: Temporary array used for merging
 * @start: Starting index of the sub-array to be split
 * @end: Ending index of the sub-array to be split
 */
void top_down_split_merge(int *array, int *temp, size_t start, size_t end)
{
	if (end - start <= 1)
		return;

	size_t mid = start + (end - start) / 2;

	top_down_split_merge(array, temp, start, mid);
	top_down_split_merge(array, temp, mid, end);

	for (size_t i = start; i < end; i++)
		temp[i] = array[i];

	merge(array, temp + start, temp + mid, start, mid, end);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * the Merge Sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	int *temp = malloc(size * sizeof(int));

	if (temp == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return;
	}

	top_down_split_merge(array, temp, 0, size);
	free(temp);
}
