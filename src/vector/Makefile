CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = vector.c
OBJ = $(SRC:.c=.o)
LIB = libvector.a

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(LIB)