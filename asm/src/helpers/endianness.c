/*
** endianness.c for corewar in /home/jeremy/Desktop/corewar/asm/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 16:36:27 2017 Jérémy Sid Idris
** Last update Sat Mar 25 16:36:27 2017 Jérémy Sid Idris
*/

#include "helpers/endianness.h"

short int	swap_short_endianness(short int number)
{
  int		tmp;

  tmp = (number << 8) | ((number >> 8) & 0xFF);
  return (tmp);
}

int	swap_endianness(int number)
{
  int	tmp;

  tmp = ((number >> 24) & 0xff) | ((number << 8) & 0xff0000) |
    ((number >> 8) & 0xff00) | ((number << 24) & 0xff000000);
  return (tmp);
}
