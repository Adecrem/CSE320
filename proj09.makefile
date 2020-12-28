proj09: proj09.support.o proj09.driver.o
	gcc proj09.support.o proj09.driver.o -o proj09

proj09.support.o: proj09.support.s
	gcc -march=native -c proj09.support.s

proj09.driver.o: proj09.driver.c project09.support.h
	gcc -Wall -c proj09.driver.c
