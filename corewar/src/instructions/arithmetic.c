/*
** arithmetic.c for corewar in /home/jeremy/Desktop/corewar/vm/src/instructions
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Mar 29 18:38:26 2017 Jérémy Sid Idris
** Last update Wed Mar 29 18:38:26 2017 Jérémy Sid Idris
*/

#include "helpers/endianness.h"
#include "register.h"
#include "memory.h"
#include "offset.h"
#include "corewar.h"
#include "instructions/arithmetic.h"

void			instruction_add(void *raw1, void *raw2)
{
  t_process_list	*process;
  int			value;

  (void)(raw1);
  process = (t_process_list *)raw2;
  value =
    get_in_register(process, process->current_operator_args[0]) +
    get_in_register(process, process->current_operator_args[1]);
  process->carry = (value == 0 ? 1 : 0);
  set_in_register(process, process->current_operator_args[2], value);
}

void			instruction_sub(void *raw1, void *raw2)
{
  t_process_list	*process;
  int			value;

  (void)(raw1);
  process = (t_process_list *)raw2;
  value =
    get_in_register(process, process->current_operator_args[0]) -
    get_in_register(process, process->current_operator_args[1]);
  process->carry = (value == 0 ? 1 : 0);
  set_in_register(process, process->current_operator_args[2], value);
}

void			instruction_and(void *raw1, void *raw2)
{
  t_context		*context;
  t_process_list	*process;
  int			number1;
  int			number2;
  int			value;

  context = (t_context *)raw1;
  process = (t_process_list *)raw2;
  if (process->current_operator_args_type[0] == T_DIR)
    number1 = process->current_operator_args[0];
  else if (process->current_operator_args_type[0] == T_REG)
    number1 = get_in_register(process, process->current_operator_args[0]);
  else
    number1 = get_in_memory(context, get_offset_at_new_addr(process,
			    process->current_operator_args[0] % IDX_MOD));
  if (process->current_operator_args_type[1] == T_DIR)
    number2 = process->current_operator_args[1];
  else if (process->current_operator_args_type[1] == T_REG)
    number2 = get_in_register(process, process->current_operator_args[1]);
  else
    number2 = get_in_memory(context, get_offset_at_new_addr(process,
			    process->current_operator_args[1] % IDX_MOD));
  value = number1 & number2;
  process->carry = (value == 0 ? 1 : 0);
  set_in_register(process, process->current_operator_args[2], value);
}

void			instruction_or(void *raw1, void *raw2)
{
  t_context		*context;
  t_process_list	*process;
  int			number1;
  int			number2;
  int			value;

  context = (t_context *)raw1;
  process = (t_process_list *)raw2;
  if (process->current_operator_args_type[0] == T_DIR)
    number1 = process->current_operator_args[0];
  else if (process->current_operator_args_type[0] == T_REG)
    number1 = get_in_register(process, process->current_operator_args[0]);
  else
    number1 = get_in_memory(context, get_offset_at_new_addr(process,
			    process->current_operator_args[0] % IDX_MOD));
  if (process->current_operator_args_type[1] == T_DIR)
    number2 = process->current_operator_args[1];
  else if (process->current_operator_args_type[1] == T_REG)
    number2 = get_in_register(process, process->current_operator_args[1]);
  else
    number2 = get_in_memory(context, get_offset_at_new_addr(process,
			    process->current_operator_args[1] % IDX_MOD));
  value = number1 | number2;
  process->carry = (value == 0 ? 1 : 0);
  set_in_register(process, process->current_operator_args[2], value);
}

void			instruction_xor(void *raw1, void *raw2)
{
  t_context		*context;
  t_process_list	*process;
  int			number1;
  int			number2;
  int			value;

  context = (t_context *)raw1;
  process = (t_process_list *)raw2;
  if (process->current_operator_args_type[0] == T_DIR)
    number1 = process->current_operator_args[0];
  else if (process->current_operator_args_type[0] == T_REG)
    number1 = get_in_register(process, process->current_operator_args[0]);
  else
    number1 = get_in_memory(context, get_offset_at_new_addr(process,
			    process->current_operator_args[0] % IDX_MOD));
  if (process->current_operator_args_type[1] == T_DIR)
    number2 = process->current_operator_args[1];
  else if (process->current_operator_args_type[1] == T_REG)
    number2 = get_in_register(process, process->current_operator_args[1]);
  else
    number2 = get_in_memory(context, get_offset_at_new_addr(process,
			    process->current_operator_args[1] % IDX_MOD));
  value = number1 ^ number2;
  process->carry = (value == 0 ? 1 : 0);
  set_in_register(process, process->current_operator_args[2], value);
}
