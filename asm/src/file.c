/*
** file.c for corewar in /home/jeremy/Desktop/corewar/asm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 02:42:08 2017 Jérémy Sid Idris
** Last update Sat Mar 25 02:42:08 2017 Jérémy Sid Idris
*/

#include <stdbool.h>
#include <stdlib.h>
#include "helpers/secure_malloc.h"
#include "assembler.h"
#include "file.h"

t_file		*make_file(char *name)
{
  t_file	*file;

  file = secure_malloc(sizeof(t_file));
  file->name = name;
  file->line = 0;
  file->offset = 0;
  file->header_has_name = false;
  file->passed_header = 0;
  file->label_usage_list = NULL;
  file->label_def_list = NULL;
  make_header(file);
  return (file);
}

void	make_header(t_file *file)
{
  int	i;

  i = 0;
  file->header = secure_malloc(sizeof(t_header));
  file->header->magic = FILE_MAGIC;
  while (i <= PROG_NAME_LENGTH)
    {
      file->header->prog_name[i] = 0;
      i = i + 1;
    }
  i = 0;
  while (i <= COMMENT_LENGTH)
    {
      file->header->comment[i] = 0;
      i = i + 1;
    }
}
