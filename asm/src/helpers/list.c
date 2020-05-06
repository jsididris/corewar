/*
** list.c for corewar in /home/jeremy/Desktop/corewar/assembler/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Mar 22 17:01:01 2017 Jérémy Sid Idris
** Last update Wed Mar 22 17:01:01 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/secure_malloc.h"
#include "helpers/string.h"
#include "assembler.h"
#include "helpers/list.h"

void		put_in_list(t_labels_list **list, char *name, int line,
			    int offset)
{
  t_labels_list	*element;

  element = secure_malloc(sizeof(t_labels_list));
  element->name = name;
  element->line = line;
  element->offset = offset;
  element->next = *list;
  *list = element;
}

int		count_list(t_labels_list *begin)
{
  t_labels_list	*tmp;
  int		count;

  count = 0;
  tmp = begin;
  while (tmp != 0)
    {
      count = count + 1;
      tmp = tmp->next;
    }
  return (count);
}

int		name_occurence_in_list(char *pattern, t_labels_list *begin)
{
  t_labels_list	*tmp;
  int		occurence;

  tmp = begin;
  occurence = 0;
  while (tmp != 0)
    {
      if (my_strcmp(tmp->name, pattern) == 0)
	occurence = occurence + 1;
      tmp = tmp->next;
    }
  return (occurence);
}

void		purge_list(t_labels_list **list)
{
  t_labels_list	*tmp;
  t_labels_list	*tmp2;

  tmp = *list;
  tmp2 = NULL;
  while (tmp != NULL)
    {
      tmp2 = tmp;
      free(tmp->name);
      tmp = tmp->next;
      free(tmp2);
    }
  *list = NULL;
}
