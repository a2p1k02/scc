CC = gcc
CFLAGS = 
LDFLAGS +=
BUILD = build
INC = -I./include
SRC_DIR = src
SOURCES = $(wildcard $(SRC_DIR)/*.c)
EXECUTABLE_NAME = scc
OBJ = $(SOURCES:.c=.o)
OUTPUT = $(EXECUTABLE_NAME)

$(OUTPUT): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OUTPUT) src/*.o

