/*
** output.c for corewar in /home/jeremy/Desktop/corewar/vm/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Mar 27 04:11:03 2017 Jérémy Sid Idris
** Last update Mon Mar 27 04:11:03 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include <unistd.h>
#include "helpers/string.h"
#include "helpers/output.h"

int	print_error(int type, char *str)
{
  if (type == 1)
    write(2, "[Fatal error] ", 14);
  else if (type == 2)
    write(2, "[Memory error] ", 15);
  else if (type == 3)
    write(2, "[Parsing error] ", 16);
  else if (type == 4)
    write(2, "[Usage error] ", 14);
  write(2, str, len(str));
  write(2, "\n", 1);
  return (84);
}

void	my_putchar(char c, int type)
{
  write(type, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, len(str));
}

void	my_putnbr(int nbr, int type)
{
  int	divisor;

  divisor = 1;
  while ((nbr / divisor) >= 10)
    divisor = divisor * 10;
  while (divisor != 0)
    {
      my_putchar((nbr / divisor) % 10 + '0', type);
      divisor = divisor / 10;
    }
}

void	my_puthex(int value, int fill, int pass)
{
  char	*map;

  map = "0123456789ABCDEF";
  if (value > 15)
    my_puthex(value / 16, fill, 1);
  if (fill && pass == 0 && value <= 15)
    my_putchar('0', 1);
  my_putchar(map[value % 16], 1);
}
