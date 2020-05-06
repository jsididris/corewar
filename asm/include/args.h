/*
** args.h for corewar in /home/jeremy/Desktop/corewar/asm/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Thu Mar 23 20:12:11 2017 Jérémy Sid Idris
** Last update Thu Mar 23 20:12:11 2017 Jérémy Sid Idris
*/

#ifndef ARGS_H_
# define ARGS_H_

# include "assembler.h"

char	get_arg_type(char *);
void	validate_instruction_args(t_file *, t_operator, char **);
void	write_instruction_args(t_file *, t_operator, char **, int);
void	write_args_coding_byte(t_operator, char **, int);
char	*purge_args_str(char *);

#endif /* !ARGS_H_ */
