#include "s21_matrix_oop.h"

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
  rows_ = other.rows_;
  cols_ = other.cols_;
  MemoryAllocation();
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result(rows_, cols_);
  result = *this;
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result(rows_, cols_);
  result = *this;
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result(rows_, cols_);
  result = *this;
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(rows_, cols_);
  result = *this;
  result.MulNumber(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  bool res;
  res = EqMatrix(other);
  return res;
}

bool S21Matrix::operator!=(const S21Matrix& other) {
  bool res;
  res = !EqMatrix(other);
  return res;
}

double S21Matrix::operator()(int row, int col) {
  if (row < 0 || col < 0 || col > cols_ || row > rows_)
    throw std::range_error("Segmentation fault!");
  else
    return matrix_[row][col];
}