CC = gcc
CFLAGS = -Wall -Wextra -g
OBJS = main.o parser.o executor.o builtins.o

all: minishell

minishell: $(OBJS)
	$(CC) $(CFLAGS) -o minishell $(OBJS)

clean:
	rm -f *.o minishell
