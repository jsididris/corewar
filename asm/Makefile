##
## Makefile for corewar in /home/jeremy/Desktop/corewar/assembler
## 
## Made by Jérémy Sid Idris
## Login   <jeremy.sid-idris@epitech.eu>
## 
## Started on  Tue Mar 21 02:02:37 2017 Jérémy Sid Idris
## Last update Tue Mar 21 02:02:37 2017 Jérémy Sid Idris
##

CC	=	gcc

SRC	=	src/helpers/string.c		\
		src/helpers/string_2.c		\
		src/helpers/string_3.c		\
		src/helpers/number.c		\
		src/helpers/array.c		\
		src/helpers/list.c		\
		src/helpers/output.c		\
		src/helpers/name.c		\
		src/helpers/secure_malloc.c	\
		src/helpers/endianness.c	\
		src/utils/get_next_line.c	\
		src/types/label.c		\
		src/types/register.c		\
		src/types/direct.c		\
		src/types/indirect.c		\
		src/header.c			\
		src/instruction.c		\
		src/args.c			\
		src/operator.c			\
		src/validator.c			\
		src/analyzer.c			\
		src/token.c			\
		src/file.c			\
		src/main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

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
