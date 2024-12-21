CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = hashmap.c
OBJ = $(SRC:.c=.o)
LIB = libhashmap.a

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(LIB)