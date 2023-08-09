#ifndef MAIN_H
#define MAIN_H

/**
 * struct list_s - linked list
 * @str: string
 * @next: next pointer
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

extern char **environ;

list_t *linked_paths(void);
list_t *add_node(list_t **head, char *str);
void shexecute_file(list_t *paths);
int check_file(char *file);
void free_list(list_t *head);
char **getargs(char *line);
void free_args(char **args);
int builtin(char **args);
int check_builtin(char *arg);
void execute_builtin(char **args, char *line, list_t *paths, int flag);
int _putchar(int c);
void shexecute(list_t *paths);
char **check_newlines(char **args);
void exit_free(char *line, list_t *paths, int exit_status);
list_t *add_node_end(list_t **head, char *str);
char *_getenv(char *variable);
void execute(char **args);
int _setenv(const char *variable, const char *value, int overwrite);
int _strcmp(const char *s1, const char *s2);
int _strlen(const char *s);
char *str_concat(char *s1, char *s2);
char *str_concat_three(const char *s1, const char *s2, const char *s3);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_which(char *file, list_t *paths);
char *_strdup(const char *str);
void printenv(void);
void welcome_user(const char *name);

#endif
