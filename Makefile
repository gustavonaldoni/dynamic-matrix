EXECUTABLE_NAME = main.out
SOURCE_FILE = src/main.c

LIB_DIR = lib
LIB_FILES = $(wildcard $(LIB_DIR)/*.c)

TEST_DIR = unittests
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)
TEST_FLAGS = --list
TEST_FINAL_FILE = testResults

CC = gcc
CFLAGS = -Wall -Werror

all:
	$(CC) $(SOURCE_FILE) -o build/$(EXECUTABLE_NAME) $(LIB_FILES) $(CFLAGS) -I./include

tests:
	$(CC) $(TEST_FILES) -o $(TEST_DIR)/$(TEST_FINAL_FILE) $(LIB_FILES) $(CFLAGS) -lcriterion -I./include

executetests:
	$(TEST_DIR)/$(TEST_FINAL_FILE)