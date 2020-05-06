/*
** cycle.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Mar 29 06:02:04 2017 Jérémy Sid Idris
** Last update Wed Mar 29 06:02:04 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "process.h"
#include "helpers/output.h"
#include "helpers/list.h"
#include "memory.h"
#include "operator.h"
#include "process.h"
#include "args.h"
#include "champion.h"
#include "corewar.h"
#include "cycle.h"

int	before_cycle(t_context *context)
{
  context->cycle = context->cycle + 1;
  if (list_is_unique(context->process_list))
    {
      if (context->process_list != NULL)
	{
	  my_putstr("The player ");
	  my_putnbr(context->process_list->id_champion, 1);
	  my_putstr(" (");
	  my_putstr(context->process_list->name_champion);
	  my_putstr(") has won.\n");
	}
      else
	my_putstr("No player has won ! Maybe the VM ?\n");
      return (1);
    }
  return (0);
}

void			perform_cycle(t_context *context)
{
  t_process_list	*tmp;
  t_process_list	*process;
  t_operator		operator;

  process = context->process_list;
  while (process != NULL)
    {
      tmp = process->next;
      if (!is_alive(context, process))
	remove_process(context, process);
      else if (!is_null_operator(process->current_operator))
	perform_instruction(context, process);
      else
	{
	  process->before_offset = process->current_offset;
	  operator = find_operator(memory_read(context, process, 1));
	  if (!is_null_operator(operator))
	    try_perform_instruction(context, process, operator);
	}
      process = tmp;
    }
}

void	try_perform_instruction(t_context *context, t_process_list *process,
				t_operator operator)
{
  process->current_operator = operator;
  if (check_args(context, process, operator))
    perform_instruction(context, process);
  else
    reset_process_task(process);
}

void	perform_instruction(t_context *context, t_process_list *process)
{
  process->current_cycle = process->current_cycle + 1;
  if (process->current_cycle == (process->current_operator).nb_cycles)
    {
      (process->current_operator).handle(context, process);
      reset_process_task(process);
    }
}
