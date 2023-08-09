#include "main.h"

/**
 * _strlen - Counts the value of characters
 * @s: The pointer of string
 * Return: i lentgth of String
 */

int _strlen(const char *s)
{
	int i = 0;
	/*while i doesn't point to a null character increase value of i*/
	while (s[i] != '\0')
		i++;
	return (i);
}
