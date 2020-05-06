/*
** validator.h for corewar in /home/jeremy/Desktop/corewar/assembler/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 15:18:14 2017 Jérémy Sid Idris
** Last update Tue Mar 21 15:18:14 2017 Jérémy Sid Idris
*/

#ifndef VALIDATOR_H_
# define VALIDATOR_H_

# include "assembler.h"

t_file	*validate_source(int, char *);
void	initiate_validate_instruction(t_file *, char **);
t_file	*end_file_validation(t_file *);
void	free_validator_readed_line(char *, char *, char **);

#endif /* !VALIDATOR_H_ */
