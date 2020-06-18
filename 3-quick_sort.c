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

	left_limit = 0;
	right_limit = (int)(size - 1);
	quickSort(array, left_limit, right_limit, size);
}

/**
 * quickSort - Recursive funtion to sort arrays
 *
 * @arr: Elements to be ordered
 * @low: Left limit sort
 * @high: Right limit sort
 * @size: Size of array, used to print an array
 */
void quickSort(int *arr, int low, int high, size_t size)
{
	print_array(arr, size);
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1, size);
		quickSort(arr, pi + 1, high, size);
	}
}

/**
 * partition - funtion that take arrat divide and sort it
 *
 * @arr: Elements to be ordered
 * @low: Lowest limit sort
 * @high: Highest limit sort
 * Return: Next position to check
 */
int partition(int *arr, int low, int high)
{
	int pivot;
	int i, j;

	pivot = arr[high];
	i = (low - 1);
	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/**
 * swap - swap two positions in an array
 *
 * @a: First element to swap
 * @b: Second element to swap
 */
void swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}
