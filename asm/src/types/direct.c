/*
** direct.c for corewar in /home/jeremy/Desktop/corewar/asm/src/types
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 16:04:57 2017 Jérémy Sid Idris
** Last update Sat Mar 25 16:04:57 2017 Jérémy Sid Idris
*/

#include <unistd.h>
#include <stdlib.h>
#include "helpers/number.h"
#include "helpers/output.h"
#include "helpers/endianness.h"
#include "assembler.h"
#include "types/label.h"
#include "types/direct.h"

void	validate_direct_arg(t_file *file, char *arg, int is_index)
{
  char	*direct;

  direct = &arg[1];
  if (direct[0] == LABEL_CHAR)
    validate_label(file, LABEL_USAGE, direct);
  file->offset = file->offset + (is_index ? 2 : 4);
}

void		write_direct_arg(t_file *file, char *arg, int is_index, int fd)
{
  char		*direct;
  short int	index_value;
  int		direct_value;

  direct = &arg[1];
  if (direct[0] == LABEL_CHAR)
    direct_value = get_label(file, &direct[1]);
  else
    direct_value = my_getnbr(direct);
  if (is_index)
    {
      index_value = (short int)direct_value;
      index_value = swap_short_endianness(index_value);
      if (write(fd, &index_value, sizeof(short int)) != sizeof(short int))
	exit(print_error(1, "Error for writing dir_ind arg to bytecode file"));
    }
  else
    {
      direct_value = swap_endianness(direct_value);
      if (write(fd, &direct_value, sizeof(int)) != sizeof(int))
	exit(print_error(1, "Error for writing direct arg to bytecode file"));
    }
  file->offset = file->offset + (is_index ? 2 : 4);
}
