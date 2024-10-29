#include "sort.h"

/**
  * selection_sort - Sorts an array using selection sort algorithm.
  * @array: Pointer to an array to be sorted.
  * @size: The size of an array
  *
  * Return: Void
  */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int temp;

	if (array == NULL || size == 0)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
		print_array(array, size);
	}
}
