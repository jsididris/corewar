/*
** validator.c for corewar in /home/jeremy/Desktop/corewar/assembler/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 03:34:55 2017 Jérémy Sid Idris
** Last update Tue Mar 21 03:34:55 2017 Jérémy Sid Idris
*/

#include <stdbool.h>
#include <stdlib.h>
#include "types/label.h"
#include "helpers/secure_malloc.h"
#include "helpers/output.h"
#include "helpers/array.h"
#include "helpers/string.h"
#include "utils/get_next_line.h"
#include "header.h"
#include "instruction.h"
#include "token.h"
#include "file.h"
#include "assembler.h"
#include "validator.h"

t_file		*validate_source(int source_fd, char *file_name)
{
  t_file	*file;
  char		*buffer;
  char		*epured_line;
  char		**tokens;
  int		header_type;

  file = make_file(file_name);
  while ((buffer = get_next_line(source_fd)) != NULL)
    {
      file->line = file->line + 1;
      if (len(buffer) == 0)
	continue;
      epured_line = epur_str(cut_str(buffer, COMMENT_CHAR));
      tokens = my_str_to_wordtab(epured_line, ' ');
      if (is_empty_tokens(tokens))
	continue;
      if (array_size(tokens) == 0 || tokens[0] == NULL)
	exit(put_parsing_error(file, "Null token found"));
      if ((header_type = is_header_line(tokens[0])) != -1)
	validate_header(file, header_type, buffer);
      else
	initiate_validate_instruction(file, tokens);
      free_validator_readed_line(buffer, epured_line, tokens);
    }
  return (end_file_validation(file));
}

void	initiate_validate_instruction(t_file *file, char **tokens)
{
  validate_instruction(file, tokens);
  file->passed_header = -1;
}

t_file	*end_file_validation(t_file *file)
{
  if (file->header_has_name == false)
    exit(put_parsing_error(file, "Unknown name of program"));
  validate_label_usages(file);
  file->header->prog_size = file->offset;
  return (file);
}

void	free_validator_readed_line(char *buffer, char *epured_line,
				   char **tokens)
{
  free(buffer);
  free(epured_line);
  free_str_to_wordtab(tokens);
}
