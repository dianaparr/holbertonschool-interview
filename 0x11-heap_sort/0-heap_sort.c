#include "sort.h"

/**
 * heap_sort - is a efficient sorting algorithm
 *
 * @arr: array of int to sort
 * @size: size of array of int
 *
 * Return: void
 */

void heap_sort(int *arr, size_t size)
{
	size_t last;
	int store;

	if (size <= 1)
		return;
	heapify(arr, size);
	last = size - 1;
	while (last > 0)
	{
		store = arr[0];
		arr[0] = arr[last];
		arr[last] = store;
		print_array(arr, size);
		last -= 1;
		sift_down(arr, 0, last, size);
	}
}

/**
 * heapify - heaps an integer array
 *
 * @arr: array to heapify
 * @size: size of the array
 *
 * Return: void
 */

void heapify(int *arr, size_t size)
{
	size_t start;

	if ((size - 1) % 2 == 0)
		start = (size - 3) / 2;
	else
		start = (size - 2) / 2;
	while (start + 1 >= 1)
	{
		sift_down(arr, start, size - 1, size);
		start -= 1;
	}
}

/**
 * sift_down - sift down
 *
 * @arr: heap array to sift
 * @start: start
 * @end: end
 * @size: array size
 *
 * Return: void
 */

void sift_down(int *arr, size_t start, size_t end, size_t size)
{
	size_t root = start, child, swap;
	int temp;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;
		swap = root;
		if (arr[swap] < arr[child])
			swap = child;
		if (child + 1 <= end && arr[swap] < arr[child + 1])
			swap = child + 1;
		if (swap == root)
			return;
		temp = arr[root];
		arr[root] = arr[swap];
		arr[swap] = temp;
		print_array(arr, size);
		root = swap;
	}
}
