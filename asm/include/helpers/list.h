/*
** list.h for corewar in /home/jeremy/Desktop/corewar/assembler/include/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Mar 22 17:03:42 2017 Jérémy Sid Idris
** Last update Wed Mar 22 17:03:42 2017 Jérémy Sid Idris
*/

#ifndef LIST_H_
# define LIST_H_

# include "assembler.h"

void	put_in_list(t_labels_list **, char *, int, int);
int	count_list(t_labels_list *);
int	name_occurence_in_list(char *, t_labels_list *);
void	purge_list(t_labels_list **);

#endif /* !LIST_H_ */
