#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

  void MemoryAllocation();
  S21Matrix Minor(int row, int column);  //Минорная матрица

 public:
  S21Matrix();                    //констркутор
  ~S21Matrix();                   //деструктор
  S21Matrix(int rows, int cols);  //конструктор с параметрами
  S21Matrix(const S21Matrix& other);  //конструктор копирования
  S21Matrix(S21Matrix&& other);       //конструктор переноса

  bool EqMatrix(const S21Matrix& other);   //сравнение матриц
  void SumMatrix(const S21Matrix& other);  //сложени матриц
  void SubMatrix(const S21Matrix& other);  //вычитание матриц
  void MulNumber(const double num);  //Умножение матрицы на число
  void MulMatrix(const S21Matrix& other);  //умножение матрицы на матрицу
  S21Matrix Transpose();        //Траспонирование матрицы
  S21Matrix CalcComplements();  //Матрица дополнений
  double Determinant();         //Детерминант матрицы
  S21Matrix InverseMatrix();    //Инверсия матрицы

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& other);
  bool operator!=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double operator()(int row, int col);

  void SetMatrix(const std::vector<std::vector<double>>& values);
  int get_rows();
  int get_cols();
};

#endif