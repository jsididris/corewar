/*
** number.c for corewar in /home/jeremy/Desktop/corewar/vm/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Mar 27 04:10:54 2017 Jérémy Sid Idris
** Last update Mon Mar 27 04:10:54 2017 Jérémy Sid Idris
*/

#include "helpers/number.h"

int	is_num(char *str)
{
  int	in_num;

  in_num = 0;
  while (*str != 0)
    {
      if (!(*str >= '0' && *str <= '9'))
	{
	  if (*str == '-' && in_num == 0)
	    {
	      str = str + 1;
	      in_num = 1;
	      continue;
	    }
	  return (in_num);
	}
      in_num = 1;
      str = str + 1;
    }
  return (2);
}

int	my_getnbr(char *str)
{
  int	number;
  int	is_neg;

  is_neg = 0;
  number = 0;
  while (*str != 0)
    {
      if (*str == '-')
	is_neg = 1;
      else
	{
	  number = number * 10;
	  number = number + (*str - '0');
	}
      str = str + 1;
    }
  number = number * (is_neg ? -1 : 1);
  return (number);
}
