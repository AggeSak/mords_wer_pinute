CC = gcc

CFLAGS = -std=c17 -Wall -Wextra -Wpedantic
LDLIBS = -lncurses -lpanel

TARGET = build/mords_wer_pinute
SRC = source/main.c

.PHONY: all run docs clean docs-clean

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) $(LDLIBS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

docs:
	doxygen Doxyfile

clean:
	rm -rf build

docs-clean:
	rm -rf html latex
