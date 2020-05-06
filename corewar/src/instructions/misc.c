/*
** misc.c for corewar in /home/jeremy/Desktop/corewar/vm/src/instructions
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Wed Mar 29 18:52:34 2017 Jérémy Sid Idris
** Last update Wed Mar 29 18:52:34 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/list.h"
#include "helpers/output.h"
#include "process.h"
#include "register.h"
#include "offset.h"
#include "corewar.h"
#include "instructions/misc.h"

void			instruction_live(void *raw1, void *raw2)
{
  t_context		*context;
  t_process_list	*process;
  int			champion_id;

  context = (t_context *)raw1;
  process = (t_process_list *)raw2;
  champion_id = process->current_operator_args[0];
  if (id_occurence_in_list(champion_id, context->process_list) == 0)
    return ;
  if (process->id_champion != champion_id)
    process = find_process_by_id(context, champion_id);
  if (process == NULL)
    return ;
  process->cycle_last_live = context->cycle;
  if ((context->live_count = context->live_count + 1) >= NBR_LIVE)
    {
      context->cycle_to_die = context->cycle_to_die - CYCLE_DELTA;
      context->live_count = 0;
    }
  my_putstr("The player ");
  my_putnbr(process->id_champion, 1);
  my_putstr(" (");
  my_putstr(process->name_champion);
  my_putstr(") is alive.\n");
}

void			instruction_aff(void *raw1, void *raw2)
{
  t_process_list	*process;
  int			ascii_code;
  int			arg;

  (void)(raw1);
  process = (t_process_list *)raw2;
  arg = process->current_operator_args[0];
  ascii_code = get_in_register(process, arg) % 256;
  my_putchar(ascii_code, 1);
}

void			instruction_zjmp(void *raw1, void *raw2)
{
  t_process_list	*process;
  int			index;

  (void)(raw1);
  process = (t_process_list *)raw2;
  index = process->current_operator_args[0] % IDX_MOD;
  if (!process->carry)
    return ;
  process->current_offset = get_offset_at_new_addr(process, index);
}

void			instruction_fork(void *raw1, void *raw2)
{
  t_context		*context;
  t_process_list	*process;
  t_process_list	*new_process;
  int			index;

  context = (t_context *)raw1;
  process = (t_process_list *)raw2;
  index = process->current_operator_args[0] % IDX_MOD;
  new_process = make_process(context, process->id_champion,
	       process->name_champion, get_offset_at_new_addr(process, index));
  copy_process_state(process, new_process);
}
