CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -std=c++17 -O3 -lstdc++
COVERAGE = -fprofile-arcs -ftest-coverage
SRC_FILES=*.cc
TEST_FILES=test.cc
UNAME_S := $(shell uname -s)
STYLE=-style=Google

ifeq ($(UNAME_S),Linux)
    TEST_FLAGS=-pthread $$(pkg-config --cflags --libs gtest) -lgcov
	IGNORES=
	OPEN = xdg-open
endif
ifeq ($(UNAME_S),Darwin)
    TEST_FLAGS=-pthread -lgtest -lgtest_main -lgmock
	IGNORES= --ignore-errors usage,usage --ignore-errors inconsistent
	OPEN = open
endif


all: clean gcov_report

test: test.o s21_matrix_oop.a
	$(CXX) $(CXXFLAGS) test.o s21_matrix_oop.a $(TEST_FLAGS) -o test.out
	./test.out

test.o: test.cc
	$(CXX) $(CXXFLAGS) $(COVERAGE) $(TEST_FLAGS) -c test.cc
	
s21_matrix_oop.a:
	$(CXX) $(CXXFLAGS) $(COVERAGE) -c $(SRC_FILES)
	ar rcs s21_matrix_oop.a *.o

gcov_report: clean s21_matrix_oop.a test.o
	$(CXX) $(CXXFLAGS) $(COVERAGE) test.o s21_matrix_oop.a $(TEST_FLAGS) -o test.out
	./test.out
	gcov $(SRC_FILES) $(TEST_FILES)
	lcov -t "s21_test" -o s21_test.info -c -d . $(IGNORES) --no-external
	genhtml -o report s21_test.info
	make remove_files
	$(OPEN) report/index.html

remove_files:
	rm -rf *.out *.o *.gcno *.info s21_matrix_oop.a *.gcda *.a *.o *.txt *.gcov
clean: 
	make remove_files
	rm -rf report 
	rm -rf test
leaks: 
	leaks -atExit --  ./test
clang-format:
	clang-format $(STYLE) -i *.cc *.cc *.h
valgrind:
	valgrind --tool=memcheck --leak-check=yes ./test.out
