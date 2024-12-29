CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../src

GREEN = \033[0;32m
CYAN = \033[0;36m
MAGENTA = \033[0;35m
RESET = \033[0m

OBJ = ../src/binTree/binTree.o ../src/hashmap/hashmap.o \
	   ../src/linkedList/linkedList.o ../src/vector/vector.o \
	   ../src/string/string.o
TESTS = test_linkedList test_string

TEST_SOURCES = $(patsubst %,%.c,$(TESTS))

.PHONY: all clean check

all: $(TESTS) $(OBJ)

%: %.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ $< $(OBJ) -lcriterion

check: all $(OBJ)
	@for test in $(TESTS); do \
		echo "$(MAGENTA)Running $$test$(RESET)"; \
		./$$test; \
	done

clean:
	rm -f $(TESTS)