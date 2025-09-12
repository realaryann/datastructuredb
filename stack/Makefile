CC = g++
FLAGS = --pedantic -Wall -Werror

all: stack

stack: stack.cpp stack.hpp
	$(CC) $(FLAGS) -o stack $^

clean:
	rm stack