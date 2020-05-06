/*
** list_2.c for corewar in /home/jeremy/Desktop/corewar/vm/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sun Apr  2 17:57:07 2017 Jérémy Sid Idris
** Last update Sun Apr  2 17:57:07 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "corewar.h"
#include "helpers/list.h"

void	put_at_begin_of_list(t_process_list **list, t_process_list *element)
{
  element->next = *list;
  *list = element;
}

void	put_in_list(t_process_list **list, t_process_list *element,
		    t_process_list *tmp, t_process_list *last)
{
  if (last == NULL)
    {
      element->next = *list;
      *list = element;
    }
  else
    {
      element->next = tmp;
      last->next = element;
    }
}
