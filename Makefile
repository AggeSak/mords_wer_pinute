CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic
LDLIBS = -lncurses

hello_world: hello_world.c
	$(CC) $(CFLAGS) hello_world.c $(LDLIBS) -o hello_world

docs:
	doxygen Doxyfile

clean:
	rm -f hello_world

docs-clean:
	rm -rf html latex
