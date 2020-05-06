/*
** process.h for corewar in /home/jeremy/Desktop/corewar/vm/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 28 03:09:16 2017 Jérémy Sid Idris
** Last update Tue Mar 28 03:09:16 2017 Jérémy Sid Idris
*/

#ifndef PROCESS_H_
# define PROCESS_H_

# include "corewar.h"

t_process_list	*find_process_by_id(t_context *, int);
t_process_list	*make_process(t_context *, int, char *, int);
void		reset_process_task(t_process_list *);
void		copy_process_state(t_process_list *, t_process_list *);
void		remove_process(t_context *, t_process_list *);

#endif /* !PROCESS_H_ */
