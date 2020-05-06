/*
** manage.c for corewar in /home/jeremy/Desktop/corewar/vm/src/instructions
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Mar 29 18:46:36 2017 Jérémy Sid Idris
** Last update Wed Mar 29 18:46:36 2017 Jérémy Sid Idris
*/

#include "helpers/endianness.h"
#include "offset.h"
#include "memory.h"
#include "register.h"
#include "corewar.h"
#include "instructions/manage.h"

void			instruction_ld(void *raw1, void *raw2)
{
  t_context		*context;
  t_process_list	*process;
  int			value;
  int			index;

  context = (t_context *)raw1;
  process = (t_process_list *)raw2;
  if (process->current_operator_args_type[0] == T_DIR)
    value = process->current_operator_args[0];
  else
    {
      index = process->current_operator_args[0] % IDX_MOD;
      value = get_in_memory(context, get_offset_at_new_addr(process, index));
    }
  process->carry = (value == 0 ? 1 : 0);
  set_in_register(process, process->current_operator_args[1], value);
}

void			instruction_st(void *raw1, void *raw2)
{
  t_context		*context;
  t_process_list	*process;
  int			value;
  int			index;

  context = (t_context *)raw1;
  process = (t_process_list *)raw2;
  value = get_in_register(process, process->current_operator_args[0]);
  if (process->current_operator_args_type[1] == T_REG)
    set_in_register(process, process->current_operator_args[1], value);
  else
    {
      index = process->current_operator_args[1] % IDX_MOD;
      set_in_memory(context, get_offset_at_new_addr(process, index), value);
    }
}

void			instruction_ldi(void *raw1, void *raw2)
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
		              process->current_operator_args[0] % IDX_MOD));
  if (process->current_operator_args_type[1] == T_DIR)
    sum = sum + process->current_operator_args[1];
  else if (process->current_operator_args_type[1] == T_REG)
    sum = sum + get_in_register(process, process->current_operator_args[1]);
  value = get_in_memory(context,
			get_offset_at_new_addr(process, sum % IDX_MOD));
  process->carry = (value == 0 ? 1 : 0);
  set_in_register(process, process->current_operator_args[2], value);
}

void			instruction_sti(void *raw1, void *raw2)
{
  t_context		*context;
  t_process_list	*process;
  int			value;
  int			sum;
  int			index;

  context = (t_context *)raw1;
  process = (t_process_list *)raw2;
  sum = 0;
  value = get_in_register(process, process->current_operator_args[0]);
  if (process->current_operator_args_type[1] == T_DIR)
    sum = process->current_operator_args[1];
  else if (process->current_operator_args_type[1] == T_REG)
    sum = get_in_register(process, process->current_operator_args[1]);
  else
    sum = get_index_in_memory(context, get_offset_at_new_addr(process,
			      process->current_operator_args[1] % IDX_MOD));
  if (process->current_operator_args_type[2] == T_DIR)
    sum = sum + process->current_operator_args[2];
  else if (process->current_operator_args_type[2] == T_REG)
    sum = sum + get_in_register(process, process->current_operator_args[2]);
  index = sum % IDX_MOD;
  set_in_memory(context, get_offset_at_new_addr(process, index), value);
}
