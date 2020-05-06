/*
** indirect.h for corewar in /home/jeremy/Desktop/corewar/asm/include/types
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 16:11:44 2017 Jérémy Sid Idris
** Last update Sat Mar 25 16:11:44 2017 Jérémy Sid Idris
*/

#ifndef INDIRECT_H_
# define INDIRECT_H_

# include "assembler.h"

void	validate_indirect_arg(t_file *, char *);
void	write_indirect_arg(t_file *, char *, int);

#endif /* !INDIRECT_H_ */
