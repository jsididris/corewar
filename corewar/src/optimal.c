/*
** optimal.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 28 05:32:35 2017 Jérémy Sid Idris
** Last update Tue Mar 28 05:32:35 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include <stdbool.h>
#include "helpers/output.h"
#include "corewar.h"
#include "optimal.h"

int	find_optimal_id(t_context *context)
{
  int	optimal;

  optimal = 0;
  if (context->available_ids[0] == true)
    optimal = 1;
  else if (context->available_ids[1] == true)
    optimal = 2;
  else if (context->available_ids[2] == true)
    optimal = 3;
  else if (context->available_ids[3] == true)
    optimal = 4;
  else
    exit(print_error(1, "Too many champions !"));
  context->available_ids[optimal - 1] = false;
  return (optimal);
}

int	find_optimal_address(t_context *context, int id)
{
  int	amount;
  int	unity;
  int	i;

  amount = context->champions_amount;
  if (amount == 4)
    return ((MEM_SIZE / 4) * (id - 1));
  unity = MEM_SIZE / amount;
  i = 0;
  while (i < amount)
    {
      if (context->memory[unity * i] == 0)
	return (unity * i);
      i = i + 1;
    }
  exit(print_error(1, "Unable to find optimal address : very curious :/"));
}
