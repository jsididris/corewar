/*
** main.c for corewar in /home/jeremy/Desktop/corewar/assembler/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 02:06:23 2017 Jérémy Sid Idris
** Last update Tue Mar 21 02:06:23 2017 Jérémy Sid Idris
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "helpers/output.h"
#include "helpers/name.h"
#include "header.h"
#include "validator.h"
#include "analyzer.h"
#include "assembler.h"

int	main(int argc, char **argv)
{
  int	i;

  if (argc == 1)
    {
      my_putstr("Usage : ");
      my_putstr(argv[0]);
      my_putstr(" file_name[.s]\n");
      return (84);
    }
  i = 1;
  while (i < argc)
    {
      assembler(argv[i]);
      i = i + 1;
    }
  return (0);
}

void		assembler(char *file_name)
{
  t_file	*file;
  char		*output_name;
  int		source_fd;
  int		output_fd;

  if ((source_fd = open(file_name, O_RDONLY)) == -1)
    exit(print_error(1, "Can't open source file"));
  output_name = get_binary_name(file_name);
  file = validate_source(source_fd, file_name);
  if ((output_fd = open(output_name, O_CREAT | O_WRONLY | O_TRUNC,
       S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    exit(print_error(1, "Can't make destination bytecode file"));
  if (lseek(source_fd, 0, SEEK_SET) == -1)
    exit(print_error(1, "Can't go at the begin of source file"));
  write_header(output_fd, file);
  analyze_source(source_fd, output_fd, file);
  close(source_fd);
  close(output_fd);
}
