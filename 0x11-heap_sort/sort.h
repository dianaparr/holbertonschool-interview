#ifndef _SORT_H
#define _SORT_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

void print_array(const int *array, size_t size);
void sift_down(int *arr, size_t start, size_t end, size_t size);
void heapify(int *arr, size_t size);
void heap_sort(int *arr, size_t size);

#endif /* _SORT_H */
