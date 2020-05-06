/*
** args.c for corewar in /home/jeremy/Desktop/corewar/asm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Thu Mar 23 20:04:07 2017 Jérémy Sid Idris
** Last update Thu Mar 23 20:04:07 2017 Jérémy Sid Idris
*/

#include <unistd.h>
#include <stdlib.h>
#include "helpers/number.h"
#include "helpers/array.h"
#include "helpers/output.h"
#include "helpers/string.h"
#include "helpers/secure_malloc.h"
#include "types/register.h"
#include "types/direct.h"
#include "types/indirect.h"
#include "assembler.h"
#include "args.h"

char	get_arg_type(char *arg)
{
  if (arg[0] == REGISTER_CHAR && len(arg) > 1 && is_num(&arg[1]) == 2)
    return (T_REG);
  else if (arg[0] == DIRECT_CHAR && len(arg) > 1 &&
	   (arg[1] == LABEL_CHAR || is_num(&arg[1]) == 2))
    return (T_DIR);
  else if (arg[0] == LABEL_CHAR || is_num(&arg[0]) == 2)
    return (T_IND);
  return (0);
}

void	validate_instruction_args(t_file *file, t_operator operator,
				  char **args)
{
  int	i;
  char	type;

  if (array_size(args) != operator.nb_args)
    exit(put_parsing_error(file, (array_size(args) > operator.nb_args ?
	 "Too many instruction params" : "To few instruction params")));
  i = 0;
  while (i < operator.nb_args)
    {
      if ((type = get_arg_type(args[i])) == 0)
	exit(put_parsing_error(file, "Unable to find type of parameter"));
      if ((type & operator.type[i]) == 0)
	exit(put_parsing_error(file, "Bad type of arg for this instruction"));
      if (type == T_REG)
	validate_register_arg(file, args[i]);
      else if (type == T_DIR)
	validate_direct_arg(file, args[i], operator.is_index);
      else
	validate_indirect_arg(file, args[i]);
      i = i + 1;
    }
}

void	write_instruction_args(t_file *file, t_operator operator,
			       char **args, int fd)
{
  int	i;
  char	type;

  i = 0;
  while (i < operator.nb_args)
    {
      type = get_arg_type(args[i]);
      if (type == T_REG)
	write_register_arg(file, args[i], fd);
      else if (type == T_DIR)
	write_direct_arg(file, args[i], operator.is_index, fd);
      else
	write_indirect_arg(file, args[i], fd);
      i = i + 1;
    }
}

void    write_args_coding_byte(t_operator operator, char **args, int fd)
{
  char	coding_byte;
  int	i;
  char	type;

  coding_byte = 0;
  i = 0;
  while (i < operator.nb_args)
    {
      type = get_arg_type(args[i]);
      (coding_byte) |= ((type != T_REG) << (7 - (i * 2)));
      (coding_byte) |= ((type != T_DIR) << (7 - ((i * 2) + 1)));
      i = i + 1;
    }
  if (write(fd, &coding_byte, sizeof(char)) != sizeof(char))
    exit(print_error(1, "Error for writing coding byte to bytecode file"));
}

char	*purge_args_str(char *args_str)
{
  char	*purged_args_str;
  int	i;
  int	x;

  purged_args_str = secure_malloc(sizeof(char) * len(args_str) + 1);
  i = 0;
  x = 0;
  while (args_str[i] != 0)
    {
      if (args_str[i] == ' ')
	{
	  if ((args_str[i + 1] != 0 && args_str[i + 1] == SEPARATOR_CHAR) ||
	      (i > 0 && args_str[i - 1] == SEPARATOR_CHAR))
	    {
	      i = i + 1;
	      continue;
	    }
	}
      purged_args_str[x] = args_str[i];
      i = i + 1;
      x = x + 1;
    }
  purged_args_str[x] = '\0';
  return (purged_args_str);
}
