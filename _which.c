#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <stddef.h>
#include <stdlib.h>
#include "main.h"

/**
 * _which - searches path directory for an executable file
 * @file: file to search for
 * @paths: paths in PATH
 * Return: path of executable or NULL if doesn't exist
 */

char *_which(char *file, list_t *paths)
{
	DIR *D;
	char *file_path;
	list_t *curnode = paths;
	struct dirent *dir;

	if (!(file))
		return (NULL);
	while (curnode->str)
	{
		D = opendir(curnode->str);
		if (D)
		{
			while ((dir = readdir(D)))
			{
				if (!(_strcmp(dir->d_name, file)))
				{
					closedir(D);
					if (curnode->str)
					{
						file_path = str_concat_three(curnode->str, "/", file);
						free(file);
						file = file_path;
						return (file);
					}
				}
			}
		}
		closedir(D);
		curnode = curnode->next;
	}
	return (NULL);
}
