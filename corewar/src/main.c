/*
** main.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Mar 27 04:20:18 2017 Jérémy Sid Idris
** Last update Mon Mar 27 04:20:18 2017 Jérémy Sid Idris
*/

#include "helpers/list.h"
#include "helpers/output.h"
#include "context.h"
#include "dump.h"
#include "process.h"
#include "cycle.h"
#include "corewar.h"

int		main(int argc, char **argv)
{
  t_context	*context;

  if (argc == 1)
    {
      my_putstr("Usage: ./corewar [-dump cycle_nb] [[-a load_addr]"
		 "[-n prog_nb] prog.cor] ...\n");
      return (84);
    }
  context = make_context(argc - 1, argv + 1);
  while (before_cycle(context) == 0)
    {
      perform_cycle(context);
      if (context->dump_option && !list_is_unique(context->process_list) &&
	  context->cycle == context->dump_at_cycle)
	{
	  dump_memory(context);
	  free_context(context);
	  return (0);
	}
    }
  free_context(context);
  return (0);
}
