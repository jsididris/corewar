/*
** memory.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Mar 27 04:52:54 2017 Jérémy Sid Idris
** Last update Mon Mar 27 04:52:54 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/endianness.h"
#include "corewar.h"
#include "memory.h"

void	empty_memory(t_context *context)
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      context->memory[i] = 0;
      i = i + 1;
    }
}

int	memory_read(t_context *context, t_process_list *process, int size)
{
  int	readed_value;

  if (size == 1)
    readed_value = context->memory[process->current_offset % MEM_SIZE];
  else if (size == 2)
    {
      readed_value = context->memory[process->current_offset % MEM_SIZE] |
	context->memory[(process->current_offset + 1) % MEM_SIZE] << 8;
      readed_value = swap_short_endianness(readed_value);
    }
  else if (size == 4)
    {
      readed_value =
	(context->memory[process->current_offset % MEM_SIZE] << 24) |
	(context->memory[(process->current_offset + 1) % MEM_SIZE] << 16) |
	(context->memory[(process->current_offset + 2) % MEM_SIZE] << 8) |
	context->memory[(process->current_offset + 3) % MEM_SIZE];
    }
  process->current_offset = (process->current_offset + size) % MEM_SIZE;
  return (readed_value);
}

int	get_in_memory(t_context *context, int offset)
{
  int	value;

  value =
    (context->memory[offset % MEM_SIZE] << 24) |
    (context->memory[(offset + 1) % MEM_SIZE] << 16) |
    (context->memory[(offset + 2) % MEM_SIZE] << 8) |
    context->memory[(offset + 3) % MEM_SIZE];
  return (value);
}

short int	get_index_in_memory(t_context *context, int offset)
{
  short int	value;

  value =
    (context->memory[offset % MEM_SIZE] << 8) |
    context->memory[(offset + 1) % MEM_SIZE];
  return (value);
}

void	set_in_memory(t_context *context, int offset, int value)
{
  context->memory[offset % MEM_SIZE] = (value >> 24) & 0xFF;
  context->memory[(offset + 1) % MEM_SIZE] = (value >> 16) & 0xFF;
  context->memory[(offset + 2) % MEM_SIZE] = (value >> 8) & 0xFF;
  context->memory[(offset + 3) % MEM_SIZE] = value & 0xFF;
}
