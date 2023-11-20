#include "sort.h"

/**
 * selection_sort - Sorts an array using selection sort algorithm.
 * @array: Array to be sorted.
 * @size: Size of the array.
 *
 * Description:
 *   This function implements the selection sort algorithm to
 *   sort the given array in ascending order. It iterates through
 *   the array, finding the minimum element in the unsorted
 *   portion and swapping it with the first unsorted element.
 *   The process repeats until the entire array is sorted. The
 *   function prints the array after each swap.
 *
 * @param array: The array of integers to be sorted.
 * @param size: The number of elements in the array.
 *
 * Return: Void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, i2;
	int min, tmp, idx;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (i2 = i + 1; i2 < size; i2++)
		{
			if (min > array[i2])
			{
				min = array[i2];
				idx = i2;
			}
		}
		if (min != array[i])
		{
			tmp = array[i];
			array[i] = min;
			array[idx] = tmp;
			print_array(array, size);
		}
	}
}
