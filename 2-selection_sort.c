#include "sort.h"

/**
 * selection_sort - function that sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: Elements to be ordered
 * @size: Size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, k = 0;
	int n, p;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		n = array[i];
		p = 0;
		for (j = i; j < size; j++)
		{
			if (array[j] < n)
			{
				n = array[j];
				k = j;
				p++;
			}
		}
		array[k] = array[i];
		array[i] = n;
		if (p != 0)
			print_array(array, size);
	}
}
