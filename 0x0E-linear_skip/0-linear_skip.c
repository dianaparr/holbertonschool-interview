#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 *
 * @list:  pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: A pointer on the first node where value is located
 **/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *this = list, *searchValue = list;

	if (!list)
		return (NULL);

	while (searchValue && searchValue->express != NULL && searchValue->n < value)
	{
		this = searchValue;
		searchValue = this->express;
		printf("Value checked at index [%lu] = [%d]\n",
searchValue->index, searchValue->n);
	}

if (!(searchValue->express) && !(searchValue->n > value))
{
	this = searchValue;
	while (searchValue->next)
		searchValue = searchValue->next;
}

	printf("Value found between indexes [%lu] and [%lu]\n",
		   this->index, searchValue->index);

	while (this && this->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n", this->index, this->n);
		this = this->next;
	}

	if (this)
		printf("Value checked at index [%lu] = [%d]\n", this->index, this->n);

return (this && this->n == value ? this : NULL);
}
