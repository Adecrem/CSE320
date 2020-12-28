run: proj06.driver.o
	gcc proj06.driver.o -o run
proj06.driver.o: proj06.driver.c proj06.support.c
	gcc -Wall -c proj06.driver.c proj06.support.c
