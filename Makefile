CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99 -Isrc

SUBDIRS = src/binTree src/hashmap src/linkedList src/vector

LIBRARIES = src/binTree/libbinTree.a src/hashmap/libhashmap.a src/linkedList/liblinkedList.a src/vector/libvector.a
SRC_DIR = src
TEST_DIR = tests


.PHONY: all clean check

all: $(LIBRARIES)

$(LIBRARIES):
	$(MAKE) -C src

check: $(LIBRARIES)
	$(MAKE) -C $(TEST_DIR) check

clean:
	$(MAKE) -C $(SRC_DIR) clean
	$(MAKE) -C $(TEST_DIR) clean