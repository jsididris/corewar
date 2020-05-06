/*
** operator.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 28 03:20:57 2017 Jérémy Sid Idris
** Last update Tue Mar 28 03:20:57 2017 Jérémy Sid Idris
*/

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "instructions/manage.h"
#include "instructions/arithmetic.h"
#include "instructions/long.h"
#include "instructions/misc.h"
#include "corewar.h"
#include "operator.h"

t_operator	g_operators_array[] =
{
  {"live", 1, {T_DIR}, 1, 10, false, false, instruction_live},
  {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, true, false, instruction_ld},
  {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, true, false, instruction_st},
  {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, true, false, instruction_add},
  {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, true, false, instruction_sub},
  {"and", 3, {T_ALL, T_ALL, T_REG}, 6, 6, true, false, instruction_and},
  {"or", 3, {T_ALL, T_ALL, T_REG}, 7, 6, true, false, instruction_or},
  {"xor", 3, {T_ALL, T_ALL, T_REG}, 8, 6, true, false, instruction_xor},
  {"zjmp", 1, {T_DIR}, 9, 20, false, true, instruction_zjmp},
  {"ldi", 3, {T_ALL, T_DIR | T_REG, T_REG}, 10, 25, 1, 1, instruction_ldi},
  {"sti", 3, {T_REG, T_ALL, T_DIR | T_REG}, 11, 25, 1, 1, instruction_sti},
  {"fork", 1, {T_DIR}, 12, 800, false, true, instruction_fork},
  {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, true, false, instruction_lld},
  {"lldi", 3, {T_ALL, T_DIR | T_REG, T_REG}, 14, 50, 1, 1, instruction_lldi},
  {"lfork", 1, {T_DIR}, 15, 1000, false, true, instruction_lfork},
  {"aff", 1, {T_REG}, 16, 2, true, false, instruction_aff},
  {NULL, 0, {0}, 0, 0, false, false, NULL}
};

t_operator	get_null_operator()
{
  return (g_operators_array[UNKNOWN_OPERATOR]);
}

int	is_null_operator(t_operator operator)
{
  return (operator.name == NULL);
}

t_operator	find_operator(char code)
{
  int		i;

  i = 0;
  while (!is_null_operator(g_operators_array[i]))
    {
      if (code == g_operators_array[i].code)
	return (g_operators_array[i]);
      i = i + 1;
    }
  return (get_null_operator());
}
