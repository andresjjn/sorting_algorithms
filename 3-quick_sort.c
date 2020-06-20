#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers in ascending
 * order using the Quick sort algorithm
 *
 * @array: Elements to be ordered
 * @size: Size of array
 */
void quick_sort(int *array, size_t size)
{
	int left_limit, right_limit;

	if (!array || size < 2)
		return;
	left_limit = 0;
	right_limit = (int)(size - 1);
	quick_sort_rec(array, left_limit, right_limit, size);
}

/**
 * quick_sort_rec - Recursive funtion to sort array
 * @array: Elements to be ordered
 * @left_limit: Left limit sort
 * @right_limit: Right limit sort
 * @size: Array size
 */
void quick_sort_rec(int *array, int left_limit, int right_limit, size_t size)
{
	long int p = array[right_limit], i = left_limit - 1, j, t;

	if (left_limit < right_limit)
	{
		for (j = left_limit; j < right_limit; j++)
		{
			if (array[j] <= p)
			{
				i++;
				if (i != j)
				{
					t = array[i];
					array[i] = array[j];
					array[j] = t;
					print_array(array, size);
				}
			}
		}
		if (i + 1 != right_limit)
		{
			t = array[i + 1];
			array[i + 1] = array[right_limit];
			array[right_limit] = t;
			print_array(array, size);
		}
		quick_sort_rec(array, left_limit, i, size);
		quick_sort_rec(array, i + 2, right_limit, size);
	}
}
