/*
** register.h for corewar in /home/jeremy/Desktop/corewar/asm/include/types
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 16:10:07 2017 Jérémy Sid Idris
** Last update Sat Mar 25 16:10:07 2017 Jérémy Sid Idris
*/

#ifndef REGISTER_H_
# define REGISTER_H_

# include "assembler.h"

void	validate_register_arg(t_file *, char *);
void	write_register_arg(t_file *, char *, int);

#endif /* !REGISTER_H_ */
