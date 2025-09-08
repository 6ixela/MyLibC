CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99 -Isrc

SUBDIRS = src/binTree src/hashmap src/linkedList src/vector src/string

OBJ = src/binTree/binTree.o src/hashmap/hashmap.o \
			src/linkedList/linkedList.o src/vector/vector.o \
			src/string/string.o \
			src/hashmap/hash.o
SRC_DIR = src
TEST_DIR = tests


.PHONY: all clean check test

all: $(OBJ)

$(OBJ):
	$(MAKE) -C src

check: $(OBJ)
	@echo "Call Makefile test directory"
	$(MAKE) -C $(TEST_DIR) check

test: CFLAGS += -g -fsanitize=address
test: LDFLAGS += -fsanitize=address
test: $(OBJ) main.o
	@echo "Create binary"
	$(CC) $(LDFLAGS) $(CFLAGS) $^ -o $@

clean:
	$(MAKE) -C $(SRC_DIR) clean
	$(MAKE) -C $(TEST_DIR) clean
	$(RM) main.o test