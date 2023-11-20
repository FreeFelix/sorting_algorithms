#include "sort.h"

/**
 * quick_sort - Sorts an array using the quicksort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 *
 * Description:
 *   This function implements the quicksort algorithm to sort
 *   the given array in ascending order. It calls the recursive
 *   sorting function, `sort_alg`, to perform the sorting.
 *
 * @param array: The array of integers to be sorted.
 * @param size: The number of elements in the array.
 *
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	sort_alg(array, 0, size - 1, size);
}

/**
 * sort_alg - Recursive sorting algorithm for quicksort.
 * @arr: Array to be sorted.
 * @left: Leftmost index of the subarray.
 * @right: Rightmost index of the subarray.
 * @size: Full size of the array.
 *
 * Description:
 *   This function is a recursive sorting algorithm used
 *   by quick_sort. It selects a pivot, partitions the array,
 *   and recursively calls itself on the two resulting subarrays.
 *
 * Return: Void
 */
void sort_alg(int *arr, int left, int right, size_t size)
{
	int pivot;

	if (left < right)
	{
		pivot = split(arr, left, right, size);
		sort_alg(arr, left, pivot - 1, size);
		sort_alg(arr, pivot + 1, right, size);
	}
}

/**
 * split - Splits the array for quicksort partitioning.
 * @arr: Array to be split.
 * @left: Leftmost index of the subarray.
 * @right: Rightmost index of the subarray.
 * @size: Full size of the array.
 *
 * Description:
 *   This function selects a pivot, partitions the array
 *   into elements less than the pivot and elements greater
 *   than the pivot, and returns the index of the pivot.
 *
 * Return: Index of the pivot.
 */
int split(int *arr, int left, int right, size_t size)
{
	int i, i2, pivot, tmp;

	pivot = arr[right];
	i = left;

	for (i2 = left; i2 < right; i2++)
	{
		if (arr[i2] < pivot)
		{
			if (i != i2)
			{
				tmp = arr[i2];
				arr[i2] = arr[i];
				arr[i] = tmp;
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] != arr[right])
	{
		tmp = arr[i];
		arr[i] = arr[right];
		arr[right] = tmp;
		print_array(arr, size);
	}

	return (i);
}
