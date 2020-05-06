/*
** secure_malloc.c for corewar in /home/jeremy/Desktop/corewar/vm/src/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Mar 27 04:11:13 2017 Jérémy Sid Idris
** Last update Mon Mar 27 04:11:13 2017 Jérémy Sid Idris
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
