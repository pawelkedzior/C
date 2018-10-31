cc=gcc
CFLAGS=-Wall
OBJS=add.o main.o
add: $(OBJS)
	$(CC) -o add main.o add.o
main.o: main.c
	$(CC) -c main.c -o main.o
add.o: add.c
	$(CC) -c add.c -o add.o
clean:
	rm -f *.o add
