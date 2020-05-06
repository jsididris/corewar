/*
** register.c for corewar in /home/jeremy/Desktop/corewar/asm/src/types
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 16:04:19 2017 Jérémy Sid Idris
** Last update Sat Mar 25 16:04:19 2017 Jérémy Sid Idris
*/

#include <unistd.h>
#include <stdlib.h>
#include "helpers/output.h"
#include "helpers/number.h"
#include "assembler.h"
#include "types/register.h"

void	validate_register_arg(t_file *file, char *arg)
{
  int	register_nb;

  register_nb = my_getnbr(&arg[1]);
  if (register_nb < 1 || register_nb > REG_NUMBER)
    exit(put_parsing_error(file, "Invalid register number"));
  file->offset = file->offset + 1;
}

void	write_register_arg(t_file *file, char *arg, int fd)
{
  char	register_nb;

  register_nb = (char)my_getnbr(&arg[1]);
  if (write(fd, &register_nb, sizeof(char)) != sizeof(char))
    exit(print_error(1, "Error for writing register arg to bytecode file"));
  file->offset = file->offset + 1;
}
