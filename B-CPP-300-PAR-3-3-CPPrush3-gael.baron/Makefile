##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Gael Baron's Makefile
##

SRC	=	srcMenu/Menu.cpp		\
		srcSFML/mainSFML.cpp		\
		srcSFML/Cases.cpp		\
		srcSFML/add.cpp			\
		src/modules/BaseInfo.cpp	\
		src/modules/Hostname.cpp	\
		src/modules/InfoManager.cpp	\
		src/modules/OS_name.cpp		\
		src/modules/Time.cpp		\
		src/modules/MonitorCore.cpp	\
		src/modules/RAM.cpp		\
		src/modules/Network.cpp		\
		srcNCURSES/start.cpp		\
		srcNCURSES/win.cpp		\

OBJ	=	$(SRC:.cpp=.o)

CSFLAGS	=	-l sfml-graphics -l sfml-audio -l sfml-system -l sfml-window -lncurses

NAME	=	MyGKrellm

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CSFLAGS)

all:	$(NAME)

debug:	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CSFLAGS) -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     clean all

.PHONY: all clean fclean re
