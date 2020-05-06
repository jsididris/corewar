/*
** instruction.c for corewar in /home/jeremy/Desktop/corewar/asm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 16:28:08 2017 Jérémy Sid Idris
** Last update Sat Mar 25 16:28:08 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/array.h"
#include "helpers/string.h"
#include "helpers/output.h"
#include "types/label.h"
#include "token.h"
#include "operator.h"
#include "args.h"
#include "instruction.h"

void		validate_instruction(t_file *file, char **tokens)
{
  char		**args;
  char		*args_str;
  char		*purged_args_str;
  char		**instruction;
  char		*label;
  t_operator	operator;

  if (get_token_type(tokens[0]) == TOKEN_TYPE_LABEL)
    {
      if (array_size(tokens) == 1)
	return (validate_label(file, LABEL_DECLARATION, tokens[0]));
      label = tokens[0];
      validate_label(file, LABEL_DECLARATION, label);
      instruction = &tokens[1];
    }
  else
    instruction = &tokens[0];
  if (array_size(instruction) <= 1)
    exit(put_parsing_error(file, "Missing parameters for instruction"));
  args_str = wordtab_to_str(&instruction[1], ' ');
  purged_args_str = purge_args_str(args_str);
  args = my_str_to_wordtab(purged_args_str, SEPARATOR_CHAR);
  operator = find_operator(instruction[0]);
  check_instruction(file, operator, args);
  free_instruction(purged_args_str, args_str, args);
}

void	check_instruction(t_file *file, t_operator operator, char **args)
{
  if (!is_operator(operator))
    exit(put_parsing_error(file, "Unknown operator"));
  validate_instruction_args(file, operator, args);
  file->offset = file->offset + (operator.has_coding_byte ? 2 : 1);
}

void		write_instruction(t_file *file, char **tokens, int fd)
{
  char		**args;
  char		*args_str;
  char		*purged_args_str;
  char		**instruction;
  t_operator	operator;

  if (get_token_type(tokens[0]) == TOKEN_TYPE_LABEL && array_size(tokens) != 1)
    instruction = &tokens[1];
  else
    instruction = &tokens[0];
  args_str = wordtab_to_str(&instruction[1], ' ');
  purged_args_str = purge_args_str(args_str);
  args = my_str_to_wordtab(purged_args_str, SEPARATOR_CHAR);
  operator = find_operator(instruction[0]);
  if (is_operator(operator))
    {
      write_operator(operator, fd);
      if (operator.has_coding_byte)
	write_args_coding_byte(operator, args, fd);
      write_instruction_args(file, operator, args, fd);
      file->offset = file->offset + (operator.has_coding_byte ? 2 : 1);
    }
  free_instruction(purged_args_str, args_str, args);
}

void	free_instruction(char *purged_args_str, char *args_str, char **args)
{
  free(purged_args_str);
  free(args_str);
  free_str_to_wordtab(args);
}
