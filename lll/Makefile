CC=gcc
BIN=g.bin
STD=-std=gnu99
FLAG=-Wall -Werror
OBJ=head.o main.o student.o teacher.o tools.o

all:$(OBJ)
	$(CC) -o $(BIN) $(OBJ)
main.o:main.c head.h student.h teacher.h tools.h
	$(CC) $(STD) $(FLAG) -c main.c
head.o:head.c head.h tools.h
	$(CC) $(STD) $(FLAG) -c head.c
student.o:student.c student.h tools.h
	$(CC) $(STD) $(FLAG) -c student.c
teacher.o:teacher.c teacher.h tools.h
	$(CC) $(STD) $(FLAG) -c teacher.c
tools.o:tools.c tools.h
	$(CC) $(STD) $(FLAG) -c tools.c

clean:
	rm -rf $(OBJ) $(BIN)
	rm -rf *~

