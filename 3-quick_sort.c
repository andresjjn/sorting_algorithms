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
        quick_sort_rec(array, left_limit, right_limit, size);
}

/**
 * quick_sort_rec - Recursive funtion to sort array
 * 
 * @array: Elements to be ordered
 * @left_limit: Left limit sort
 * @right_limit: Right limit sort
 */
void quick_sort_rec(int *array, int left_limit, int right_limit, size_t size)
{
        int left, right, tmp, pivot;

        left = left_limit;
        right = right_limit;
        pivot = array[(left + right) / 2];
        do{
                while(array[left] < pivot && left < right_limit)
                        left++;
                while(pivot < array[right] && right > left_limit)
                        right--;
                if (left <= right)
                {
                        tmp = array[left];
                        array[left] = array[right];
                        array[right] = tmp;
                        left++;
                        right--;
                }
        }while(left <= right);
        print_array(array, size);
        if (left_limit < right)
                quick_sort_rec(array, left_limit, right, size);
        if (right_limit > left)
                quick_sort_rec(array, left, right_limit, size);
}
