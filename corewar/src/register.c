/*
** register.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 28 03:25:37 2017 Jérémy Sid Idris
** Last update Tue Mar 28 03:25:37 2017 Jérémy Sid Idris
*/

#include "corewar.h"
#include "register.h"

void	empty_register(t_process_list *process)
{
  int	i;

  i = 0;
  while (i < REG_NUMBER)
    {
      process->registers[i] = 0;
      i = i + 1;
    }
}

void	copy_registers(t_process_list *src, t_process_list *target)
{
  int	i;

  i = 0;
  while (i < REG_NUMBER)
    {
      target->registers[i] = src->registers[i];
      i = i + 1;
    }
}

int	get_in_register(t_process_list *process, int number)
{
  return (process->registers[number]);
}

void	set_in_register(t_process_list *process, int number, int value)
{
  process->registers[number] = value;
}
