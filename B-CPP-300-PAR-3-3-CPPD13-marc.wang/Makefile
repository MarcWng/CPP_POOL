##
## EPITECH PROJECT, 2020
## B-CPP-300-PAR-3-3-CPPD13-marc.wang
## File description:
## Makefile
##

RM      =       rm -rf

all:
	make -C ex00/
	make -C ex01/
	make -C ex02/
	make -C ex03/
	make -C ex04/
	make -C ex05/

tests_run:
	make -C ex00 tests_run
	make -C ex01 tests_run
	make -C ex02 tests_run
	make -C ex03 tests_run
	make -C ex04 tests_run
	make -C ex05 tests_run

clean:
	make clean -C ex00/
	make clean -C ex01/
	make clean -C ex02/
	make clean -C ex03/
	make clean -C ex04/
	make clean -C ex05/

fclean:         clean
	make fclean -C ex00/
	make fclean -C ex01/
	make fclean -C ex02/
	make fclean -C ex03/
	make fclean -C ex04/
	make fclean -C ex05/

re:	fclean all
