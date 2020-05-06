/*
** instruction.h for corewar in /home/jeremy/Desktop/corewar/asm/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 16:28:36 2017 Jérémy Sid Idris
** Last update Sat Mar 25 16:28:36 2017 Jérémy Sid Idris
*/

#ifndef INSTRUCTION_H_
# define INSTRUCTION_H_

# include "assembler.h"

void	validate_instruction(t_file *, char **);
void	check_instruction(t_file *, t_operator, char **);
void	write_instruction(t_file *, char **, int);
void	free_instruction(char *, char *, char **);

#endif /* !INSTRUCTION_H_ */
