# Makefile for lab10

project: project.o projfunc.o
	gcc project.o projfunc.o gfx.o -lX11 -lm -o project

projfunc.o: projfunc.c projfunc.h
	gcc -c projfunc.c -lm -o projfunc.o 

project.o: project.c projfunc.h
	gcc -c project.c -lm -o project.o	

clean:
	rm project
	rm project.o 
	rm projfunc.o

