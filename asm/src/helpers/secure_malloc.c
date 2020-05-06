/*
** secure_malloc.c for corewar in /home/jeremy/Desktop/corewar/assembler/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 02:56:21 2017 Jérémy Sid Idris
** Last update Tue Mar 21 02:56:21 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/output.h"

void	*secure_malloc(size_t size)
{
  void	*malloced;

  if ((malloced = malloc(size)) == NULL)
    {
      print_error(2, "Malloc failed");
      exit(84);
    }
  return (malloced);
}
