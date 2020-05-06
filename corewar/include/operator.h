/*
** operator.h for corewar in /home/jeremy/Desktop/corewar/vm/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 28 03:23:02 2017 Jérémy Sid Idris
** Last update Tue Mar 28 03:23:02 2017 Jérémy Sid Idris
*/

#ifndef OPERATOR_H_
# define OPERATOR_H_

# include "corewar.h"

t_operator	get_null_operator();
int		is_null_operator(t_operator);
t_operator	find_operator(char);

#endif /* !OPERATOR_H_ */
