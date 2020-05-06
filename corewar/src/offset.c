/*
** offset.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Mar 29 21:26:45 2017 Jérémy Sid Idris
** Last update Wed Mar 29 21:26:45 2017 Jérémy Sid Idris
*/

#include "corewar.h"
#include "offset.h"

int	get_offset_at_new_addr(t_process_list *process, int addr)
{
  int	new_offset;

  new_offset = (process->before_offset + addr) % MEM_SIZE;
  if (new_offset < 0)
    new_offset = MEM_SIZE + new_offset;
  return (new_offset);
}
