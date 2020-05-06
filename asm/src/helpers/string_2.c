/*
** string_2.c for corewar in /home/jeremy/Desktop/corewar/assembler/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 14:56:40 2017 Jérémy Sid Idris
** Last update Tue Mar 21 14:56:40 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/secure_malloc.h"
#include "helpers/string.h"

char	**my_str_to_wordtab(char *str, char sep)
{
  char	**result;
  int	i_word;
  int	i_letter;

  i_word = 0;
  i_letter = 0;
  result = secure_malloc(sizeof(char *) * count_words(str, sep) + 10);
  result[i_word] = secure_malloc(sizeof(char) * word_len(str, sep) + 1);
  while (*str != '\0')
    {
      if (*str == sep)
	{
	  begin_new_word_in_tab(result, &i_word, &i_letter);
	  result[i_word] = secure_malloc(word_len(str + 1, sep) + 1);
	}
      else
	{
	  result[i_word][i_letter] = *str;
	  i_letter = i_letter + 1;
	}
      str = str + 1;
    }
  result[i_word][i_letter] = '\0';
  result[i_word + 1] = NULL;
  return (result);
}

void	begin_new_word_in_tab(char **result, int *i_word, int *i_letter)
{
  result[*i_word][*i_letter] = '\0';
  *i_word = *i_word + 1;
  *i_letter = 0;
}

void	my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  if (src == NULL)
    return ;
  while (src[i] != 0)
    {
      dest[i] = src[i];
      i = i + 1;
    }
}

int	is_separator(char c)
{
  if (c == '\t' || c == ' ')
    return (1);
  return (0);
}

char	*cut_str(char *str, char separator)
{
  int	i;
  int	in_quote;

  i = 0;
  in_quote = 0;
  while (str[i] != 0)
    {
      if (str[i] == '"')
	in_quote = (in_quote ? 0 : 1);
      else if (str[i] == separator && !in_quote)
	{
	  str[i] = '\0';
	  return (str);
	}
      i = i + 1;
    }
  return (str);
}
