CC = gcc
CFLAGS = -shared -fPIC
LIBS = $(shell python3-config --ldflags)

SRC = add.c
OBJ = $(SRC:.c=.o)
TARGET = addnums.so

.PHONY: all clean check

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(LIBS) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) $(shell python3-config --includes) -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)

check:
	@echo "Running checks..."
