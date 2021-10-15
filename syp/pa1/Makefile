TARGET=minishell
CC=gcc
OBJS=minishell.o
$(TARGET):	$(OBJS)
	$(CC) -o $@ $^
$(OBJS):	minishell.c
	$(CC) -c minishell.c
clean:
	rm *.o minishell
