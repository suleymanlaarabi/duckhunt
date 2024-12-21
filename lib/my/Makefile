##
## EPITECH PROJECT, 2024
## LibMy
## File description:
## Build and clean the LibMy
##

CC = gcc
CFLAGS= -Wextra -Wall
SRC = $(shell find . -name '*.c')
OBJ := $(SRC:.c=.o)
NAME = libmy.a

all: $(OBJ)
	ar rc libmy.a $(OBJ)

debug_build:
	gcc -c $(SRC)
	ar rc $(NAME) *.o

clean_debug:
	rm -f *.gc*
	rm -f $(OBJ)
	rm -f $(NAME)

clean: clean_debug
	rm -f *.o

fclean: clean
	rm -f libmy.a

re: fclean all
