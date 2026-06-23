CC = gcc 
CFLAGS = -Wall -Wextra -Iinclude

SRCS = main.c src/dlistas.c #anadir proximos archivos
OBJS = $(SRCS:.c=.o)

programa: $(OBJS)
	$(CC) $(CFLAGS) -o programa $(OBJS)

%.o: %.CC
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f programa *.o