#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(SET_MATRIX, MoreParemetr) {
  S21Matrix matrix_a(2, 2);
  EXPECT_THROW(matrix_a.SetMatrix({{1, 2, 3}, {4, 5, 6}}),
               std::invalid_argument);
  S21Matrix matrix_b(2, 2);
  EXPECT_THROW(matrix_b.SetMatrix({{1, 2}, {4, 5}, {7, 8}}),
               std::invalid_argument);
}

TEST(CREATE_MATRIX, StandartConstructor) {
  S21Matrix a;
  int cols = a.get_cols();
  int rows = a.get_rows();
  ASSERT_TRUE(cols == 3);
  ASSERT_TRUE(rows == 3);
}

TEST(CREATE_MATRIX, ParameterConstructor) {
  S21Matrix a(4, 4);
  int cols = a.get_cols();
  int rows = a.get_rows();
  ASSERT_TRUE(cols == 4);
  ASSERT_TRUE(rows == 4);
}

TEST(CREATE_MATRIX, ParameterWrong) {
  EXPECT_THROW(S21Matrix a(0, 0), std::range_error);
  EXPECT_THROW(S21Matrix a(-3, -3), std::range_error);
}

TEST(COPY_MATRIX, copy1) {
  S21Matrix a(4, 4);
  a.SetMatrix({{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}});
  ASSERT_NO_THROW(S21Matrix c(a));
  S21Matrix b(a);
  ASSERT_TRUE(a.EqMatrix(b) == 1);
}

TEST(REMOVE_MATRIX, remove1) {
  S21Matrix matrix_a(2, 2);
  ASSERT_NO_THROW(S21Matrix matrix_b = std::move(matrix_a));
}

TEST(SUM_MATRIX, equal_matrix) {
  S21Matrix a(2, 2);
  a.SetMatrix({{1, 1}, {1, 1}});
  S21Matrix b(2, 2);
  b.SetMatrix({{2, 2}, {2, 2}});
  a.SumMatrix(b);
  S21Matrix c(2, 2);
  c.SetMatrix({{3, 3}, {3, 3}});
  ASSERT_TRUE(a.EqMatrix(c) == 1);
}

TEST(SUM_MATRIX, not_equal_matrix) {
  S21Matrix a(2, 2);
  a.SetMatrix({{1, 1}, {1, 1}});
  S21Matrix b(3, 3);
  b.SetMatrix({{2, 2, 2}, {2, 2, 2}, {2, 2, 2}});
  EXPECT_THROW(a.SumMatrix(b), std::logic_error);
}

TEST(SUB_MATRIX, equal_matrix) {
  S21Matrix a(2, 2);
  a.SetMatrix({{1, 1}, {1, 1}});
  S21Matrix b(2, 2);
  b.SetMatrix({{2, 2}, {2, 2}});
  a.SubMatrix(b);
  S21Matrix c(2, 2);
  c.SetMatrix({{-1, -1}, {-1, -1}});
  ASSERT_TRUE(a.EqMatrix(c) == 1);
}

TEST(SUB_MATRIX, not_equal_matrix) {
  S21Matrix a(2, 2);
  a.SetMatrix({{1, 1}, {1, 1}});
  S21Matrix b(3, 3);
  b.SetMatrix({{2, 2, 2}, {2, 2, 2}, {2, 2, 2}});
  EXPECT_THROW(a.SubMatrix(b), std::logic_error);
}

TEST(MULT_NUMBER, test1) {
  S21Matrix a(2, 2);
  a.SetMatrix({{1, 1}, {1, 1}});
  a.MulNumber(1.1);
  S21Matrix b(2, 2);
  b.SetMatrix({{1.1, 1.1}, {1.1, 1.1}});
}

TEST(MULT_MATRIX, ParametrRight) {
  S21Matrix a(2, 3);
  S21Matrix b(3, 2);
  a.SetMatrix({{1, 1, 1}, {1, 1, 1}});
  b.SetMatrix({{2, 2}, {2, 2}, {2, 2}});
  a.MulMatrix(b);
  S21Matrix c(2, 2);
  c.SetMatrix({{6, 6}, {6, 6}});
  ASSERT_TRUE(c.EqMatrix(a) == 1);
}

