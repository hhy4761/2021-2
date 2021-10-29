TARGET=W9
CC=gcc
OBJS=w9.o

$(TARGET):	$(OBJS)
			  $(CC) -o $@ $^
$(OBJS):	w9.c
			$(CC) -c w9.c
clean:
		rm *.o W9
