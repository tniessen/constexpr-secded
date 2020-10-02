override CFLAGS += -Wall -Wextra -Wpedantic -Werror -O3

.PHONY: test
test: generated-test-vectors.h test.c
	$(CC) $(CFLAGS) -o run_test test.c
	./run_test
