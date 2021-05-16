##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make the lib
##

NAME		=	libstring.a

SRC			=	string.c	\
				append.c	\
				compare.c	\
				find.c	\
				to_int.c

CRITNAME	=	unit_test

LDFLAGS		=	-L. -lstring

CRITERION	=	-lcriterion --coverage

TEST		=	./tests/test.c

TEMP		=	*.gcno	\
			*.gcda

all:	$(NAME)

$(NAME):
		gcc -c -std=gnu11 -Wall -Wextra $(SRC)
		ar rc $(NAME) *.o

tests_run:
		gcc -o  $(CRITNAME) $(SRC) $(TEST) $(LDFLAGS) $(CRITERION)
		./unit_test

clean:
		rm -f *.o

fclean:	clean
		rm -f $(CRITNAME) $(NAME) $(TEMP)

re:		fclean all
.PHONY:		all clean fclean re