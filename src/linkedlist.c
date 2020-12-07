#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"
#include <ctype.h>


struct node
{
	char data[200];
	struct node *next;
};

struct list
{
	Node *head;
};

Node *createnode(char *data);

Node *createnode(char *data)
{
	Node *newNode = malloc(sizeof(Node));
	if (!newNode)
	{
		return NULL;
	}
	strcpy(newNode->data, data);
	newNode->next = NULL;
	return newNode;
}

List *makelist()
{
	List *list = malloc(sizeof(List));
	if (!list)
	{
		return NULL;
	}
	list->head = NULL;
	return list;
}

void display(List *list)
{
	Node *current = list->head;
	if (list->head == NULL)
		return;
	int i = 1;
	for (; current != NULL; current = current->next)
	{
		printf("%d. %s\n", i, current->data);
		i++;
	}
}

void add(char *data, List *list)
{
	Node *current = NULL;
	if (list->head == NULL)
	{
		list->head = createnode(data);
	}
	else
	{
		current = list->head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = createnode(data);
	}
}

void delete (char *data, List *list)
{
	Node *current = list->head;
	Node *previous = current;
	while (current != NULL)
	{
		if (!strcmp(current->data, data))
		{
			previous->next = current->next;
			if (current == list->head)
				list->head = current->next;
			free(current);
			return;
		}
		previous = current;
		current = current->next;
	}
}

void reverse(List *list)
{
	Node *reversed = NULL;
	Node *current = list->head;
	Node *temp = NULL;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		temp->next = reversed;
		reversed = temp;
	}
	list->head = reversed;
}

void destroy(List *list)
{
	Node *current = list->head;
	Node *next = current;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(list);
}

char *brief(char *str)
{
	if (str == NULL)
	{
		return NULL;
	}
	else if (!strcmp(str, "HISTORY FULL"))
	{
		return str;
	}
	else if (!strcmp(str, "HISTORY BRIEF"))
	{
		return str;
	}
	int i = 0;

	while (str[i])
	{
		if (isspace(str[i]))
		{
			str[i] = 0;
			break;
		}
		
		i++;
	}
	return str;
}
//https://stackoverflow.com/questions/47116974/remove-a-substring-from-a-string-in-c#:~:text=1%20Answer&text=There%20is%20no%20predefined%20function,source%20and%20destination%20arrays%20overlap.
//Thanks @chqrlie
char *strremove(char *str, const char *sub)
{
	char *p, *q, *r;
	if ((q = r = strstr(str, sub)) != NULL)
	{
		size_t len = strlen(sub);
		while ((r = strstr(p = r + len, sub)) != NULL)
		{
			memmove(q, p, r - p);
			q += r - p;
		}
		memmove(q, p, strlen(p) + 1);
	}
	return str;
}