TEST(MULT_MATRIX, ParametrWrong) {
  S21Matrix a(2, 2);
  S21Matrix b(3, 3);
  EXPECT_THROW(a.MulMatrix(b), std::logic_error);
}

TEST(Transpose, test1) {
  S21Matrix a(2, 3);
  S21Matrix b(3, 2);
  a.SetMatrix({{1, 2, 3}, {1, 2, 3}});
  a.Transpose();
  b.SetMatrix({{1, 1}, {2, 2}, {3, 3}});
  ASSERT_TRUE(a.Transpose() == b);
}

TEST(Determinant, ParametrWrong) {
  S21Matrix a(2, 3);
  EXPECT_THROW(a.Determinant(), std::logic_error);
}

TEST(Determinant, Rows1) {
  S21Matrix a(1, 1);
  a.SetMatrix({{3}});
  ASSERT_TRUE(a.Determinant() == 3);
}

TEST(Determinant, Rows2) {
  S21Matrix a(2, 2);
  a.SetMatrix({{2, 3}, {4, 5}});
  ASSERT_TRUE(a.Determinant() == -2);
}

TEST(Determinant, Rows3) {
  S21Matrix a(3, 3);
  a.SetMatrix({{2, 3, 4}, {5, 6, 7}, {8, 9, -1}});
  ASSERT_TRUE(a.Determinant() == 33);
}

TEST(Determinant, Rows4) {
  S21Matrix a(4, 4);
  a.SetMatrix({{2, 3, 4, 2}, {5, 6, 7, 1}, {8, 9, -1, 3}, {4, 2, 3, 0}});
  ASSERT_TRUE(a.Determinant() == 247);
}

TEST(COMPLIMENTS_MATRIX, ParametrWrong) {
  S21Matrix a(4, 3);
  EXPECT_THROW(a.CalcComplements(), std::logic_error);
}

TEST(COMPLIMENTS_MATRIX, Rows1) {
  S21Matrix a(1, 1);
  a.SetMatrix({{4}});
  S21Matrix c(1, 1);
  c.SetMatrix({{1}});
  ASSERT_TRUE(a.CalcComplements() == c);
}

TEST(COMPLIMENTS_MATRIX, ParametrRight) {
  S21Matrix a(2, 2);
  a.SetMatrix({{4, 3}, {2, 2}});
  S21Matrix c(2, 2);
  c.SetMatrix({{2, -2}, {-3, 4}});
  ASSERT_TRUE(a.CalcComplements() == c);
}

TEST(INVERSE_MATRIX, ParametrWrong) {
  S21Matrix a(4, 3);
  EXPECT_THROW(a.InverseMatrix(), std::logic_error);
}

TEST(INVERSE_MATRIX, Rows1) {
  S21Matrix a(1, 1);
  a.SetMatrix({{4}});
  S21Matrix c(1, 1);
  c.SetMatrix({{0.25}});
  ASSERT_TRUE(a.InverseMatrix() == c);
}

TEST(INVERSE_MATRIX, ParametrRight) {
  S21Matrix a(3, 3);
  a.SetMatrix({{5, 2, 1}, {2, 2, 2}, {4, 2, 4}});
  S21Matrix c(3, 3);
  c.SetMatrix({{0.25, -0.375, 0.125}, {0, 1, -0.5}, {-0.25, -0.125, 0.375}});
  ASSERT_TRUE(a.InverseMatrix() == c);
}

