/*
** operator.h for corewar in /home/jeremy/Desktop/corewar/assembler/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 15:18:56 2017 Jérémy Sid Idris
** Last update Tue Mar 21 15:18:56 2017 Jérémy Sid Idris
*/

#ifndef OPERATOR_H_
# define OPERATOR_H_

# include "assembler.h"

t_operator	find_operator(char *);
int		is_operator(t_operator);
void		write_operator(t_operator, int);

#endif /* !OPERATOR_H_ */
