/*
** memory.h for corewar in /home/jeremy/Desktop/corewar/vm/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Mar 27 04:54:19 2017 Jérémy Sid Idris
** Last update Mon Mar 27 04:54:19 2017 Jérémy Sid Idris
*/

#ifndef MEMORY_H_
# define MEMORY_H_

# include "corewar.h"

void		empty_memory(t_context *);
int		memory_read(t_context *, t_process_list *, int);
int		get_in_memory(t_context *, int);
short int	get_index_in_memory(t_context *, int);
void		set_in_memory(t_context *, int, int);

#endif /* !MEMORY_H_ */
