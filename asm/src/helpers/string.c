/*
** string.c for corewar in /home/jeremy/Desktop/corewar/assembler/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 14:56:30 2017 Jérémy Sid Idris
** Last update Tue Mar 21 14:56:30 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/secure_malloc.h"
#include "helpers/string.h"

int	len(char *str)
{
  int	count;

  count = 0;
  while (*str != 0)
    {
      count = count + 1;
      str = str + 1;
    }
  return (count);
}

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] == str2[i] && str1[i] != 0)
    i = i + 1;
  return (str1[i] - str2[i]);
}

char	*my_strdup(char *src)
{
  int	i;
  int	size;
  char	*result;

  i = 0;
  size = len(src);
  result = secure_malloc(sizeof(char) * size + 1);
  while (i < size)
    {
      result[i] = src[i];
      i = i + 1;
    }
  result[i] = 0;
  return (result);
}

int	count_words(char *str, char separator)
{
  int	words;

  words = 1;
  while (*str != 0)
    {
      if (*str == separator)
	words = words + 1;
      str = str + 1;
    }
  return (words);
}

int	word_len(char *str, char separator)
{
  int	i;

  i = 0;
  while (*str != 0)
    {
      if (*str == separator)
	break ;
      i = i + 1;
      str = str + 1;
    }
  return (i);
}
