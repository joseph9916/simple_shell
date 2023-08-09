#include "main.h"
#include <sys/stat.h>

/**
 * check_file - check if executable file and pathe exits
 * @file: executable to check
 * Return: 1 or 0
 */
int check_file(char *file)
{
	struct stat st;

	return (stat(file, &st));
}
