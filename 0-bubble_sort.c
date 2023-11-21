#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using Bubble sort.
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Description:
 *   This function implements Bubble sort to sort the given array
 *   in ascending order. It iterates through the array, compares
 *   adjacent elements, and swaps if they're in the wrong order.
 *   The process repeats until the array is sorted. The function
 *   prints the array after each swap.
 *
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, size2 = size;
	int tmp, flag = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 1; j < size2; j++)
		{
			if (array[j - 1] > array[j])
			{
				flag = 1;
				tmp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = tmp;
				print_array(array, size);
			}
		}

		if (flag == 0)
			break;

		flag = 0;
		size2--;
	}
}
