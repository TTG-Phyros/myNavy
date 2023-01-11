##
## EPITECH PROJECT, 2023
## navy
## File description:
## Makefile
##

NAME			=				navy

CFLAGS			=				-W -Wall -Werror

SRC				=		./src/main.c				\

OBJ				=				$(SRC:.c=.o)

all:    $(OBJ)
		gcc -g3 $(OBJ) -o $(NAME) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:     fclean all
