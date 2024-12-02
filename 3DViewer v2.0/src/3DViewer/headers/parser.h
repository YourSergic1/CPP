#ifndef PARSER_H
#define PARSER_H

#include <GL/gl.h>

#include <cstdio>  // Добавляем заголовок для sscanf
#include <fstream>
#include <iomanip>  // печать дробной части
#include <iostream>
#include <locale>  // настройка sscanf
#include <regex>
#include <set>
#include <string>
#include <vector>

namespace s21 {
class Parser {
 public:
  Parser();
  ~Parser();
  void ClearData();
  int Parsing();
  void PrintDataObj();
  void setFilename(const std::string& newFilename);

  //  private:
  std::vector<GLfloat> dataV;           // Массив вершин
  std::vector<std::vector<int>> dataF;  // 2D массив граней
  int sumV;                             // Кол-во вершин
  int sumF;                             // Кол-во граней
  int flagParser;                       // управление тестами
  std::string filename;
};
}  // namespace s21
#endif  // PARSER_H