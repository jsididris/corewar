/*
** process.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 28 03:13:03 2017 Jérémy Sid Idris
** Last update Tue Mar 28 03:13:03 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/list.h"
#include "helpers/secure_malloc.h"
#include "register.h"
#include "operator.h"
#include "corewar.h"
#include "process.h"

t_process_list		*find_process_by_id(t_context *context, int id)
{
  t_process_list	*tmp;

  tmp = context->process_list;
  while (tmp != NULL)
    {
      if (tmp->id_champion == id)
	return (tmp);
      tmp = tmp->next;
    }
  return (NULL);
}

t_process_list		*make_process(t_context *context, int id,
				      char *name, int addr)
{
  t_process_list	*new_process;

  new_process = secure_malloc(sizeof(t_process_list));
  new_process->id_champion = id;
  new_process->name_champion = name;
  new_process->current_offset = addr;
  new_process->before_offset = addr;
  new_process->carry = 0;
  new_process->cycle_last_live = context->cycle;
  empty_register(new_process);
  reset_process_task(new_process);
  set_in_register(new_process, 1, id);
  ordered_put_in_list(&context->process_list, new_process);
  return (new_process);
}

void	reset_process_task(t_process_list *process)
{
  process->current_operator = get_null_operator();
  process->current_cycle = 0;
  process->current_operator_args_amount = 0;
  process->current_operator_args[0] = 0;
  process->current_operator_args[1] = 0;
  process->current_operator_args[2] = 0;
  process->current_operator_args[3] = 0;
  process->current_operator_args_type[0] = 0;
  process->current_operator_args_type[1] = 0;
  process->current_operator_args_type[2] = 0;
  process->current_operator_args_type[3] = 0;
}

void	copy_process_state(t_process_list *src, t_process_list *target)
{
  copy_registers(src, target);
  target->carry = src->carry;
  target->cycle_last_live = src->cycle_last_live;
}

void	remove_process(t_context *context, t_process_list *process)
{
  reset_process_task(process);
  remove_list_element(&context->process_list, process);
  free(process);
}
