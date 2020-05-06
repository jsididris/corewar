/*
** list.h for corewar in /home/jeremy/Desktop/corewar/vm/include/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 28 03:37:11 2017 Jérémy Sid Idris
** Last update Tue Mar 28 03:37:11 2017 Jérémy Sid Idris
*/

#ifndef LIST_H_
# define LIST_H_

# include "corewar.h"

void	ordered_put_in_list(t_process_list **, t_process_list *);
void	put_at_begin_of_list(t_process_list **, t_process_list *);
void	put_in_list(t_process_list **, t_process_list *,
		    t_process_list *, t_process_list *);
int	count_list(t_process_list *);
int	id_occurence_in_list(int, t_process_list *);
int	list_is_unique(t_process_list *);
void	remove_list_element(t_process_list **, t_process_list *);

#endif /* !LIST_H_ */
