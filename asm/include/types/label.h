/*
** label.h for corewar in /home/jeremy/Desktop/corewar/asm/include/types
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 16:12:22 2017 Jérémy Sid Idris
** Last update Sat Mar 25 16:12:22 2017 Jérémy Sid Idris
*/

#ifndef LABEL_H_
# define LABEL_H_

# include "assembler.h"

void	validate_label(t_file *, int, char *);
void	validate_label_usages(t_file *);
int	get_label(t_file *, char *);

#endif /* !LABEL_H_ */
