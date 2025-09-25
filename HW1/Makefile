CC := gcc
CFLAGS := -Wall -Wextra -O2

BUILD_DIR := build

SRC := $(wildcard *.c)
BIN := $(SRC:.c=)
EXE := $(SRC:%.c=$(BUILD_DIR)/%)

.PHONY: all format clean

all:
	@mkdir -p $(BUILD_DIR)
	gcc $(SRC) -o $(EXE)

format:
	find . -name $(BUILD_DIR) -type d \! -prune -o -iname '*.h' -o -iname '*.c' | xargs clang-format -i

clean:
	rm -rf $(BUILD_DIR)