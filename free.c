#include "main.h"
#include <stdlib.h>

/**
 * free_args - free array args
 * @args: array to free
 */
void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
