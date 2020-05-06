/*
** cycle.h for corewar in /home/jeremy/Desktop/corewar/vm/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Mar 29 06:23:18 2017 Jérémy Sid Idris
** Last update Wed Mar 29 06:23:18 2017 Jérémy Sid Idris
*/

#ifndef CYCLE_H_
# define CYCLE_H_

# include "corewar.h"

int	before_cycle(t_context *);
void	perform_cycle(t_context *);
void	try_perform_instruction(t_context *, t_process_list *, t_operator);
void	perform_instruction(t_context *, t_process_list *);

#endif /* !CYCLE_H_ */
