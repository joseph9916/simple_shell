#include "main.h"
#include <stdlib.h>

/**
 * exit_free - frees and exits
 * @line: line pointer
 * @paths: paths linked_lists
 * @exit_status: exit status
 */

void exit_free(char *line, list_t *paths, int exit_status)
{
	if (line)
		free(line);
	if (paths)
		free_list(paths);
	exit(exit_status);
}
