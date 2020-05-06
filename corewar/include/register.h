/*
** register.h for corewar in /home/jeremy/Desktop/corewar/vm/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 28 03:23:44 2017 Jérémy Sid Idris
** Last update Tue Mar 28 03:23:44 2017 Jérémy Sid Idris
*/

#ifndef REGISTER_H_
# define REGISTER_H_

# include "corewar.h"

void	empty_register(t_process_list *);
void	copy_registers(t_process_list *, t_process_list *);
int	get_in_register(t_process_list *, int);
void	set_in_register(t_process_list *, int, int);

#endif /* !REGISTER_H_ */
