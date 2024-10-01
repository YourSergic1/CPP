#include "s21_matrix_oop.h"

void S21Matrix::SetMatrix(const std::vector<std::vector<double>> &values) {
  if ((int)values.size() != rows_)
    throw std::invalid_argument(
        "S21Matrix Class => Ошибка метода SetMatrix(): \
                Несоответствие количества строк!");
  for (const auto &row : values)
    if ((int)row.size() != cols_)
      throw std::invalid_argument(
          "S21Matrix Class => Ошибка метода SetMatrix(): \
                    Несоответствие количества столбцов!");
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = values[i][j];
}

int S21Matrix::get_rows() { return rows_; }

int S21Matrix::get_cols() { return cols_; }