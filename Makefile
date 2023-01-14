##
## EPITECH PROJECT, 2023
## navy
## File description:
## Makefile
##

NAME			=				navy

CFLAGS			=				-W -Wall

SRC				=		./src/main.c				\
						./src/connection.c			\
						./src/int_manipulation.c	\
						./src/file_gestion.c		\
						./src/signal_handling.c		\
						./src/error_handling.c		\
						./src/str_manipulation.c	\
						./src/game.c				\
						./src/map.c					\

OBJ				=				$(SRC:.c=.o)

all:    $(OBJ)
		gcc -g3 $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:     fclean all
