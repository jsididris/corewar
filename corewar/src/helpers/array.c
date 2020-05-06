/*
** array.c for corewar in /home/jeremy/Desktop/corewar/vm/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Mar 27 04:10:36 2017 Jérémy Sid Idris
** Last update Mon Mar 27 04:10:36 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/secure_malloc.h"
#include "helpers/string.h"
#include "helpers/array.h"

int	array_size(char **array)
{
  int	i;

  i = 0;
  while (array[i] != NULL)
    {
      i = i + 1;
    }
  return (i);
}

int	exist_in_string_array(char pattern, char *array)
{
  int	i;

  i = 0;
  while (array[i] != 0)
    {
      if (pattern == array[i])
	return (1);
      i = i + 1;
    }
  return (0);
}

void	free_str_to_wordtab(char **arr)
{
  int	i;

  i = 0;
  while (arr[i] != NULL)
    {
      free(arr[i]);
      i = i + 1;
    }
  free(arr);
}
