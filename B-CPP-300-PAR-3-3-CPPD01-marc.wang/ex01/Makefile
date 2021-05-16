##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	$(wildcard *.c)

NOMAIN	=	tests/test.c	\

CC	=	cc

NAME	=	menger

CRITNAME =	unit_test

CPPFLAGS =	-I ./include

CRITERION =	-lcriterion --coverage

CFLAGS	+=	-std=gnu11 -Wall -Werror -Wextra

LIB	=	-lm

OBJ	=	$(SRC:.c=.o)

OBJ_TEST=	$(NOMAIN:.c=.o)

TEST	=	./tests/test.c

TEMP     =	*.gcno	\
		*.gcda

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

tests_run:	$(OBJ)
		gcc -o $(CRITNAME) $(NOMAIN) $(CRITERION) $(CPPFLAGS)
		./unit_test

debug	:	CFLAGS += -g3
debug	:	re

clean	:
		rm -f $(OBJ)
		rm -f $(TEMP)

fclean	:	clean
		rm -f $(NAME) $(CRITNAME)

re	:	fclean all

.PHONY	:	all clean fclean re
