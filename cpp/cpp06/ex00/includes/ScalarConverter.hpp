#pragma once

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

typedef enum e_type {
  LITERAL = 0,
  CHAR = 1,
  INT = 2,
  FLOAT = 3,
  DOUBLE = 4,
  IDK = 5
} t_type;
typedef bool (*tc)(string &);

class ScalarConverter {
private:
  static bool is_int(string &value);
  static bool is_char(string &value);
  static bool is_float(string &value);
  static bool is_double(string &value);
  static bool is_literal(string &value);

  static void print_char(char c, t_type type);
  static void print_int(int i, t_type type);
  static void print_float(float f, string &value, t_type type);
  static void print_double(double d, string &value, t_type type);

public:
  static void convert(string &value);
};

#endif
