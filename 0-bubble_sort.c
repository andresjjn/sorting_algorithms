#include "sort.h"

/**
 * bubble_sort - Sort algorithm
 *
 * @array: Elements to be ordered
 * @size: Size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, s;
	int tmp;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		s = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				s = 1;
				print_array(array, size);
			}
		}
		if (s == 0)
			break;
	}
}
