#include "main.h"

/**
 * _strcmp - Compare two stings and return the difference of the first
 * difference in both strings
 * @s1: String 1
 * @s2: String 2
 * Return: Return the difference
 */

int _strcmp(const char *s1, const char *s2)
{
	int i = 0;

	while ((!(s1[i] == '\0' || s2[i] == '\0')) && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
