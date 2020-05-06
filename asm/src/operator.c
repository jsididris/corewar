/*
** operator.c for corewar in /home/jeremy/Desktop/corewar/assembler/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 14:39:58 2017 Jérémy Sid Idris
** Last update Tue Mar 21 14:39:58 2017 Jérémy Sid Idris
*/

#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include "helpers/output.h"
#include "helpers/string.h"
#include "assembler.h"
#include "operator.h"

t_operator	g_operators_array[] =
{
  {"live", 1, {T_DIR}, 1, 10, false, false},
  {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, true, false},
  {"st", 2, {T_REG, T_IND | T_REG}, 3, 5, true, false},
  {"add", 3, {T_REG, T_REG, T_REG}, 4, 10, true, false},
  {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, true, false},
  {"and", 3, {T_ALL, T_ALL, T_REG}, 6, 6, true, false},
  {"or", 3, {T_ALL, T_ALL, T_REG}, 7, 6, true, false},
  {"xor", 3, {T_ALL, T_ALL, T_REG}, 8, 6, true, false},
  {"zjmp", 1, {T_DIR}, 9, 20, false, true},
  {"ldi", 3, {T_ALL, T_DIR | T_REG, T_REG}, 10, 25, true, true},
  {"sti", 3, {T_REG, T_ALL, T_DIR | T_REG}, 11, 25, true, true},
  {"fork", 1, {T_DIR}, 12, 800, false, true},
  {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, true, false},
  {"lldi", 3, {T_ALL, T_DIR | T_REG, T_REG}, 14, 50, true, true},
  {"lfork", 1, {T_DIR}, 15, 1000, false, true},
  {"aff", 1, {T_REG}, 16, 2, true, false},
  {NULL, 0, {0}, 0, 0, false, false}
};

t_operator	find_operator(char *str)
{
  int		i;

  i = 0;
  while (g_operators_array[i].name != NULL)
    {
      if (my_strcmp(str, g_operators_array[i].name) == 0)
	return (g_operators_array[i]);
      i = i + 1;
    }
  return (g_operators_array[UNKNOWN_OPERATOR]);
}

int	is_operator(t_operator operator)
{
  if (operator.name == NULL)
    return (0);
  return (1);
}

void	write_operator(t_operator operator, int fd)
{
  if (write(fd, &operator.code, sizeof(char)) != sizeof(char))
    exit(print_error(1, "Error for writing operator to bytecode file"));
}
