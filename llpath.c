#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * linked_paths - puts the paths in the path environ in a linked list
 * Return: linked list of all paths strings
 */

list_t *linked_paths(void)
{
	char *paths = _getenv("PATH");
	char *token;
	char delim[] = " :\n";
	list_t *head = NULL;

	if (!paths)
		return (NULL);
	token = strtok(paths, delim);
	while (token)
	{
		add_node_end(&head, token);
		token = strtok(NULL, delim);
	}
	free(paths);
	return (head);
}
/**
 * add_node_end - add a node to the end of a linked list
 * @head: pointer to the head of the linked list
 * @str: str to copy to ths new head
 * Return: Address of new address
 */

list_t *add_node_end(list_t **head, char *str)
{
	list_t *new_node;
	list_t *cur_node = *head;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->str = _strdup(str);
	new_node->next = NULL;
	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}
	while (cur_node->next)
		cur_node = cur_node->next;
	cur_node->next = new_node;
	return (*head);
}

/**
 * free_list - free the memory allocation of linked list
 * @head: pointer to the linked list
 */

void free_list(list_t *head)
{
	list_t *curnode = head, *temp;

	if (head)
	{
		while (curnode != NULL)
		{
			temp = curnode;
			curnode = curnode->next;
			if (temp->str)
				free(temp->str);
			free(temp);
		}
		free(curnode);
	}
}
