#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * _strdup - Duplicates a string
 * @str: String to duplicate
 * Return: Initial address to duplicate or NULL if malloc fails
 */

char *_strdup(const char *str)
{
	int i, len = 0;
	char *dup;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * (len + 1));

	/*Check if malloc works*/
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';
	return (dup);
}
