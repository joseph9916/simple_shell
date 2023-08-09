#include "main.h"
#include <unistd.h>

/**
 * printenv - prints environment
 */

void printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		write(1, environ[i], _strlen(environ[i]));
		_putchar('\n');
		i++;
	}
}
