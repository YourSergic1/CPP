CC = gcc
CFLAGS = -std=c++17 -Wall -Werror -Wextra
STYLE=-style=Google
UNAME_S := $(shell uname -s)
EXCLUDE_FLAGS1 = --exclude '*/RedBlackTreeForSet/*'
EXCLUDE_FLAGS2 = --exclude '*/RedBlackTreeForMap/*'

ifeq ($(UNAME_S),Linux)
	OPEN = open
	MEMORY = valgrind --tool=memcheck --leak-check=yes
	TEST_FLAGS=-pthread $(pkg-config --cflags --libs gtest gmock) -lgcov
endif
ifeq ($(UNAME_S),Darwin)
	OPEN = open
	MEMORY = leaks -atExit --
	TEST_FLAGS=-pthread -lgtest -lgtest_main -lgmock
endif

all:clean gcov_report

test: clean
	${CC} ${CСFLAGS} tests/test.cpp -lgtest -lstdc++ -lm  -o test.out
	./test.out

clean:
	@find .. -type f -name "test.out" -exec rm {} \;
	@find .. -type f -name "test_cov.out" -exec rm {} \;
	@find .. -type f -name "*.gcda" -exec rm {} \;
	@find .. -type f -name "*.gcno" -exec rm {} \;
	@find .. -type f -name "*.info" -exec rm {} \;
	@rm -rf report

style:
	clang-format -n $(STYLE) containers/*.h
	clang-format -n $(STYLE) containers/*.tpp
	clang-format -n $(STYLE) containers_plus/*.h
	clang-format -n $(STYLE) RedBlackTreeForSet/*.h
	clang-format -n $(STYLE) tests/*.cpp
	clang-format -n $(STYLE) RedBlackTreeForMap/*.h
	clang-format -n $(STYLE) RedBlackTreeForMap/*.tpp

clang-format:
	clang-format -i $(STYLE) containers/*.h
	clang-format -i $(STYLE) containers/*.tpp
	clang-format -i $(STYLE) containers_plus/*.h
	clang-format -i $(STYLE) RedBlackTreeForSet/*.h
	clang-format -i $(STYLE) tests/*.cpp
	clang-format -i $(STYLE) RedBlackTreeForMap/*.h
	clang-format -i $(STYLE) RedBlackTreeForMap/*.tpp

memory_check: test
	$(MEMORY) ./test.out

gcov_report: clean
	${CC} ${CFLAGS} -coverage -g tests/test.cpp -lgtest -lstdc++ -lm -o test.out
	./test.out
	gcov tests/test.cpp
	lcov -t "s21_test" -o s21_test.info -c -d . $(EXCLUDE_FLAGS1) $(EXCLUDE_FLAGS2) --no-external
	genhtml -o report s21_test.info
	@find .. -type f -name "test.out" -exec rm {} \;
	@find .. -type f -name "test_cov.out" -exec rm {} \;
	@find .. -type f -name "*.gcda" -exec rm {} \;
	@find .. -type f -name "*.gcno" -exec rm {} \;
	@find .. -type f -name "*.info" -exec rm {} \;
	open report/index.html