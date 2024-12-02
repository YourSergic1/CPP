#include <gtest/gtest.h>

#include <sstream>

#include "../3DViewer/headers/affine_transform.h"
#include "../3DViewer/headers/parser.h"

TEST(PARSER, init) {
  s21::Parser new1;
  EXPECT_EQ(new1.sumV, 0);
  EXPECT_EQ(new1.sumF, 0);
  EXPECT_EQ(new1.flagParser, 0);
}

TEST(PARSER, print_emty) {
  s21::Parser new1;
  std::stringstream buffer;
  std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

  new1.PrintDataObj();

  std::string output = buffer.str();
  std::cout.rdbuf(old);

  EXPECT_EQ(output,
            "CPP Вершины:\nCPP Грани:\nCPP ИТОГО ======================\nCPP "
            "Вершин = 0\nCPP Поверхностей = 0\n");
}

TEST(PARSER, print_not_emty) {
  s21::Parser new1;
  std::stringstream buffer;
  std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

  new1.setFilename("objects/Cube.obj");
  new1.Parsing();
  new1.PrintDataObj();

  std::string output = buffer.str();
  std::cout.rdbuf(old);

  EXPECT_EQ(output,
            "CPP Вершины:\nv 1.000000 1.000000 -1.000000\nv 1.000000 -1.000000 "
            "-1.000000\nv 1.000000 1.000000 1.000000\nv 1.000000 -1.000000 "
            "1.000000\nv -1.000000 1.000000 -1.000000\nv -1.000000 -1.000000 "
            "-1.000000\nv -1.000000 1.000000 1.000000\nv -1.000000 -1.000000 "
            "1.000000\nCPP Грани:\nf 1 5 7 3\nf 4 3 7 8\nf 8 7 5 6\nf 6 2 4 "
            "8\nf 2 1 3 4\nf 6 5 1 2\nCPP ИТОГО ======================\nCPP "
            "Вершин = 8\nCPP Поверхностей = 6\n");
}

TEST(PARSER, file_name) {
  s21::Parser new1;
  new1.setFilename("asd");
  EXPECT_EQ(new1.filename, "asd");
}

TEST(PARSER, parsing_error1) {
  s21::Parser new1;
  new1.setFilename("objects/ssss.obj");
  new1.Parsing();
  EXPECT_EQ(new1.flagParser, 1);
}

TEST(PARSER, parsing_error2) {
  s21::Parser new1;
  new1.setFilename("objects/broken_file1.obj");
  new1.Parsing();
  EXPECT_EQ(new1.flagParser, 1);
}

TEST(PARSER, parsing_error3) {
  s21::Parser new1;
  new1.setFilename("objects/broken_file2.obj");
  new1.Parsing();
  EXPECT_EQ(new1.flagParser, 1);
}

TEST(PARSER, parsing) {
  s21::Parser new1;
  new1.setFilename("objects/Cube.obj");
  new1.Parsing();
  EXPECT_EQ(new1.sumF, 6);
  EXPECT_EQ(new1.sumV, 8);
  EXPECT_EQ(new1.flagParser, 0);
}

TEST(AFFINE_TRANSFORM, init) {
  s21::AffineTransform new1;
  float result[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      EXPECT_EQ(result[i][j], new1.matrix4x4[i][j]);
    }
  }
  EXPECT_EQ(new1.Point3Dx, 0.0f);
  EXPECT_EQ(new1.Point3Dy, 0.0f);
  EXPECT_EQ(new1.Point3Dz, 0.0f);
}

TEST(AFFINE_TRANSFORM, set_point) {
  s21::AffineTransform new1;
  new1.setPoint3D(1, 2, 3);
  EXPECT_EQ(new1.Point3Dx, 1.0f);
  EXPECT_EQ(new1.Point3Dy, 2.0f);
  EXPECT_EQ(new1.Point3Dz, 3.0f);
}

TEST(AFFINE_TRANSFORM, set_inverse_translation) {
  s21::AffineTransform new1;
  QVector3D point = {1, 2, 3};
  new1.setMatrixInverseTranslation(point, 1);
  EXPECT_EQ(new1.matrix4x4[0][3], -1.0f);
  EXPECT_EQ(new1.matrix4x4[1][3], -2.0f);
  EXPECT_EQ(new1.matrix4x4[2][3], -3.0f);
}

