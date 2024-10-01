#include "s21_matrix_oop.h"

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 1 || cols < 1) {
    throw std::range_error("Rows and colls must be more then 0");
  } else {
    MemoryAllocation();
    int count = 0;
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++) matrix_[i][j] = count;
  }
}

S21Matrix::S21Matrix() : S21Matrix(3, 3) {}

S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) delete[] matrix_[i];

  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  MemoryAllocation();
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = other.matrix_;
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool flag = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) flag = false;
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      if (matrix_[i][j] != other.matrix_[i][j]) flag = false;
  return flag;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::logic_error("Rows and colls must be equal");
  else {
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++) matrix_[i][j] += other.matrix_[i][j];
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_)
    throw std::logic_error("Rows and colls must be equal");
  else {
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < cols_; j++) matrix_[i][j] -= other.matrix_[i][j];
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] *= num;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_)
    throw std::logic_error(
        "Cols of 1 matrix and rows of 2 matrix must be equal");
  else {
    S21Matrix result(rows_, other.cols_);
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < other.cols_; j++)
        for (int k = 0; k < other.rows_; k++)
          result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
    *this = result;
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) result.matrix_[j][i] = matrix_[i][j];
  return result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_)
    throw std::logic_error("Cols and rows must be equal");
  else {
    double result = 0;
    if (cols_ == 1)
      result = matrix_[0][0];
    else if (cols_ == 2)
      result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    else if (cols_ == 3)
      result = matrix_[0][0] * matrix_[1][1] * matrix_[2][2] +
               matrix_[0][1] * matrix_[1][2] * matrix_[2][0] +
               matrix_[0][2] * matrix_[1][0] * matrix_[2][1] -
               matrix_[0][2] * matrix_[1][1] * matrix_[2][0] -
               matrix_[0][0] * matrix_[1][2] * matrix_[2][1] -
               matrix_[0][1] * matrix_[1][0] * matrix_[2][2];
    else {
      int flag = 0;
      for (int i = 0; i < cols_ && flag == 0; i++) {
        S21Matrix minored_matrix(Minor(0, i));
        result += pow((-1), i) * matrix_[0][i] * minored_matrix.Determinant();
      }
    }
    return result;
  }
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_)
    throw std::logic_error("Cols and rows must be equal");
  else {
    S21Matrix result(rows_, cols_);
    if (rows_ == 1)
      result.matrix_[0][0] = 1;
    else {
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          S21Matrix minor = this->Minor(i, j);
          result.matrix_[i][j] = pow(-1, i + j) * minor.Determinant();
        }
      }
    }
    return result;
  }
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_)
    throw std::logic_error("Cols and rows must be equal");
  else {
    S21Matrix result_matrix(*this);
    if (rows_ == 1)
      result_matrix.matrix_[0][0] = 1.0 / matrix_[0][0];
    else {
      double determinant = Determinant();
      result_matrix = CalcComplements().Transpose();
      result_matrix.MulNumber(1 / determinant);
    }
    return result_matrix;
  }
}