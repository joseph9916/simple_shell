#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * str_concat_three - Concantate string s1, s2 and s3
 * @s1: first string
 * @s2: second string
 * @s3: third string
 * Return: the pointer to the new string
 */
char *str_concat_three(const char *s1, const char *s2, const char *s3)
{
	int len1, len2, len3, i;
	char *str;

	if (s1 != NULL)
		len1 = _strlen(s1);
	if (s2 != NULL)
		len2 = _strlen(s2);
	if (s2 != NULL)
		len3 = _strlen(s3);
	if (len1 == 0 && len2 == 0)
	{
		if (!(len3))
		{
			str = malloc(sizeof(char));
			if (str == NULL)
				return (NULL);
			str[0] = '\0';
			return (str);
		}
	}
	str = malloc(sizeof(char) * (len1 + len2 + len3 + 1));
	if (str == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		str[i] = s1[i];
	for (i = 0; i < len2; i++)
		str[len1 + i] = s2[i];
	for (i = 0; i < len3; i++)
		str[len1 + len2 + i] = s3[i];
	str[len1 + len2 + len3] = '\0';
	return (str);

}
