/*
** long.c for corewar in /home/jeremy/Desktop/corewar/vm/src/instructions
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Mar 29 18:51:27 2017 Jérémy Sid Idris
** Last update Wed Mar 29 18:51:27 2017 Jérémy Sid Idris
*/

#include "process.h"
#include "memory.h"
#include "offset.h"
#include "register.h"
#include "corewar.h"
#include "instructions/long.h"

void			instruction_lld(void *raw1, void *raw2)
{
  t_context		*context;
  t_process_list	*process;
  int			value;

  context = (t_context *)raw1;
  process = (t_process_list *)raw2;
  if (process->current_operator_args_type[0] == T_DIR)
    value = process->current_operator_args[0];
  else
    value = get_in_memory(context, get_offset_at_new_addr(process,
				   process->current_operator_args[0]));
  process->carry = (value == 0 ? 1 : 0);
  set_in_register(process, process->current_operator_args[1], value);
}

void			instruction_lldi(void *raw1, void *raw2)
{
  t_context		*context;
  t_process_list	*process;
  int			sum;
  int			value;

  context = (t_context *)raw1;
  process = (t_process_list *)raw2;
  sum = 0;
  if (process->current_operator_args_type[0] == T_DIR)
    sum = process->current_operator_args[0];
  else if (process->current_operator_args_type[0] == T_REG)
    sum = get_in_register(process, process->current_operator_args[0]);
  else
    sum = get_index_in_memory(context, get_offset_at_new_addr(process,
				       process->current_operator_args[0]));
  if (process->current_operator_args_type[1] == T_DIR)
    sum = sum + process->current_operator_args[1];
  else if (process->current_operator_args_type[1] == T_REG)
    sum = sum + get_in_register(process, process->current_operator_args[1]);
  value = get_in_memory(context, get_offset_at_new_addr(process, sum));
  process->carry = (value == 0 ? 1 : 0);
  set_in_register(process, process->current_operator_args[2], value);
}

void			instruction_lfork(void *raw1, void *raw2)
{
  t_context		*context;
  t_process_list	*process;
  t_process_list	*new_process;

  context = (t_context *)raw1;
  process = (t_process_list *)raw2;
  new_process = make_process(context, process->id_champion,
	   process->name_champion,
	   get_offset_at_new_addr(process, process->current_operator_args[0]));
  copy_process_state(process, new_process);
}
