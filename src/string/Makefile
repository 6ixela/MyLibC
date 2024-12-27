CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME=string
SRC = $(NAME).c
OBJ = $(SRC:.c=.o)
LIB = lib$(NAME).a

.PHONY: all clean

all: $(LIB)

$(LIB): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(LIB)