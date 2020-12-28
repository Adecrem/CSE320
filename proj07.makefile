proj07: proj07.support.o project07.driver.o
	gcc proj07.support.o project07.driver.o -o proj07

proj07.support.o: proj07.support.c project07.hardware.h
	gcc -Wall -c proj07.support.c
