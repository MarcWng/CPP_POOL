##
## EPITECH PROJECT, 2020
## B-CPP-300-PAR-3-3-CPPD09-marc.wang
## File description:
## Makefile
##

NOMAIN	=	tests/test.cpp	\
			Box.cpp	\
			GiftPaper.cpp	\
			Objects.cpp	\
			Toys.cpp	\
			Wrap.cpp	\
			ConvoyerBelt.cpp	\
			Table.cpp	\
			IElf.cpp	\


CC	=	g++

NAME	=	exec

CRITNAME =	unit_test

CRITERION =	-lcriterion --coverage

OBJ	=	$(SRC:.cpp=.o)

OBJ_TEST=	$(NOMAIN:.cpp=.o)

TEST	=	./tests/test.cpp

TEMP     =	*.gcno	\
			*.gcda

all	:	$(CRITNAME)

$(CRITNAME)	:	$(OBJ_TEST)

tests_run:	$(OBJ_TEST)
		$(CC) -o $(CRITNAME) $(NOMAIN) $(CRITERION)
		./unit_test

debug	:	CFLAGS += -g3
debug	:	re

err	:	CFLAGS += -Wall -Werror -Wextra
err	:	re

clean	:
		rm -f $(OBJ_TEST)
		rm -f $(TEMP)

fclean	:	clean
		rm -f $(CRITNAME)

re	:	fclean all

.PHONY	:	all clean fclean re
