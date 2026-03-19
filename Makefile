CC      = gcc
CFLAGS  = -Wall -Wextra -g

# ── Targets ────────────────────────────────────────────────────────────────────
.PHONY: all build test clean

all: build

## Build the main program
build: two_sum

two_sum: two_sum.c
	$(CC) $(CFLAGS) -o two_sum two_sum.c

## Build and run all tests
test: test_two_sum
	./test_two_sum

test_two_sum: two_sum.c test_two_sum.c
	$(CC) $(CFLAGS) \
	    -DTESTING \
	    -o test_two_sum \
	    two_sum.c test_two_sum.c

## Remove generated binaries
clean:
	rm -f two_sum test_two_sum