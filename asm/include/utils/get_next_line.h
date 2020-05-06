/*
** get_next_line.h for corewar in /home/jeremy/Desktop/corewar/assembler/include/utils
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 02:06:03 2017 Jérémy Sid Idris
** Last update Tue Mar 21 02:06:03 2017 Jérémy Sid Idris
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (9483)
# endif

char	*get_next_line(const int);
char	*read_data(int, char *, int);
char	*append_begin_buffer(int *, int *, int *, int);
char	*my_alloc(char *, int, int *);
void	cut_buffer(int);

#endif /* !GET_NEXT_LINE_H_ */
