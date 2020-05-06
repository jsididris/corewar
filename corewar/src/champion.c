/*
** champion.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 28 00:50:37 2017 Jérémy Sid Idris
** Last update Tue Mar 28 00:50:37 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "helpers/secure_malloc.h"
#include "helpers/output.h"
#include "helpers/string.h"
#include "helpers/endianness.h"
#include "memory.h"
#include "process.h"
#include "corewar.h"
#include "champion.h"

void		add_new_champion(t_context *context, int id,
				 int addr, char *filename)
{
  int		fd;
  t_header	header;
  char		*name;

  if ((fd = open(filename, O_RDONLY)) == -1)
    exit(print_error(1, "Can't open champion file"));
  if (read(fd, &header, sizeof(t_header)) != sizeof(t_header))
    exit(print_error(1, "Bad champion header : unable to read it"));
  if (swap_endianness(header.magic) != FILE_MAGIC)
    exit(print_error(1, "Bad champion header : magic mismatch"));
  if (!check_prog_size(swap_endianness(header.prog_size), fd))
    exit(print_error(1, "Bad champion header : invalid prog_size"));
  name = secure_malloc(sizeof(char) * len(header.prog_name) + 1);
  my_strcpy(name, header.prog_name);
  name[len(header.prog_name)] = '\0';
  put_champion_in_memory(context, swap_endianness(header.prog_size), addr, fd);
  make_process(context, id, name, addr);
  close(fd);
}

int	check_prog_size(int size, int fd)
{
  off_t	origin_position;
  off_t	end_position;

  if ((origin_position = lseek(fd, 0, SEEK_CUR)) == 0 ||
      (end_position = lseek(fd, 0, SEEK_END)) == 0)
    return (0);
  if ((end_position - origin_position) != size)
    return (0);
  if (lseek(fd, sizeof(t_header), SEEK_SET) != sizeof(t_header))
    return (0);
  return (1);
}

int	is_alive(t_context *context, t_process_list *process)
{
  int	diff;

  diff = context->cycle - process->cycle_last_live;
  if (diff < context->cycle_to_die)
    return (1);
  return (0);
}

void	put_champion_in_memory(t_context *context, int size, int addr, int fd)
{
  int	i;

  i = 0;
  while (i < size)
    {
      if (context->memory[((addr + i) % MEM_SIZE)] != 0)
	exit(print_error(1, "Overlap detected"));
      if (read(fd, &context->memory[((addr + i) % MEM_SIZE)], 1) != 1)
	exit(print_error(1, "Can't read an byte of instruction : "
			 "double check program size in header"));
      i = i + 1;
    }
}
