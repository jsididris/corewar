/*
** dump.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sun Apr  2 17:18:10 2017 Jérémy Sid Idris
** Last update Sun Apr  2 17:18:10 2017 Jérémy Sid Idris
*/

#include "helpers/output.h"
#include "corewar.h"
#include "dump.h"

void	dump_memory(t_context *context)
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      if ((i % 32) == 0)
	{
	  my_puthex(i, 0, 0);
	  my_putstr("\t : ");
	}
      if (context->memory[i] != 0)
	my_putstr("\x1B[36m");
      my_puthex(context->memory[i], 1, 0);
      if (context->memory[i] != 0)
	my_putstr("\x1B[0m");
      if (((i + 1) % 32) == 0)
	my_putchar('\n', 1);
      else
	my_putchar(' ', 1);
      i = i + 1;
    }
}
