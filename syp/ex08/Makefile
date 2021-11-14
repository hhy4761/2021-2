TARGET=ex08
CC=gcc
OBJS=ex08.o
$(TARGET):	$(OBJS)
			  $(CC) -o $@ $^
$(OBJS):	ex08.c
			$(CC) -c ex08.c
clean:
		rm *.o ex08
