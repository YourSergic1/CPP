# s21_matrix+

Реализация библиотеки s21_matrix_oop.h


💡 [Нажми сюда](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624), **чтобы поделиться с нами обратной связью на этот проект**. Это анонимно и поможет нашей команде сделать обучение лучше. Рекомендуем заполнить опрос сразу после выполнения проекта.

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
    2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
    3.1. [Part 1](#part-1-реализация-функции-библиотеки-s21_matrix_ooph)


## Chapter I

![s21_matrix](misc/images/s21_matrix.png)

Планета Земля, 20 сентября 2000 года. 

*--  Все же какой чудесный загородный дом у нашего CEO, есть все для воплощения идей! Огромный бассейн на лужайке и веранда с видом на него ещё больше дополняют образ увлеченного и умного человека.*

*- Да, соглашусь, очень рад, что нас пригласили в это место! Правда, признаться, оно навевает мне чувство некоторого дежавю, будто я здесь уже был.*

*-- О, это странно. Поверьте мне, во всей стране вы не сможете найти второго такого дома! \
Так вот, о чем это мы? Ах да! Вот уже несколько дней в этом прекрасном месте главная техническая команда id Software обсуждает новую технологию, которую бы мы хотели представить в нашей разрабатываемой игре Doom 3. А что больше всего создает ощущение реальности на фотографии? Естественно, игра света и теней, которые сейчас рассчитываются слишком долго, сильно нагружая центральный процессор. Джон известен своими технологическими и алгоритмическими идеями и трюками, которые позволяли достичь сумасшедших прорывов в быстродействии и оптимизации кода.*

*- Да, про это я уже как будто слышал.*

*-- О, правда? Полагаю, Катарина меня немного опередила. \
Тем не менее, перейдем к самому интересному. Нашим главным техническим специалистом и основателем компании Джоном Кармаком была представлена теоретическая наработка, которая позволяла бы накладывать тени на сцене после прохождения всего графического конвейера с помощью буфера глубины и трафаретного буфера.*

*- О как, звучит действительно... интригующе.*

*-- Мы пригласили вас на эту вечеринку не случайно. Вся команда трудится над новым методом построения теней в сцене, и конкретно ваш отдел был назначен Джоном для реализации очень быстрой и оптимизированной библиотеки всевозможных матричных преобразований, на которых и будет строиться вся математическая логика алгоритма. Вектора и матрицы, транспонирование и SRT преобразование и многие другие математические объекты и операции, которые используют в компьютерной графике. Для корректного и обдуманного перехода к новому методу необходимы значительные и внушительные изменения в производительности, а ответственным за это будете лично вы! Необходимо отметить, что вся работа ведется в современном ООП-стиле для достижения максимального качества кода!*

*- Что же, я буду... эм-м... рад помочь вам.*

*-- Отлично! Кто знает, может быть...*

## Introduction

В данном проекте тебе предстоит снова реализовать уже знакомую тебе по проекту **s21_matrix** библиотеку для работы с матрицами, но на этот раз используя объектно-ориентированный подход (см. материалы). Объектно-ориентированный подход позволяет реализовать библиотеку для работы с матрицами в виде отдельного класса, над объектами которого определены операции, представленные как методами, так и стандартными операторами +, -, * и т. д.


## Chapter II

## Information

### C++ и C

C++ — язык программирования, разработанный на базе языка C для реализации программ с применением объектно-ориентированного подхода. Это означает, что общие правила синтаксиса языка C++ напрямую унаследованы из C, и, следовательно, большая часть кода, написанного на языке C, может быть скопирована в текст программы на C++ и успешно скомпилирована. По большей части, C++ лишь добавляет новые возможности для программиста или несколько изменяет их, нежели что-то отнимает, поэтому, говоря о C++, легче говорить о различиях (см. материалы), чем о сходствах. 

### Пример класса матрицы на C++

```cpp
class S21Matrix {
    private:
        // Attributes
        int rows_, cols_;         // Rows and columns
        double **matrix_;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix();              // Default constructor
        ~S21Matrix();             // Destructor

        void SumMatrix(const S21Matrix& other); 
        // Other methods..
}
```

### Напоминание основных положений о матрице

Матрица — прямоугольная таблица чисел, расположенных в m строках и n столбцах:

```
    1 2 3
A = 4 5 6
    7 8 9
```

```
     1  2  3  4
В =  5  6  7  8
     9 10 11 12
```

Получить нужный элемент можно при помощи индексов, так
A[1,1] = 1, где первый индекс — номер строки, второй — номер столбца.

Порядок матрицы — это число ее строк или столбцов. \
Главная диагональ квадратной матрицы — это диагональ, идущая из левого верхнего в правый нижний угол. \
Прямоугольная матрица (В) — это матрица, у которой число строк не равно числу столбцов. \
Квадратная матрица (А) — это матрица, у которой число строк равно числу столбцов.

### Операции над матрицами

Ниже представлено краткое описание операций над матрицами, которые необходимо реализовать в разрабатываемой библиотеке. Они похожи на операции, выполненные тобой ранее в блоке «Структурного Программирования», и более подробное описание каждой из них можно посмотреть там. Обрати внимание, что некоторые операции имеют исключительные ситуации, требующие специальной обработки с использованием механизма исключений. 

| Операция    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `bool EqMatrix(const S21Matrix& other)` | Проверяет матрицы на равенство между собой. |  |
| `void SumMatrix(const S21Matrix& other)` | Прибавляет вторую матрицу к текущей | различная размерность матриц. |
| `void SubMatrix(const S21Matrix& other)` | Вычитает из текущей матрицы другую | различная размерность матриц. |
| `void MulNumber(const double num)` | Умножает текущую матрицу на число. |  |
| `void MulMatrix(const S21Matrix& other)` | Умножает текущую матрицу на вторую. | число столбцов первой матрицы не равно числу строк второй матрицы. |
| `S21Matrix Transpose()` | Создает новую транспонированную матрицу из текущей и возвращает ее. |  |
| `S21Matrix CalcComplements()` | Вычисляет матрицу алгебраических дополнений текущей матрицы и возвращает ее. | Матрица не является квадратной. |
| `double Determinant()` | Вычисляет и возвращает определитель текущей матрицы. | Матрица не является квадратной. |
| `S21Matrix InverseMatrix()` | Вычисляет и возвращает обратную матрицу. | Определитель матрицы равен 0. |

Помимо реализации данных операций, необходимо также реализовать конструкторы и деструкторы:

| Метод    | Описание   |
| ----------- | ----------- |
| `S21Matrix()` | Базовый конструктор, инициализирующий матрицу некоторой заранее заданной размерностью. |  
| `S21Matrix(int rows, int cols)` | Параметризированный конструктор с количеством строк и столбцов. | 
| `S21Matrix(const S21Matrix& other)` | Конструктор копирования. |
| `S21Matrix(S21Matrix&& other)` | Конструктор переноса. |
| `~S21Matrix()` | Деструктор. |

А также нужно перегрузить следующие операторы, частично соответствующие операциям выше:

| Оператор    | Описание   | Исключительные ситуации |
| ----------- | ----------- | ----------- |
| `+`      | Сложение двух матриц.  | Различная размерность матриц. |
| `-`   | Вычитание одной матрицы из другой. | Различная размерность матриц. |
| `*`  | Умножение матриц и умножение матрицы на число. | Число столбцов первой матрицы не равно числу строк второй матрицы. |
| `==`  | Проверка на равенство матриц (`EqMatrix`). | |
| `=`  | Присвоение матрице значений другой матрицы. | |
| `+=`  | Присвоение сложения (`SumMatrix`).   | Различная размерность матриц. |
| `-=`  | Присвоение разности (`SubMatrix`). | Различная размерность матриц. |
| `*=`  | Присвоение умножения (`MulMatrix`/`MulNumber`). | Число столбцов первой матрицы не равно числу строк второй матрицы. |
| `(int i, int j)`  | Индексация по элементам матрицы (строка, колонка). | Индекс за пределами матрицы. |


## Chapter III

## Part 1. Реализация функции библиотеки s21_matrix_oop.h

- Программа должна быть разработана на языке C++ стандарта C++17 с использованием компилятора gcc.
- Код программы должен находиться в папке src.
- При написании кода необходимо придерживаться Google Style.
- Реализуй матрицу в виде класса `S21Matrix`.
- Храни только приватные поля `matrix_`, `rows_` и `cols_`.
- Реализуй доступ к приватным полям `rows_` и `cols_` через accessor и mutator. При увеличении размера матрица дополняется нулевыми элементами, при уменьшении лишнее просто отбрасывается.
- Оформи решение как статическую библиотеку (с заголовочным файлом s21_matrix_oop.h).
- Реализуй операции, описанные [выше](#операции-над-матрицами).
- Перегрузи операторы в соответствии с таблицей в разделе [выше](#операции-над-матрицами).
- Подготовь полное покрытие unit-тестами функций библиотеки c помощью библиотеки GTest.
- Предусмотри Makefile для сборки библиотеки и тестов (с целями all, clean, test, s21_matrix_oop.a).
