/*
** label.c for corewar in /home/jeremy/Desktop/corewar/asm/src
** 
** Made by Jérémy Sid Idris
** Login   <jeremy.sid-idris@epitech.eu>
** 
** Started on  Sat Mar 25 16:03:56 2017 Jérémy Sid Idris
** Last update Sat Mar 25 16:03:56 2017 Jérémy Sid Idris
*/

#include <stdlib.h>
#include "helpers/secure_malloc.h"
#include "helpers/string.h"
#include "helpers/output.h"
#include "helpers/list.h"
#include "helpers/array.h"
#include "assembler.h"
#include "types/label.h"

void	validate_label(t_file *f, int type, char *label)
{
  int	i;
  int	max;
  int	x;
  char	*name;

  if (len(label) <= 1)
    exit(put_parsing_error(f, "Label must contain name"));
  x = 0;
  i = (type == LABEL_USAGE ? 1 : 0);
  max = (type == LABEL_DECLARATION ? len(label) - 1 : len(label));
  name = secure_malloc(sizeof(char) * len(label));
  while (i < max)
    {
      if (!exist_in_string_array(label[i], LABEL_CHARS))
	exit(put_parsing_error(f, "Forbidden character in label name"));
      name[x] = label[i];
      i = i + 1;
      x = x + 1;
    }
  name[x] = '\0';
  if (type == LABEL_USAGE)
    return (put_in_list(&f->label_usage_list, name, f->line, f->offset));
  else if (name_occurence_in_list(name, f->label_def_list) >= 1)
    exit(put_parsing_error(f, "Multiple definition of label"));
  put_in_list(&f->label_def_list, name, f->line, f->offset);
}

void		validate_label_usages(t_file *file)
{
  t_labels_list	*tmp;

  tmp = file->label_usage_list;
  while (tmp != NULL)
    {
      if (name_occurence_in_list(tmp->name, file->label_def_list) == 0)
	exit(put_parsing_error(file, "Undefined label"));
      tmp = tmp->next;
    }
}

int		get_label(t_file *file, char *name)
{
  t_labels_list	*tmp;

  tmp = file->label_def_list;
  while (tmp != NULL)
    {
      if (my_strcmp(name, tmp->name) == 0)
	return (tmp->offset - file->offset_instruction);
      tmp = tmp->next;
    }
  return (0);
}
