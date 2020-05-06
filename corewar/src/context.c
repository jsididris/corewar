/*
** context.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Mar 27 04:49:19 2017 Jérémy Sid Idris
** Last update Mon Mar 27 04:49:19 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include <stdbool.h>
#include "helpers/output.h"
#include "helpers/string.h"
#include "helpers/number.h"
#include "helpers/secure_malloc.h"
#include "champion.h"
#include "memory.h"
#include "optimal.h"
#include "corewar.h"
#include "context.h"

t_context	*make_context(int argc, char **argv)
{
  t_context	*context;
  int		i;

  i = 0;
  context = secure_malloc(sizeof(t_context));
  context->champions_amount = 0;
  context->dump_option = false;
  context->dump_at_cycle = 0;
  context->cycle = 0;
  context->cycle_to_die = CYCLE_TO_DIE;
  context->live_count = 0;
  context->process_list = NULL;
  context->available_ids[0] = true;
  context->available_ids[1] = true;
  context->available_ids[2] = true;
  context->available_ids[3] = true;
  empty_memory(context);
  fill_available_ids(context, argc, argv, i);
  fill_context_by_parsing(context, argc, argv);
  return (context);
}

void	fill_available_ids(t_context *context, int argc, char **argv, int i)
{
  int	id;

  while (i < argc)
    {
      if (my_strcmp(argv[i], "-n") == 0 && argv[i + 1] != NULL)
	{
	  if (argv[i + 1] == NULL || is_num(argv[i + 1]) != 2)
	    exit(print_error(4, "Program number must be correct number"));
	  id = my_getnbr(argv[i + 1]);
	  if (id > 4 || id <= 0)
	    exit(print_error(4, "Program number must be between 1 & 4"));
	  if (context->available_ids[id - 1] == false)
	    exit(print_error(1, "Prog number (-n) must be unique"));
	  context->available_ids[id - 1] = false;
	  i = i + 2;
	}
      else if (my_strcmp(argv[i], "-a") == 0 && argv[i + 1] != NULL)
	i = i + 2;
      else
	{
	  context->champions_amount = context->champions_amount + 1;
	  i = i + 1;
	}
    }
}

void	fill_context_by_parsing(t_context *context, int argc, char **argv)
{
  int	i;
  int	amount;

  amount = 0;
  i = 0;
  while (i < argc)
    {
      if (my_strcmp(argv[i], "-dump") == 0)
	{
	  if (context->dump_option != false)
	    exit(print_error(4, "Arg -dump already defined !"));
	  if (argv[i + 1] == NULL || is_num(argv[i + 1]) != 2)
	    exit(print_error(4, "Bad integer value for -dump arg"));
	  context->dump_option = true;
	  context->dump_at_cycle = my_getnbr(argv[i + 1]);
	  i = i + 1;
	}
      else
	parse_champion(context, argv, &i, &amount);
      i = i + 1;
    }
  if (amount > 4 || amount < 2)
    exit(print_error(4, "Please provide between 2 & 4 champions"));
}

void	parse_champion(t_context *context, char **argv, int *i, int *amount)
{
  int	id;
  int	address;
  char	*filename;

  id = 0;
  address = 0;
  if (my_strcmp(argv[*i], "-n") == 0 && argv[*i + 1] != NULL)
    {
      id = my_getnbr(argv[*i + 1]);
      *i = *i + 2;
    }
  if (my_strcmp(argv[*i], "-a") == 0 && argv[*i + 1] != NULL)
    {
      if (argv[*i + 1] == NULL || is_num(argv[*i + 1]) != 2)
	exit(print_error(4, "Bad integer value for -a arg"));
      address = my_getnbr(argv[*i + 1]);
      *i = *i + 2;
    }
  if ((filename = argv[*i]) == NULL)
    exit(print_error(4, "Bad champion filename"));
  id = (id == 0 ? find_optimal_id(context) : id);
  address = (address == 0 ? find_optimal_address(context, id) : address);
  add_new_champion(context, id, address, filename);
  *amount = *amount + 1;
}

void			free_context(t_context *context)
{
  t_process_list	*old;

  while (context->process_list != 0)
    {
      old = context->process_list->next;
      free(context->process_list);
      context->process_list = old;
    }
  free(context);
}
