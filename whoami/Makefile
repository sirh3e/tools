WORK_DIR	:= $(shell pwd)

BIN_DIR		:= $(WORK_DIR)/bin
BIN_NAME	:= $(notdir $(WORK_DIR))

TARGET		:= $(BIN_DIR)/$(BIN_NAME)

CC		:= gcc
CFLAGS	:= -std=c99 -O3 -Wall -Wextra -Wno-unused-parameter

.PHONY: all

.PHONY: all
all: prepare
	$(CC) $(CFLAGS) -o $(TARGET) main.c

.PHONY: prepare
prepare:
	mkdir -pv $(BIN_DIR)

.PHONY: clean
clean:
	rm $(TARGET)