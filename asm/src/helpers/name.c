/*
** name.c for corewar in /home/jeremy/Desktop/corewar/assembler/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 03:15:14 2017 Jérémy Sid Idris
** Last update Tue Mar 21 03:15:14 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/secure_malloc.h"
#include "helpers/string.h"
#include "helpers/output.h"
#include "helpers/name.h"

char	*get_binary_name(char *path)
{
  char	*source_name;
  char	*binary_name;
  int	i;

  i = 0;
  source_name = get_file_name(path);
  source_name = remove_asm_extension(source_name);
  binary_name = secure_malloc(sizeof(char) * len(source_name) + 5);
  while (i < len(source_name))
    {
      binary_name[i] = source_name[i];
      i = i + 1;
    }
  binary_name[i] = '.';
  binary_name[i + 1] = 'c';
  binary_name[i + 2] = 'o';
  binary_name[i + 3] = 'r';
  binary_name[i + 4] = '\0';
  return (binary_name);
}

char	*get_file_name(char *path)
{
  int	i;

  i = len(path) - 1;
  while (i != -1)
    {
      if (path[i] == '/')
	{
	  if (path[i + 1] == 0)
	    exit(print_error(1, "Malformed source file path"));
	  return (&path[i + 1]);
	}
      i = i - 1;
    }
  return (path);
}

char	*remove_asm_extension(char *filename)
{
  int	i;

  i = 0;
  while (filename[i] != 0)
    {
      if (filename[i] == '.' && filename[i + 1] == 's' && filename[i + 2] == 0)
	{
	  filename[i] = '\0';
	  return (filename);
	}
      i = i + 1;
    }
  return (filename);
}
