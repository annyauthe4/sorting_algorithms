#include "sort.h"

/**
  * swap - Swaps two elements in an array and prints the array.
  * @array: The array of integers.
  * @i: The index of the first element.
  * @j: The index of the second element.
  * @size: The size of the array.
  */
void swap(int *array, int i, int j, size_t size)
{
	int temp;

	if (i != j)
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}
}

/**
  * lomuto_partition - Partitions the array using the Lomuto scheme.
  * @array: The array of integers.
  * @low: The starting index of the partition.
  * @high: The ending index of the partition (pivot).
  * @size: The size of the array.
  *
  * Return: The index of the pivot after partitioning.
  */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j, size);
		}
	}
	swap(array, i + 1, high, size);
	return (i + 1);
}

/**
  * quick_sort_recursive - Recursively sorts the array using Quick Sort.
  * @array: The array of integers.
  * @low: The starting index of the partition.
  * @high: The ending index of the partition.
  * @size: The size of the array.
  */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index;

		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
  * quick_sort - Sorts an array of integers in ascending order
  * using Quick Sort.
  * @array: The array of integers.
  * @size: The size of the array.
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
