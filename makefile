CC = gcc
AR = ar
FLAGS = -Wall -g

# $@ - the file on the left side of the :
# $< - the first name in the dependencies list
# $^ - the right side of :

all: txtfind isort
txtfind: mainf.o textfind.o
	$(CC) $(FLAGS) -o $@ $^
isort: mains.o isort.o
	$(CC) $(FLAGS) -o $@ $^
textfind.o: textfind.c textfind.h
	$(CC) $(FLAGS) -fPIC -c $<
mainf.o: mainf.c textfind.h
	$(CC) $(FLAGS) -c $<
isort.o: isort.c isort.h
	$(CC) $(FLAGS) -fPIC -c $<
mains.o: mains.c isort.h
	$(CC) $(FLAGS) -c $<

.PHONY: clean all

clean:
	rm -f *.o *.a *.so txtfind isort
