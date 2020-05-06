/*
** header.c for corewar in /home/jeremy/Desktop/corewar/asm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 16:21:40 2017 Jérémy Sid Idris
** Last update Sat Mar 25 16:21:40 2017 Jérémy Sid Idris
*/

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "helpers/output.h"
#include "helpers/array.h"
#include "helpers/string.h"
#include "helpers/endianness.h"
#include "assembler.h"
#include "header.h"

int	is_header_line(char *token)
{
  if (my_strcmp(token, NAME_CMD_STRING) == 0)
    return (HEADER_TYPE_NAME);
  else if (my_strcmp(token, COMMENT_CMD_STRING) == 0)
    return (HEADER_TYPE_COMMENT);
  else
    return (-1);
}

void	validate_header(t_file *file, int type, char *line)
{
  char	**tokens;
  char	*data;
  char	*epured_instruction;

  tokens = my_str_to_wordtab(line, '"');
  epured_instruction = epur_str(tokens[0]);
  if (array_size(tokens) != 3 || len(epur_str(tokens[2])) != 0 ||
      is_header_line(epured_instruction) != type)
    exit(put_parsing_error(file, "Header syntax error"));
  data = tokens[1];
  check_header(file, type, data);
  file->passed_header = (type == HEADER_TYPE_NAME ? 1 : -1);
  file->header_has_name = (type == HEADER_TYPE_NAME ? true :
			   file->header_has_name);
  if (type == HEADER_TYPE_NAME)
    my_strcpy(file->header->prog_name, data);
  else
    my_strcpy(file->header->comment, data);
  free_str_to_wordtab(tokens);
  free(epured_instruction);
}

void	check_header(t_file *file, int type, char *data)
{
  if (type == HEADER_TYPE_NAME && len(data) > PROG_NAME_LENGTH)
    exit(put_parsing_error(file, "Program name (header) is too long"));
  if (type == HEADER_TYPE_COMMENT && len(data) > COMMENT_LENGTH)
    exit(put_parsing_error(file, "Comment (header) is too long"));
  if (file->passed_header == -1)
    exit(put_parsing_error(file, "Header must be declared at begin of file"));
  if (type == HEADER_TYPE_NAME && file->passed_header != 0)
    exit(put_parsing_error(file, "Name must be specified before comment"));
  if (type == HEADER_TYPE_COMMENT && file->passed_header != 1)
    exit(put_parsing_error(file, "Comment must be specified after prog name"));
}

void	write_header(int output_fd, t_file *file)
{
  file->header->magic = swap_endianness(file->header->magic);
  file->header->prog_size = swap_endianness(file->header->prog_size);
  if (write(output_fd, file->header, sizeof(t_header)) != sizeof(t_header))
    exit(print_error(1, "Error for writing header to bytecode file"));
}
