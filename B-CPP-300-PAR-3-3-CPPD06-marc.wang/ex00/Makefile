##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	$(wildcard *.cpp)

NOMAIN	=	tests/test.cpp	\

NAME	=	my_cat

CRITNAME =	unit_test

CPPFLAGS =	-I ./include

CRITERION =	-lcriterion --coverage

CFLAGS	+=	-Wall -Werror -Wextra

OBJ	=	$(SRC:.cpp=.o)

OBJ_TEST=	$(NOMAIN:.cpp=.o)

TEST	=	./tests/test.cpp

TEMP     =	*.gcno	\
		*.gcda

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		g++ $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)

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
