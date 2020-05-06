/*
** list.c for corewar in /home/jeremy/Desktop/corewar/vm/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 28 03:48:04 2017 Jérémy Sid Idris
** Last update Tue Mar 28 03:48:04 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/secure_malloc.h"
#include "helpers/string.h"
#include "corewar.h"
#include "helpers/list.h"

void			ordered_put_in_list(t_process_list **list,
				    t_process_list *element)
{
  t_process_list	*tmp;
  t_process_list	*last;

  tmp = *list;
  last = NULL;
  if (count_list(*list) == 0 ||
     (count_list(*list) == 1 && element->id_champion <= tmp->id_champion))
    return (put_at_begin_of_list(list, element));
  while (tmp != NULL)
    {
      if (element->id_champion < tmp->id_champion &&
	 (tmp->next == NULL || tmp->next->id_champion > element->id_champion))
	return (put_in_list(list, element, tmp, last));
      last = tmp;
      tmp = tmp->next;
    }
  last->next = element;
  element->next = tmp;
}

int			count_list(t_process_list *begin)
{
  t_process_list	*tmp;
  int			count;

  count = 0;
  tmp = begin;
  while (tmp != 0)
    {
      count = count + 1;
      tmp = tmp->next;
    }
  return (count);
}

int			id_occurence_in_list(int pattern,
					     t_process_list *begin)
{
  t_process_list	*tmp;
  int			occurence;

  tmp = begin;
  occurence = 0;
  while (tmp != 0)
    {
      if (pattern == tmp->id_champion)
	occurence = occurence + 1;
      tmp = tmp->next;
    }
  return (occurence);
}

int			list_is_unique(t_process_list *begin)
{
  t_process_list	*tmp;
  int			check_id;

  if (begin == NULL)
    return (1);
  tmp = begin;
  check_id = tmp->id_champion;
  while (tmp != 0)
    {
      if (tmp->id_champion != check_id)
	return (0);
      check_id = tmp->id_champion;
      tmp = tmp->next;
    }
  return (1);
}

void			remove_list_element(t_process_list **list,
					    t_process_list *element)
{
  t_process_list	*tmp;
  t_process_list	*before;

  tmp = *list;
  before = NULL;
  while (tmp != 0)
    {
      if (tmp == element)
	{
	  if (before == NULL)
	    *list = tmp->next;
	  else
	    before->next = tmp->next;
	  return ;
	}
      before = tmp;
      tmp = tmp->next;
    }
}
