CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99 -Isrc

SUBDIRS = src/binTree src/hashmap src/linkedList src/vector src/string

OBJ = src/binTree/binTree.o src/hashmap/hashmap.o \
			src/linkedList/linkedList.o src/vector/vector.o \
			src/string/string.o
SRC_DIR = src
TEST_DIR = tests


.PHONY: all clean check

all: $(OBJ)

$(OBJ):
	$(MAKE) -C src

check: $(OBJ)
	@echo "Call Makefile test directory"
	$(MAKE) -C $(TEST_DIR) check

clean:
	$(MAKE) -C $(SRC_DIR) clean
	$(MAKE) -C $(TEST_DIR) clean