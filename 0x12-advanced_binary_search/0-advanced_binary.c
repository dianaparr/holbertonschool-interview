#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of integers
 *
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: the index where value is located
 */
int advanced_binary(int *array, size_t size, int value)
{

	size_t i = 0, mid = 0, idx = 0;
	int tmp;

	if (!array)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i == size - 1)
			printf("\n");
		else
			printf(", ");
	}

	mid = (size - 1) / 2;
	if (array[mid] == value)
	{
		if (size == 1 || array[mid - 1] < value)
			return (mid);
	}
	else if (size == 1)
	{
		return (-1);
	}
	if (array[mid] < value)
	{
		idx += mid + 1, array += mid + 1;
		if (size % 2 != 0)
			mid--;
	}
	mid++;
	tmp = advanced_binary(array, mid, value);
	if (tmp != -1)
		return (tmp + idx);
	return (-1);

}