TEST(AFFINE_TRANSFORM, multiply_matrix_point) {
  s21::AffineTransform new1;
  new1.setPoint3D(5, 2, 3);
  new1.multiplyMatrixPoint3D();
  EXPECT_EQ(new1.Point3Dx, 5.0f);
  EXPECT_EQ(new1.Point3Dy, 2.0f);
  EXPECT_EQ(new1.Point3Dz, 3.0f);
}

TEST(AFFINE_TRANSFORM, calc_data_from_matrix) {
  float result[9] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f};
  GLfloat vertices[] = {
      -0.5f, -0.5f, 0.0f,  // Вершина 1
      0.5f,  -0.5f, 0.0f,  // Вершина 2
      0.0f,  0.5f,  0.0f   // Вершина 3
  };
  s21::AffineTransform new1;
  new1.calcDataFromMatrix(vertices, 3);
  for (int i = 0; i < 9; i++) {
    EXPECT_EQ(result[i], vertices[i]);
  }
}

TEST(AFFINE_TRANSFORM, set_matrix_scale) {
  s21::AffineTransform new1;
  new1.setMatrixScale(2);
  EXPECT_EQ(new1.matrix4x4[0][0], 2);
  EXPECT_EQ(new1.matrix4x4[1][1], 2);
  EXPECT_EQ(new1.matrix4x4[2][2], 2);
}

TEST(AFFINE_TRANSFORM, set_matrix_translation_x) {
  s21::AffineTransform new1;
  new1.setMatrixTranslation(7, 1);
  EXPECT_EQ(new1.matrix4x4[0][3], 7);
}

TEST(AFFINE_TRANSFORM, set_matrix_translation_y) {
  s21::AffineTransform new1;
  new1.setMatrixTranslation(7, 2);
  EXPECT_EQ(new1.matrix4x4[1][3], 7);
}

TEST(AFFINE_TRANSFORM, set_matrix_translation_z) {
  s21::AffineTransform new1;
  new1.setMatrixTranslation(7, 3);
  EXPECT_EQ(new1.matrix4x4[2][3], 7);
}

TEST(AFFINE_TRANSFORM, set_matrix_rotation_x) {
  s21::AffineTransform new1;
  new1.setMatrixRotation(7, 1);
  float res1 = 0.992546;
  float res2 = -0.121869;
  float res3 = 0.121869;
  float res4 = 0.992546;
  EXPECT_NEAR(new1.matrix4x4[1][1], res1, 1e-6f);
  EXPECT_NEAR(new1.matrix4x4[1][2], res2, 1e-6f);
  EXPECT_NEAR(new1.matrix4x4[2][1], res3, 1e-6f);
  EXPECT_NEAR(new1.matrix4x4[2][2], res4, 1e-6f);
}

TEST(AFFINE_TRANSFORM, set_matrix_rotation_y) {
  s21::AffineTransform new1;
  new1.setMatrixRotation(7, 2);
  float res1 = 0.992546;
  float res2 = 0.121869;
  float res3 = -0.121869;
  float res4 = 0.992546;
  EXPECT_NEAR(new1.matrix4x4[0][0], res1, 1e-6f);
  EXPECT_NEAR(new1.matrix4x4[0][2], res2, 1e-6f);
  EXPECT_NEAR(new1.matrix4x4[2][0], res3, 1e-6f);
  EXPECT_NEAR(new1.matrix4x4[2][2], res4, 1e-6f);
}

TEST(AFFINE_TRANSFORM, set_matrix_rotation_z) {
  s21::AffineTransform new1;
  new1.setMatrixRotation(7, 3);
  float res1 = 0.992546;
  float res2 = -0.121869;
  float res3 = 0.121869;
  float res4 = 0.992546;
  EXPECT_NEAR(new1.matrix4x4[0][0], res1, 1e-6f);
  EXPECT_NEAR(new1.matrix4x4[0][1], res2, 1e-6f);
  EXPECT_NEAR(new1.matrix4x4[1][0], res3, 1e-6f);
  EXPECT_NEAR(new1.matrix4x4[1][1], res4, 1e-6f);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}