/*
** corewar.h for corewar in /home/jeremy/Desktop/corewar/vm/include
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Mon Mar 27 04:21:57 2017 Jérémy Sid Idris
** Last update Mon Mar 27 04:21:57 2017 Jérémy Sid Idris
*/

#ifndef COREWAR_H_
# define COREWAR_H_

# define FILE_MAGIC 0xea83f3
# define MEM_SIZE (6 * 1024)
# define IDX_MOD 512
# define MAX_ARGS_NUMBER 4

# define REG_NUMBER 16

# define T_REG 1
# define T_DIR 2
# define T_IND 4
# define T_LAB 8
# define T_ALL T_REG | T_IND | T_DIR

# define REG_SIZE 4
# define IND_SIZE 2
# define DIR_SIZE REG_SIZE

# define CYCLE_TO_DIE 1536
# define CYCLE_DELTA 5
# define NBR_LIVE 40

# define PROG_NAME_LENGTH 128
# define COMMENT_LENGTH 2048
# define UNKNOWN_OPERATOR 16

typedef struct	s_operator
{
  char		*name;
  char		nb_args;
  char		type[MAX_ARGS_NUMBER];
  char		code;
  int		nb_cycles;
  int		has_coding_byte;
  int		is_index;
  void		(*handle)(void *, void *);
}		t_operator;

typedef struct	s_header
{
  int		magic;
  char		prog_name[PROG_NAME_LENGTH + 1];
  int		prog_size;
  char		comment[COMMENT_LENGTH + 1];
}		t_header;

typedef struct		s_process_list
{
  int			id_champion;
  char			*name_champion;
  int			registers[REG_NUMBER];
  int			current_offset;
  int			before_offset;
  t_operator		current_operator;
  int			current_operator_args_amount;
  int			current_operator_args[4];
  int			current_operator_args_type[4];
  int			current_cycle;
  char			carry;
  int			cycle_last_live;
  struct s_process_list	*next;
}			t_process_list;

typedef struct		s_context
{
  int			champions_amount;
  char			dump_option;
  int			dump_at_cycle;
  int			cycle;
  int			cycle_to_die;
  int			live_count;
  unsigned char		memory[MEM_SIZE];
  int			available_ids[4];
  t_process_list	*process_list;
}			t_context;

#endif /* !COREWAR_H_ */
