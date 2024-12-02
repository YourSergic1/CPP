#include "../headers/parser.h"

namespace s21 {
Parser::Parser() {
  dataV.clear();
  dataF.clear();
  sumV = 0;
  sumF = 0;
  flagParser = 0;
}

Parser::~Parser() {
  ClearData();  // Явное очищение данных в деструкторе
}

void Parser::ClearData() {
  dataV.clear();
  dataF.clear();
  sumV = 0;
  sumF = 0;
}

void Parser::PrintDataObj() {
  std::cout << "CPP Вершины:" << std::endl;
  for (int i = 0; i < sumV; i++) {
    float x = dataV.at(i * 3);
    float y = dataV.at(i * 3 + 1);
    float z = dataV.at(i * 3 + 2);
    // Вывод чисел с плавающей точкой с указанием количества знаков после
    // запятой
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "v " << x << " " << y << " " << z << std::endl;
  }
  std::cout << "CPP Грани:" << std::endl;
  for (int i = 0; i < sumF; i++) {
    int f1 = dataF[i][0];
    int f2 = dataF[i][1];
    int f3 = dataF[i][2];
    int f4 = dataF[i][3];
    std::cout << "f " << f1 << " " << f2 << " " << f3 << " " << f4 << std::endl;
  }
  std::cout << "CPP ИТОГО ======================" << std::endl;
  std::cout << "CPP Вершин = " << sumV << std::endl;
  std::cout << "CPP Поверхностей = " << sumF << std::endl;
}

void Parser::setFilename(const std::string& newFilename) {
  filename = newFilename;
}

int Parser::Parsing() {
  // Устанавливаем локаль только для этой операции
  // Локаль "C" — это стандартная локаль,
  // которая использует точку в качестве разделителя дробной части числа.
  std::locale loc("C");
  std::locale::global(loc);

  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Ошибка открытия файла: " << filename << std::endl;
    flagParser = 1;
    return 1;
  }

  std::string line;
  while (std::getline(file, line)) {
    if (line[0] == 'v' && line[1] == ' ') {
      GLfloat x = 0, y = 0, z = 0;
      if (sscanf(line.c_str(), "v %f %f %f", &x, &y, &z) == 3) {
        dataV.push_back(x);
        dataV.push_back(y);
        dataV.push_back(z);
        sumV++;
      } else {
        std::cerr << "CPP Ошибка парсинга строки v: " << line << std::endl;
        flagParser = 1;
        return 1;
      }
    } else if (line[0] == 'f') {
      std::vector<int> faceVertices;
      faceVertices.clear();
      int fVCount = 0;  // кол-во вершин в faceVertices для подрезки
      std::regex face_regex(R"((\d+)(/\d+/\d+)?)");
      std::smatch match;

      std::string::const_iterator searchStart(line.cbegin());
      while (std::regex_search(searchStart, line.cend(), match, face_regex)) {
        faceVertices.push_back(std::stoi(match[1].str()));
        searchStart = match.suffix().first;
        fVCount++;
      }

      faceVertices.resize(fVCount);
      if (!faceVertices.empty()) {
        dataF.push_back(faceVertices);
        sumF++;
      } else {
        std::cerr << "Ошибка парсинга строки f " << std::endl;
        flagParser = 1;
        return 1;
      }
    }
  }
  file.close();

  // Возвращаем глобальную локаль к предыдущему значению
  std::setlocale(LC_ALL, "");
  return 0;
}
}  // namespace s21