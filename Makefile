##
## Makefile for corewar in /home/jeremy/Desktop/corewar
## 
## Made by Jérémy Sid Idris
## Login   <jeremy.sid-idris@epitech.eu>
## 
## Started on  Thu Mar 23 01:04:35 2017 Jérémy Sid Idris
## Last update Thu Mar 23 01:04:35 2017 Jérémy Sid Idris
##

NAME_ASM	=	asm
NAME_COREWAR	=	corewar

all: $(NAME_ASM) $(NAME_COREWAR)

$(NAME_ASM):
	make -C $(NAME_ASM)

$(NAME_COREWAR):
	make -C $(NAME_COREWAR)

clean:
	make clean -C $(NAME_ASM)
	make clean -C $(NAME_COREWAR)

fclean:
	make fclean -C $(NAME_ASM)
	make fclean -C $(NAME_COREWAR)

re: fclean all

.PHONY: all clean fclean re $(NAME_ASM) $(NAME_COREWAR)
