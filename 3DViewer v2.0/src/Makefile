PP= gcc -Wall -Werror -Wextra -std=c++17 -fPIC
GCOV=-fprofile-arcs -ftest-coverage
SOURCES=tests/tests.cpp 3DViewer/sources/affine_transform.cpp 3DViewer/sources/parser.cpp
QTLIBS=-I/usr/include/x86_64-linux-gnu/qt6 -I/usr/include/x86_64-linux-gnu/qt6/QtOpenGLWidgets -I/usr/include/x86_64-linux-gnu/qt6/QtWidgets -I/usr/include/x86_64-linux-gnu/qt6/QtOpenGL -I/usr/include/x86_64-linux-gnu/qt6/QtGui -I/usr/include/x86_64-linux-gnu/qt6/QtCore
TEST=-pthread -lgcov -lstdc++ -lm -lQt6Core -lQt6Gui -lQt6Widgets -lQt6OpenGL -lQt6OpenGLWidgets -lgtest -lgtest_main
UNAME_S := $(shell uname -s)
EXCLUDE_FLAGS = --exclude '*/tests/*'

ifeq ($(shell uname), Linux)
  MEMORY=valgrind --tool=memcheck --leak-check=yes
else
  MEMORY=leaks -atExit --
endif

all: install

install: uninstall
	mkdir bin
	cd bin && qmake6 ../3DViewer
	cd bin && make

uninstall:
	rm -rf bin

rebuild:
	cd bin && make

dvi:
	open dvi.md

dist: clean install
	rm -rf archiv
	mkdir archiv
	cp -r bin Makefile 3DViewer tests dvi.md screenshots archiv
	tar -cf 3DViewer.tar archiv
	rm -rf archiv

test: clean
	$(PP) $(SOURCES) $(QTLIBS) $(TEST) -o test.out
	rm -rf bin
	./test.out

gcov-report:
	$(PP) $(GCOV) $(SOURCES) $(QTLIBS) $(TEST) -o test.out
	rm -rf bin
	./test.out
	lcov -t "test.out" -o test.info -c -d . $(EXCLUDE_FLAGS) --no-external
	genhtml -o report test.info
	open ./report/index.html
	rm -rf *.gcno *.gcda *.info  *.o test.out

memory-check: test
	$(MEMORY) ./test.out

style:
	clang-format -n 3DViewer/sources/*.cpp
	clang-format -n 3DViewer/headers/*.h
	clang-format -n tests/*.cpp

clean_screencasts:
	cd screenshots && rm -f *.gif *.jpeg *.bmp

clang-format:
	clang-format -i 3DViewer/sources/*.cpp
	clang-format -i 3DViewer/headers/*.h
	clang-format -i tests/*.cpp

clean:
	rm -rf bin
	rm -f test.out
	rm -rf report *.gcno *.gcda *.info  *.o test.out *.tar