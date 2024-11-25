#SNAKE

Игрок управляет змейкой, которая непрерывно движется вперед. Игрок изменяет направление движения змейки с помощью стрелок. Цель игры заключается в сборе «яблок», появляющихся на игровом поле. При этом игрок не должен касаться стенок игрового поля. После «поедания» очередного «яблока» длина змейки увеличивается на один. Игрок побеждает, если змейка достигает максимального размера (200 «пикселей»). Если змейка сталкивается с границей игрового поля, то игрок проигрывает.

Проект сделан в функциональном стиле на языке Си++ стандарта с++17. 
Цель данного проекта отработать навык и углубить знания в следующих темах:

- Конечные автоматы
- Работа с матрицами
- Работа с файлами
- Работа с графическими интерфейсами 

В нашем случае интерфейс терминальный с использование библиотеки ncurses и интерфейс на базе фреймворка Qt.

В игре присутствуют следующие механики:

- Вращение змейки
- Поедание "яблок"
- Удлиннение змейки

При нажатии этих клавиш происходят следующие действия:

- **LEFT** - змейка поворачивает налево;
- **RIGHT** - змейка поворачивает направо;
- **DOWN** - змейка поворачивает вниз;
- **UP** - змейка поворачивает наверх;
- **TAB** - начинает или ставит на паузу игру;
- **ESC** - выход из игры;
- **SPACE** - ускорение змейки;