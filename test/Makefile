override CFLAGS += -Wall -Wextra -Wpedantic -Werror -O3
override CXXFLAGS += -Wall -Wextra -Wpedantic -Werror -O3

.PHONY: test
test: lang_c lang_cpp

.PHONY: lang_c
lang_c: generated-test-vectors.h test.c
	$(CC) $(CFLAGS) -o bin/run_c_test test.c
	./bin/run_c_test

.PHONY: lang_cpp
lang_cpp: generated-test-vectors.h test.cpp
	$(CXX) $(CXXFLAGS) -o bin/run_cpp_test test.cpp
	./bin/run_cpp_test
