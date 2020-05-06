/*
** assembler.h for corewar in /home/jeremy/Desktop/corewar/assembler/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Tue Mar 21 15:20:53 2017 Jérémy Sid Idris
** Last update Tue Mar 21 15:20:53 2017 Jérémy Sid Idris
*/

#ifndef ASSEMBLER_H_
# define ASSEMBLER_H_

# define FILE_MAGIC 0xea83f3
# define MEM_SIZE (6 * 1024)
# define IDX_MOD 512
# define MAX_ARGS_NUMBER 4

# define COMMENT_CHAR '#'
# define LABEL_CHAR ':'
# define DIRECT_CHAR '%'
# define SEPARATOR_CHAR ','
# define REGISTER_CHAR 'r'
# define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING ".name"
# define HEADER_TYPE_NAME 1
# define COMMENT_CMD_STRING ".comment"
# define HEADER_TYPE_COMMENT 2

# define REG_NUMBER 16

# define T_REG 1
# define T_DIR 2
# define T_IND 4
# define T_LAB 8
# define T_ALL T_REG | T_IND | T_DIR

# define UNKNOWN_OPERATOR 16

# define TOKEN_TYPE_LABEL 1
# define TOKEN_TYPE_INSTRUCTION 2

# define LABEL_DECLARATION 1
# define LABEL_USAGE 2

# define REG_SIZE 4
# define IND_SIZE 2
# define DIR_SIZE REG_SIZE
# define PROG_NAME_LENGTH 128
# define COMMENT_LENGTH 2048

typedef struct	s_operator
{
  char		*name;
  char		nb_args;
  char		type[MAX_ARGS_NUMBER];
  char		code;
  int		nb_cycles;
  int		has_coding_byte;
  int		is_index;
}		t_operator;

typedef struct	s_header
{
  int		magic;
  char		prog_name[PROG_NAME_LENGTH + 1];
  int		prog_size;
  char		comment[COMMENT_LENGTH + 1];
}		t_header;

typedef struct		s_labels_list
{
  char			*name;
  int			line;
  int			offset;
  struct s_labels_list	*next;
}			t_labels_list;

typedef struct	s_file
{
  char		*name;
  int		line;
  int		offset;
  int		offset_instruction;
  int		header_has_name;
  int		passed_header;
  t_labels_list	*label_usage_list;
  t_labels_list	*label_def_list;
  t_header	*header;
}		t_file;

void	assembler(char *);

#endif /* !ASSEMBLER_H_ */
