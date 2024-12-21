CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../src

LIBS = ../src/binTree/libbinTree.a ../src/hashmap/libhashmap.a \
	   ../src/linkedList/liblinkedList.a ../src/vector/libvector.a
TESTS = test_linkedList

TEST_SOURCES = $(patsubst %,%.c,$(TESTS))

.PHONY: all clean check

all: $(TESTS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $< $(LIBS) -lcriterion

check: all
	@for test in $(TESTS); do \
		echo "Running $$test..."; \
		./$$test; \
	done

clean:
	rm -f $(TESTS)