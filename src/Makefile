CC = gcc
CFLAGS = -Wall -Wextra -Werror

SUBDIRS = linkedList binTree hashmap vector

LIBRARIES = $(patsubst %, %/lib%.a, $(SUBDIRS))

.PHONY: all clean

all: $(LIBRARIES)

$(LIBRARIES):
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir all; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done