#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * _atoi - Converts string to number
 * @s: string
 * Return: Number
 */

int _atoi(const char *s)
{
	int i = 0, ans = 0;

	if (s[i] == '-')
		perror("/hsh");
	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
		{
			perror("/hsh");
			exit(EXIT_FAILURE);
		}
		ans = ((10 * ans) + (s[i] - '0'));
	}
	return (ans);
}

/**
 * change_dir - change directory
 * @args: arguements
 */

void change_dir(char **args)
{
	char *wd = malloc(128);
	char *dir;
	int ch;

	wd = getcwd(wd, 128);

	if (!(_strcmp(args[1], "-")))
	{
		dir = wd;
		ch = chdir(dir);
		if (ch == -1)
			perror("-bash: cd: kk: No such file or directory");
		write(1, &dir, _strlen(dir));
		_setenv("PWD", dir, 1);
	}
	else if (!(_strcmp(args[1], "$HOME")) || args[1] == NULL)
	{
		dir = wd;
		ch = chdir(dir);
		if (ch == -1)
			perror("-bash: cd: kk: No such file or directory");
		_setenv("PWD", dir, 1);
	}
	else
	{
		dir = str_concat_three(wd, "/", args[1]);
		ch = chdir(dir);
		if (ch == -1)
			perror("-bash: cd: kk: No such file or directory");
		_setenv("PWD", dir, 1);
	}
	free(wd);
	free(dir);
}
/**
 * execute_builtin - execute builtins
 * @args: arguements
 * @line: line
 * @paths: paths liked list
 * @flag: flag of builtin to execute
 */

void execute_builtin(char **args, char *line, list_t *paths, int flag)
{
	int exit_status = 0;

	if (flag == 1)
	{
		if (args[1])
			exit_status = _atoi(args[1]);
		if (args)
			free_args(args);
		if (line)
			free(line);
		if (paths)
			free_list(paths);
		exit(exit_status);
	}
	if (flag == 2)
	{
		printenv();
	}
	if (flag == 3)
		change_dir(args);
}

/**
 * check_builtin - check if arg is a builtin
 * @arg: arguement string to check
 * Return: flag integer
 */

int check_builtin(char *arg)
{
	int i = 0;
	char *builtins[] = {"exit", "env", "cd", NULL};

	while (builtins[i])
	{
		if (!(_strcmp((builtins[i]), arg)))
			return (i + 1);
		i++;
	}
	return (0);
}
