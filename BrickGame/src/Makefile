CC = gcc -Wall -Werror -Wextra -std=c11
PP= gcc -Wall -Werror -Wextra -std=c++17
UNAME_S := $(shell uname -s)
EXCLUDE_FLAGS1 = --exclude '*/gui/*'
EXCLUDE_FLAGS2 = --exclude '*/tests/*'

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

ifeq ($(shell uname), Linux)
  FLAGS = -lcheck -lsubunit -lm 
else
  FLAGS = -lcheck
endif

all: install gcov_report

install:  uninstall clean frontend main.o backend
	$(PP) main.o frontend.o frontend_tetris.o backend_tetris.a frontend_snake.o backend_snake.a backend.o -lncurses -lstdc++ -o bin/game
	rm -rf *.o *.a 

uninstall:
	rm -rf bin/game

gcov_report: clear_Highscore
	gcc -Wall -Werror -Wextra -std=c11 -c --coverage ./gui/cli/tetris/frontend_t.c $(TEST_FLAGS) -lncurses -o frontend_t.o
	gcc -Wall -Werror -Wextra -std=c11 -c --coverage ./brick_game/tetris/backend_t.c $(TEST_FLAGS) -lncurses -o backend_t.o
	gcc -Wall -Werror -Wextra -std=c++17 --coverage ./gui/cli/snake/frontend_s.cpp ./tests/test.cpp backend_t.o frontend_t.o ./brick_game/snake/backend_s.cpp $(TEST_FLAGS) -lstdc++ -lncurses -lm -o test.out
	./test.out
	lcov -t "test.out" -o test.info -c -d .  $(EXCLUDE_FLAGS1) $(EXCLUDE_FLAGS2) --no-external
	genhtml -o report test.info
	open ./report/index.html
	rm -rf *.gcno *.gcda *.info  *.o test.out

test:clear_Highscore test.o backend frontend
	$(PP) test.o backend_snake.a backend_tetris.a frontend_snake.o frontend_tetris.o $(TEST_FLAGS) -lncurses -lstdc++ -lm -o test.out
	rm -rf *.o *.a
	./test.out

desktop: clean
	cd bin && rm -rf desk && mkdir desk
	cd bin/desk && qmake6 ../../gui/desktop
	cd bin/desk && make

memory-check:clear_Highscore test.o backend frontend
	$(PP) test.o backend_snake.a backend_tetris.a frontend_snake.o frontend_tetris.o $(TEST_FLAGS) -lncurses -lstdc++ -lm -o test.out
	rm -rf *.o *.a
ifeq ($(shell uname), Linux)
	@valgrind --tool=memcheck --leak-check=yes --leak-check=full --show-leak-kinds=all ./test.out
else
	@leaks -atExit -- ./test.out | grep LEAK:
endif

clean: uninstall
	rm -rf *.o *.a *.gcda *.gcdo *.gcno  report *.tar *.out bin/desk

dvi:
	open dvi_snake.md
	open dvi_tetris.md

dist: install
	mkdir archiv
	cp -r brick_game gui main.cpp tests Makefile archiv
	tar -cf brick_game.tar archiv
	rm -rf archiv

style:
	clang-format -style=Google -n gui/cli/snake/*.cpp
	clang-format -style=Google -n gui/cli/tetris/*.c
	clang-format -style=Google -n gui/cli/tetris/*.h
	clang-format -style=Google -n gui/cli/*.cpp
	clang-format -style=Google -n gui/cli/*.hpp
	clang-format -style=Google -n gui/desktop/*.cpp
	clang-format -style=Google -n gui/desktop/*.h
	clang-format -style=Google -n brick_game/tetris/*.c
	clang-format -style=Google -n brick_game/tetris/*.h
	clang-format -style=Google -n brick_game/*.cpp
	clang-format -style=Google -n brick_game/*.hpp
	clang-format -style=Google -n brick_game/snake/*.cpp
	clang-format -style=Google -n brick_game/snake/*.hpp
	clang-format -style=Google -n tests/*.cpp
	clang-format -style=Google -n *.cpp

frontend:
	$(PP) -c ./gui/cli/frontend.cpp -o frontend.o
	$(CC) -c ./gui/cli/tetris/frontend_t.c -o frontend_tetris.o
	$(PP) -c ./gui/cli/snake/frontend_s.cpp -o frontend_snake.o

backend:
	$(CC) -c ./brick_game/tetris/backend_t.c -o backend_tetris.o
	ar rcs backend_tetris.a backend_tetris.o
	ranlib backend_tetris.a
	$(PP) -c ./brick_game/snake/backend_s.cpp -o backend_snake.o
	ar rcs backend_snake.a backend_snake.o
	ranlib backend_snake.a
	$(PP) -c ./brick_game/backend.cpp -o backend.o
	rm -rf backend_tetris.o backend_snake.o

backend.o: 
	$(CC) -c ./brick_game/tetris/backend.c 

main.o:
	$(PP) -c main.cpp -o main.o

test.o:
	$(PP) $(TEST_FLAGS) -c tests/test.cpp

clear_Highscore:
	$(CC) -c ./tests/clear_highScore.c -o ./clear_highScore.o
	$(CC) clear_highScore.o -o ./clear_highScore.out
	./clear_highScore.out
	rm -rf *.o *.out

clang:
	clang-format -style=Google -i gui/cli/snake/*.cpp
	clang-format -style=Google -i gui/cli/tetris/*.c
	clang-format -style=Google -i gui/cli/tetris/*.h
	clang-format -style=Google -i gui/cli/*.cpp
	clang-format -style=Google -i gui/cli/*.hpp
	clang-format -style=Google -i gui/desktop/*.cpp
	clang-format -style=Google -i gui/desktop/*.h
	clang-format -style=Google -i brick_game/tetris/*.c
	clang-format -style=Google -i brick_game/tetris/*.h
	clang-format -style=Google -i brick_game/*.cpp
	clang-format -style=Google -i brick_game/*.hpp
	clang-format -style=Google -i brick_game/snake/*.cpp
	clang-format -style=Google -i brick_game/snake/*.hpp
	clang-format -style=Google -i tests/*.cpp
	clang-format -style=Google -i *.cpp
