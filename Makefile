CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c99 -Iinclude
LDFLAGS =

LIB_NAME = myLibC.a

SRC_DIR = src
BUILD_DIR = build
TEST_DIR = tests

SRC_FILES := $(wildcard $(SRC_DIR)/*/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
TEST_FILES := $(wildcard $(TEST_DIR)/*.c)

.PHONY: all clean check

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_FILES)
	ar rcs $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
# put @echo color
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

check: $(LIB_NAME)
	$(CC) $(CFLAGS) -o testsuite $(TEST_FILES) $(LIB_NAME) -lcriterion
	./testsuite

clean:
	$(RM) -r $(BUILD_DIR) $(LIB_NAME)
	$(RM) testsuite

