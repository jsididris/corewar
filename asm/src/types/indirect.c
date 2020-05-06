/*
** indirect.c for corewar in /home/jeremy/Desktop/corewar/asm/src/types
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 16:05:21 2017 Jérémy Sid Idris
** Last update Sat Mar 25 16:05:21 2017 Jérémy Sid Idris
*/

#include <unistd.h>
#include <stdlib.h>
#include "helpers/number.h"
#include "helpers/output.h"
#include "helpers/endianness.h"
#include "assembler.h"
#include "types/label.h"
#include "types/indirect.h"

void	validate_indirect_arg(t_file *file, char *arg)
{
  char	*indirect;

  indirect = arg;
  if (indirect[0] == LABEL_CHAR)
    validate_label(file, LABEL_USAGE, indirect);
  file->offset = file->offset + 2;
}

void		write_indirect_arg(t_file *file, char *arg, int fd)
{
  char		*indirect;
  short int	indirect_value;

  indirect = arg;
  if (indirect[0] == LABEL_CHAR)
     indirect_value = (short int)get_label(file, &indirect[1]);
  else
    indirect_value = (short int)my_getnbr(indirect);
  indirect_value = swap_short_endianness(indirect_value);
  if (write(fd, &indirect_value, sizeof(short int)) != sizeof(short int))
    exit(print_error(1, "Error for writing indirect arg to bytecode file"));
  file->offset = file->offset + 2;
}
