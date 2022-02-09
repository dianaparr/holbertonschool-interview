#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given
 *                 unsigned integer is a palindrome
 * @n: number to be checked
 *
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long original_number, remainder, reversed_number = 0;

	original_number = n;

	while (n != 0)
	{
		remainder = n % 10;
		reversed_number = reversed_number * 10 + remainder;
		n /= 10;
	}

	if (original_number == reversed_number)
		return (1);
	else
		return (0);
}
