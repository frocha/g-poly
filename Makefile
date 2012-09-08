# Makefile for testing GFinder

test-g-finder: g-finder.o g-surffinder.o test-g-finder.o
	$(CC) -o test-g-finder test-g-finder.o g-finder.o g-surffinder.o `pkg-config --libs gobject-2.0`

g-finder.o: g-finder.c g-finder.h
	$(CC) -c g-finder.c -g -Wall `pkg-config --cflags gobject-2.0`

g-surffinder.o: g-surffinder.c g-surffinder.h g-finder.h
	$(CC) -c g-surffinder.c -g -Wall `pkg-config --cflags gobject-2.0`

test-g-finder.o: test-g-finder.c g-finder.h
	$(CC) -c test-g-finder.c -g -Wall `pkg-config --cflags gobject-2.0`

clean:
	rm -f *.o *~ core
