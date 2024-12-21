CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = linkedList.c
OBJ = $(SRC:.c=.o)
LIB = liblinkedList.a

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(LIB)