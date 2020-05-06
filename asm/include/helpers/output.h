/*
** output.h for corewar in /home/jeremy/Desktop/corewar/assembler/include/helpers
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 02:05:41 2017 Jérémy Sid Idris
** Last update Tue Mar 21 02:05:41 2017 Jérémy Sid Idris
*/

#ifndef OUTPUT_H_
# define OUTPUT_H_

# include "assembler.h"

int	print_error(int, char *);
void	my_putchar(char, int);
void	my_putstr(char *);
void	my_putnbr(int, int);
int	put_parsing_error(t_file *, char *);

#endif /* !OUTPUT_H_ */
