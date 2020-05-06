/*
** validation.c for corewar in /home/jeremy/Desktop/corewar/vm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Mar 29 08:24:36 2017 Jérémy Sid Idris
** Last update Wed Mar 29 08:24:36 2017 Jérémy Sid Idris
*/

#include "corewar.h"
#include "validation.h"

int	validate_register(int number)
{
  if (number < 1 || number > REG_NUMBER)
    return (0);
  return (1);
}
