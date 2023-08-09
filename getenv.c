#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _getenv - gets environment variables string if it exists
 * @variable: environment variable
 * Return: environment value
 */

char *_getenv(char *variable)
{
	int i = 0;
	char *var, delim[] = "=";

	while (environ[i])
	{
		var = strtok(environ[i], delim);
		if (!(_strcmp(variable, var)))
			return (strtok(NULL, delim));
		i++;
	}
	return (NULL);
}

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @variable: environment variable
 * @value: environment value
 * @overwrite: 0 or non zero
 * Return: -1 or 0
 */

int _setenv(const char *variable, const char *value, int overwrite)
{
	int i = 0;
	char *env_cpy, *var, delim[] = "=";

	env_cpy = str_concat_three(variable, delim, value);
	if (env_cpy)
		return (-1);
	while (environ[i])
	{
		var = strtok(environ[i], delim);
		if (!(_strcmp(variable, var)))
		{
			if (overwrite)
				environ[i] = env_cpy;
			return (0);
		}
		i++;
	}
	if (!(environ[i]))
	{
		environ[i] = env_cpy;
		i++;
		environ[i] = NULL;
		return (0);
	}
	return (0);
}
/**
 * _unsetenv - Remove an environment variable
 * @name: environment variable
 * Return: 0 or -1
 */

int _unsetenv(const char *name)
{
	int i = 0;
	char delim[] = "=";

	while (environ[i])
	{
		if (!(_strcmp(strtok(environ[i], delim), name)))
		{
			while (environ[i])
			{
				environ[i] = environ[i + 1];
				i++;
			}
		}
		i++;
	}
	return (0);
}
