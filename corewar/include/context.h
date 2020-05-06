/*
** context.h for corewar in /home/jeremy/Desktop/corewar/vm/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Mar 27 04:48:22 2017 Jérémy Sid Idris
** Last update Mon Mar 27 04:48:22 2017 Jérémy Sid Idris
*/

#ifndef CONTEXT_H_
# define CONTEXT_H_

# include "corewar.h"

t_context	*make_context(int, char **);
void		fill_context_by_parsing(t_context *, int, char **);
void		fill_available_ids(t_context *, int, char **, int);
void		parse_champion(t_context *, char **, int *, int *);
void		free_context(t_context *);

#endif /* !CONTEXT_H_ */
