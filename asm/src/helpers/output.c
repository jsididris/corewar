/*
** output.c for corewar in /home/jeremy/Desktop/corewar/assembler/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 02:04:10 2017 Jérémy Sid Idris
** Last update Tue Mar 21 02:04:10 2017 Jérémy Sid Idris
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

int	put_parsing_error(t_file *file, char *error)
{
  write(2, "Error for ", 10);
  write(2, file->name, len(file->name));
  write(2, ": ", 2);
  write(2, error, len(error));
  write(2, " found at line ", 15);
  my_putnbr(file->line, 2);
  write(2, " at offset [", 12);
  my_putnbr(file->offset, 2);
  write(2, "]\n", 2);
  return (84);
}
