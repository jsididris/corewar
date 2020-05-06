/*
** token.c for corewar in /home/jeremy/Desktop/corewar/assembler/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 15:23:32 2017 Jérémy Sid Idris
** Last update Tue Mar 21 15:23:32 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/number.h"
#include "helpers/string.h"
#include "assembler.h"
#include "token.h"

int	is_empty_tokens(char **tokens)
{
  int	i;

  i = 0;
  while (tokens[i] != NULL)
    {
      if (len(tokens[i]) != 0)
	return (0);
      i = i + 1;
    }
  return (1);
}

int	get_token_type(char *token)
{
  if (token[len(token) - 1] == LABEL_CHAR)
    return (TOKEN_TYPE_LABEL);
  else
    return (TOKEN_TYPE_INSTRUCTION);
}