TEST(OPERATORS, PlusEqual) {
  S21Matrix a(3, 3);
  a.SetMatrix({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
  S21Matrix b(3, 3);
  b.SetMatrix({{2, 2, 2}, {2, 2, 2}, {2, 2, 2}});
  S21Matrix d(3, 3);
  d.SetMatrix({{3, 3, 3}, {3, 3, 3}, {3, 3, 3}});
  ASSERT_TRUE((a += b) == d);
}

TEST(OPERATORS, MinusEqual) {
  S21Matrix a(3, 3);
  a.SetMatrix({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
  S21Matrix b(3, 3);
  b.SetMatrix({{2, 2, 2}, {2, 2, 2}, {2, 2, 2}});
  S21Matrix d(3, 3);
  d.SetMatrix({{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}});
  ASSERT_TRUE((a -= b) == d);
}

TEST(OPERATORS, MultiplyEqualMatrix) {
  S21Matrix a(2, 3);
  S21Matrix b(3, 2);
  a.SetMatrix({{1, 1, 1}, {1, 1, 1}});
  b.SetMatrix({{2, 2}, {2, 2}, {2, 2}});
  S21Matrix c(2, 2);
  c.SetMatrix({{6, 6}, {6, 6}});
  ASSERT_TRUE((a *= b) == c);
}

TEST(OPERATORS, MultiplyEqualNum) {
  S21Matrix a(2, 3);
  a.SetMatrix({{1, 1, 1}, {1, 1, 1}});
  int c = 6;
  S21Matrix f(2, 3);
  f.SetMatrix({{6, 6, 6}, {6, 6, 6}});
  ASSERT_TRUE((a *= c) == f);
}

TEST(OPERATORS, Plus) {
  S21Matrix a(3, 3);
  a.SetMatrix({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
  S21Matrix b(3, 3);
  b.SetMatrix({{2, 2, 2}, {2, 2, 2}, {2, 2, 2}});
  S21Matrix c(3, 3);
  c = (a + b);
  S21Matrix d(3, 3);
  d.SetMatrix({{3, 3, 3}, {3, 3, 3}, {3, 3, 3}});
  ASSERT_TRUE(c == d);
}

TEST(OPERATORS, Minus) {
  S21Matrix a(3, 3);
  a.SetMatrix({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}});
  S21Matrix b(3, 3);
  b.SetMatrix({{2, 2, 2}, {2, 2, 2}, {2, 2, 2}});
  S21Matrix c(3, 3);
  c = (a - b);
  S21Matrix d(3, 3);
  d.SetMatrix({{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}});
  ASSERT_TRUE(c == d);
}

TEST(OPERATORS, MultiplyMatrix) {
  S21Matrix a(2, 3);
  S21Matrix b(3, 2);
  a.SetMatrix({{1, 1, 1}, {1, 1, 1}});
  b.SetMatrix({{2, 2}, {2, 2}, {2, 2}});
  S21Matrix e(2, 2);
  e = a * b;
  S21Matrix c(2, 2);
  c.SetMatrix({{6, 6}, {6, 6}});
  ASSERT_TRUE(e == c);
}

TEST(OPERATORS, MultiplyNum) {
  S21Matrix a(2, 3);
  a.SetMatrix({{1, 1, 1}, {1, 1, 1}});
  int e = 6;
  S21Matrix c(2, 3);
  c = a * e;
  S21Matrix f(2, 3);
  f.SetMatrix({{6, 6, 6}, {6, 6, 6}});
  ASSERT_TRUE(c == f);
}

TEST(OPERATORS, NotEqual) {
  S21Matrix a(2, 3);
  a.SetMatrix({{1, 1, 1}, {1, 1, 1}});
  S21Matrix b(2, 3);
  b.SetMatrix({{2, 1, 1}, {1, 1, 1}});
  ASSERT_TRUE(a != b);
}

TEST(OPERATORS, ij) {
  S21Matrix a(2, 3);
  a.SetMatrix({{1, 2, 3}, {4, 5, 6}});
  ASSERT_TRUE(a(0, 0) == 1);
  ASSERT_TRUE(a(0, 1) == 2);
  ASSERT_TRUE(a(0, 2) == 3);
  ASSERT_TRUE(a(1, 0) == 4);
  ASSERT_TRUE(a(1, 1) == 5);
  ASSERT_TRUE(a(1, 2) == 6);
}

TEST(OPERATORS, ijWrongParametr) {
  S21Matrix a(2, 3);
  a.SetMatrix({{1, 2, 3}, {4, 5, 6}});
  EXPECT_THROW(a(-1, 0), std::range_error);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}