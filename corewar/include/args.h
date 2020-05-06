/*
** args.h for corewar in /home/jeremy/Desktop/corewar/vm/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Mar 29 06:43:39 2017 Jérémy Sid Idris
** Last update Wed Mar 29 06:43:39 2017 Jérémy Sid Idris
*/

#ifndef ARGS_H_
# define ARGS_H_

# include "corewar.h"

int	check_args(t_context *, t_process_list *, t_operator);
int	handle_args(t_context *, t_process_list *, t_operator, int *);
void	handle_register_arg(t_context *, t_process_list *, int);
void	handle_indirect_arg(t_context *, t_process_list *, int);
void	handle_direct_arg(t_context *, t_process_list *, int, t_operator);
int	check_unique_arg(t_context *, t_process_list *, t_operator);

#endif /* !ARGS_H_ */
