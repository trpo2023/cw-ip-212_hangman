CC = g++
CXXFLAGS = -Wall -Wextra -Werror

OUT = main_executable
TESTOUT = test_executable

LIB = src/libhangman
MAIN = src/hangman

.PHONY: all test clean format run trun

all: bin/$(OUT)

bin/$(OUT): bin/$(MAIN)/main.o  bin/$(LIB)/libhangman.a
	$(CC) $^ -o $@ $(CXXFLAGS) -I $(LIB)/

bin/$(LIB)/libhangman.a: bin/$(LIB)/DrawHangman.o bin/$(LIB)/GetCurrentWord.o bin/$(LIB)/GetRandomWord.o
	ar rcs $@ $^ 

bin/$(LIB)/DrawHangman.o: $(LIB)/DrawHangman.cpp
	$(CC) -c $< -o $@ $(CXXFLAGS) -I $(LIB)/

bin/$(LIB)/GetCurrentWord.o: $(LIB)/GetCurrentWord.cpp
	$(CC) -c $< -o $@ $(CXXFLAGS) -I $(LIB)/

bin/$(LIB)/GetRandomWord.o: $(LIB)/GetRandomWord.cpp
	$(CC) -c $< -o $@ $(CXXFLAGS) -I $(LIB)/

bin/$(MAIN)/main.o: $(MAIN)/main.cpp
	$(CC) -c $< -o $@ $(CXXFLAGS) -I $(LIB)/

test: bin/$(OUT) bin/$(TESTOUT)

bin/$(TESTOUT): bin/tests/main.o bin/tests/tests.o bin/$(LIB)/DrawHangman.o bin/$(LIB)/GetCurrentWord.o bin/$(LIB)/GetRandomWord.o
	$(CC) $(CFLAGS) $^ -o $@ -I $(LIB)/

bin/tests/main.o: tests/main.c
	$(CC) -c $(CFLAGS) $< -o $@ -I thirdparty -I $(LIB)/

bin/tests/tests.o: tests/tests.cpp
	$(CC) -c $(CFLAGS) $< -o $@ -I thirdparty -I $(LIB)/

OBJSRCH := $(shell find . -type f -name "*.o")
LIBSRCH := $(shell find . -type f -name "*.a")

clean:
	rm -f bin/$(OUT) bin/$(TESTOUT) $(OBJSRCH) $(LIBSRCH)

SRCS := $(shell find . -type f -name "*.c")
SXXRCS := $(shell find . -type f -name "*.cpp")
HDRS := $(shell find . -type f -name "*.h")

format:
	clang-format -i $(SRCS) $(SXXRCS) $(HDRS)

run:
	cd bin && ./$(OUT)

trun:
	cd bin && ./$(TESTOUT)