CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = queue
SRC = $(queue).c
OBJ = $(SRC:.c=.o)
LIB = lib$(queue).a

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(LIB)