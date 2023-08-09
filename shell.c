#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/**
 * execute - execute shell executables
 * @args: arguements to check
 */

void execute(char **args)
{
	int wstatus, i = 0;

	pid_t child_pid;

	child_pid = fork();
	if (child_pid < -1)
		perror("Error");
	else if (child_pid == 0)
		execve(args[i], args, NULL);
	else
		wait(&wstatus);
}

/**
 * getargs - breaks the line string to tokens
 * @line: input line
 * Return: token array
 */

char **getargs(char *line)
{
	char *token, delim[] = " \t\n";
	char **args = malloc(16 * sizeof(char *));
	int i = 0;

	token = strtok(line, delim);
	while (token)
	{
		args[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	args[i] = NULL;
	return (args);
}

/**
 * shexecute_file - executing process for file stdin
 * @paths: path
 */

void shexecute_file(list_t *paths)
{
	char **args, *line = NULL;
	int flag, i = 0;
	size_t n;
	ssize_t nread;

	nread = getline(&line, &n, stdin);
	while (nread > 0)
	{
		args = getargs(line);
		flag = check_builtin(args[0]);
		if (flag)
			execute_builtin(args, line, paths, flag);
		else
		{
			if (!(check_file(args[0])))
				execute(args);
			else
			{
				args[0] = _which(args[0], paths);
				if (!check_file(args[0]))
					execute(args);
				else
					perror("\\hsh");
			}
		}
		i++;
		free_args(args);
		nread = getline(&line, &n, stdin);
	}
	if (nread < 0)
		_putchar('\n');
	exit_free(line, paths, 0);
}

/**
 * shexecute - executing process
 * @paths: path
 */

void shexecute(list_t *paths)
{
	char **args, *line = NULL;
	int flag;
	size_t n;
	ssize_t nread;

	nread = getline(&line, &n, stdin);
	if (nread > 0)
	{
		args = getargs(line);
		flag = check_builtin(args[0]);
		if (flag)
			execute_builtin(args, line, paths, flag);
		else
		{
			if (!(check_file(args[0])))
				execute(args);
			else
			{
				args[0] = _which(args[0], paths);
				if (!check_file(args[0]))
					execute(args);
				else
					perror("\\hsh");
			}
		}
		free_args(args);
		free(line);
	}
	if (nread < 0)
	{
		_putchar('\n');
		exit_free(line, paths, 0);
	}
}

/**
 * main - main function a shell
 * Return: 0 or 1
 */

int main(void)
{
	list_t *paths = linked_paths();
	char *prompt = "cisfun#";

	if (isatty(0))
	{
		while (1)
		{
			write(1, prompt, strlen(prompt) + 1);
			shexecute(paths);
		}
	}
	else
		shexecute_file(paths);
	if (paths)
		free_list(paths);
	return (0);
}
