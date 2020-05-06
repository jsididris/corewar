##
## Makefile for corewar in /home/jeremy/Desktop/corewar/corewar
## 
## Made by Jérémy Sid Idris
## Login   <jeremy.sid-idris@epitech.eu>
## 
## Started on  Mon Mar 27 04:09:15 2017 Jérémy Sid Idris
## Last update Mon Mar 27 04:09:15 2017 Jérémy Sid Idris
##

CC	=	gcc

SRC	=	src/helpers/string.c		\
		src/helpers/string_2.c		\
		src/helpers/string_3.c		\
		src/helpers/number.c		\
		src/helpers/array.c		\
		src/helpers/list.c		\
		src/helpers/list_2.c		\
		src/helpers/output.c		\
		src/helpers/secure_malloc.c	\
		src/helpers/endianness.c	\
		src/instructions/manage.c	\
		src/instructions/arithmetic.c	\
		src/instructions/long.c		\
		src/instructions/misc.c		\
		src/offset.c			\
		src/validation.c		\
		src/operator.c			\
		src/args.c			\
		src/args_type.c			\
		src/memory.c			\
		src/cycle.c			\
		src/register.c			\
		src/process.c			\
		src/champion.c			\
		src/context.c			\
		src/optimal.c			\
		src/dump.c			\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

CFLAGS	=	-Wextra -Wall -Werror -Iinclude/

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

.PHONY: all clean fclean re
