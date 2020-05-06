/*
** analyzer.c for corewar in /home/jeremy/Desktop/corewar/asm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 18:39:19 2017 Jérémy Sid Idris
** Last update Sat Mar 25 18:39:19 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/output.h"
#include "helpers/array.h"
#include "helpers/string.h"
#include "utils/get_next_line.h"
#include "header.h"
#include "instruction.h"
#include "token.h"
#include "assembler.h"
#include "analyzer.h"

void	analyze_source(int source_fd, int output_fd, t_file *file)
{
  char		*buffer;
  char		*epured_line;
  char		**tokens;

  file->offset = 0;
  file->offset_instruction = 0;
  while ((buffer = get_next_line(source_fd)) != NULL)
    {
      if (len(buffer) == 0)
	continue;
      epured_line = epur_str(cut_str(buffer, COMMENT_CHAR));
      tokens = my_str_to_wordtab(epured_line, ' ');
      if (is_empty_tokens(tokens))
	continue;
      if (array_size(tokens) == 0 || tokens[0] == NULL)
	exit(put_parsing_error(file, "Null token found"));
      if (is_header_line(tokens[0]) == -1)
	write_instruction(file, tokens, output_fd);
      free(buffer);
      free(epured_line);
      free_str_to_wordtab(tokens);
      file->offset_instruction = file->offset;
    }
}
