/*
** champion.h for corewar in /home/jeremy/Desktop/corewar/vm/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 28 01:04:45 2017 Jérémy Sid Idris
** Last update Tue Mar 28 01:04:45 2017 Jérémy Sid Idris
*/

#ifndef CHAMPION_H_
# define CHAMPION_H_

# include "corewar.h"

void	add_new_champion(t_context *, int, int, char *);
int	check_prog_size(int, int);
int	is_alive(t_context *, t_process_list *);
void	put_champion_in_memory(t_context *, int, int, int);

#endif /* !CHAMPION_H_ */
