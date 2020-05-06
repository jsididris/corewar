/*
** args_type.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sun Apr  2 17:04:43 2017 Jérémy Sid Idris
** Last update Sun Apr  2 17:04:43 2017 Jérémy Sid Idris
*/

#include "memory.h"
#include "corewar.h"
#include "args.h"

void	handle_register_arg(t_context *context, t_process_list *process,
			    int i)
{
  process->current_operator_args[i] = memory_read(context, process, 1);
  process->current_operator_args_type[i] = T_REG;
}

void	handle_indirect_arg(t_context *context, t_process_list *process, int i)
{
  process->current_operator_args[i] = memory_read(context, process, 2);
  process->current_operator_args_type[i] = T_IND;
}

void	handle_direct_arg(t_context *context, t_process_list *process,
			  int i, t_operator operator)
{
  if (operator.is_index)
    process->current_operator_args[i] = memory_read(context, process, 2);
  else
    process->current_operator_args[i] = memory_read(context, process, 4);
  process->current_operator_args_type[i] = T_DIR;
}
