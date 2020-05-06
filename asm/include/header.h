/*
** header.h for corewar in /home/jeremy/Desktop/corewar/asm/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 16:26:06 2017 Jérémy Sid Idris
** Last update Sat Mar 25 16:26:06 2017 Jérémy Sid Idris
*/

#ifndef HEADER_H_
# define HEADER_H_

# include "assembler.h"

int	is_header_line(char *);
void	validate_header(t_file *, int, char *);
void	check_header(t_file *, int, char *);
void	write_header(int, t_file *);

#endif /* !HEADER_H_ */
