#include "s21_matrix_oop.h"

void S21Matrix::MemoryAllocation() {
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) matrix_[i] = new double[cols_]();
}

S21Matrix S21Matrix::Minor(int row, int column) {
  S21Matrix result(rows_ - 1, cols_ - 1);
  int minor_row = 0;
  int minor_column = 0;
  for (int i = 0; i < rows_; i++) {
    if (row == i) continue;
    minor_column = 0;
    for (int j = 0; j < cols_; j++) {
      if (column == j) continue;
      result.matrix_[minor_row][minor_column] = matrix_[i][j];
      minor_column++;
    }
    minor_row++;
  }
  return result;
}