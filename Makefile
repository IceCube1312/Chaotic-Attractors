CC = gcc
CFLAGS = -Wall -lraylib -lm

lorenz: main.c lorenz.c
	$(CC) main.c lorenz.c -o lorenz $(CFLAGS)
	$(CC) main.c lorenz.c -D HALVORSEN -o halvorsen $(CFLAGS)

clean:
	rm -f lorenz halvorsen
