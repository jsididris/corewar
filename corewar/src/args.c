/*
** args.c for corewar in /home/jeremy/Desktop/corewar/vm
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Mar 29 06:39:58 2017 Jérémy Sid Idris
** Last update Wed Mar 29 06:39:58 2017 Jérémy Sid Idris
*/

#include "validation.h"
#include "memory.h"
#include "corewar.h"
#include "args.h"

int	check_args(t_context *context, t_process_list *process,
		   t_operator operator)
{
  int	i;

  if (!operator.has_coding_byte)
    return (check_unique_arg(context, process, operator));
  i = 0;
  if (!handle_args(context, process, operator, &i))
    return (0);
  if ((process->current_operator_args_amount = i) != operator.nb_args)
    return (0);
  return (1);
}

int		handle_args(t_context *context, t_process_list *process,
			    t_operator operator, int *i)
{
  int		bit_1;
  int		bit_2;
  unsigned char	coding_byte;

  coding_byte = memory_read(context, process, 1);
  while (*i < 4)
    {
      bit_1 = ((coding_byte >> (7 - (*i * 2))) & 1);
      bit_2 = ((coding_byte >> (6 - (*i * 2))) & 1);
      if (bit_1 && bit_2)
	handle_indirect_arg(context, process, *i);
      else if (bit_1 && !bit_2)
	handle_direct_arg(context, process, *i, operator);
      else if (!bit_1 && bit_2)
	{
	  handle_register_arg(context, process, *i);
	  if (!validate_register(process->current_operator_args[*i]))
	    return (0);
	}
      else
	break ;
      if ((*i = *i + 1) > operator.nb_args)
	return (0);
    }
  return (1);
}

int	check_unique_arg(t_context *context, t_process_list *process,
			 t_operator operator)
{
  if (operator.is_index)
    process->current_operator_args[0] = memory_read(context, process, 2);
  else
    process->current_operator_args[0] = memory_read(context, process, 4);
  process->current_operator_args_type[0] = T_DIR;
  process->current_operator_args_amount = 1;
  return (1);
}
