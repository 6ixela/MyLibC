CC = gcc
CFLAGS = -Wall -Wextra -Werror

SUBDIRS = linkedList binTree hashmap vector string

OBJ = $(patsubst %, %/%.o, $(SUBDIRS))
.PHONY: all clean

all: $(OBJ)

$(OBJ):
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir all; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done