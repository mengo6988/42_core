#include "ScalarConverter.hpp"
#include <algorithm>
#include <cctype>
#include <exception>
#include <string>

bool ScalarConverter::is_int(string &value) {
  int i = 0;
  if (value.front() == '+' || value.front() == '-')
    i++;
  while (value[i]) {
    if (!std::isdigit(value[i++]))
      return false;
  }
  return true;
}

bool ScalarConverter::is_char(string &value) {
  return (value.length() == 1 && std::isprint(value[0]) &&
          !std::isdigit(value[0]));
}

bool ScalarConverter::is_float(string &value) {
  if (value.back() != 'f' || value.find('.') == string::npos ||
      value.find('.') == 0 || value.find('.') == value.length() - 2)
    return false;
  int j = 0;
  int found = 0;
  if (value.front() == '+' || value.front() == '-')
    j++;
  for (int i = j; i < (int)(value.length() - 1); i++) {
    if (value[i] == '.')
      found++;
    if ((value[i] != '.' && !(std::isdigit(value[i]))) || found > 1)
      return false;
  }
  return true;
}

bool ScalarConverter::is_double(string &value) {
  if (value.find('.') == string::npos || value.find('.') == 0 ||
      value.find('.') == value.length() - 1)
    return false;
  int j = 0;
  if (value.front() == '+' || value.front() == '-')
    j++;

  int found = 0;
  for (int i = j; i < (int)value.length(); i++) {
    if (value[i] == '.')
      found++;
    if ((value[i] != '.' && !std::isdigit(value[i])) || found > 1)
      return false;
  }
  return true;
}

bool ScalarConverter::is_literal(string &value) {
  string list[6] = {"-inf", "+inf", "-inff", "+inff", "nan", "nanf"};
  for (int i = 0; i < 6; i++) {
    if (value.compare(list[i]) == 0)
      return true;
  }
  return false;
}

void ScalarConverter::print_char(char c, t_type type) {
  if (!std::isprint(c))
    cout << "char: Non displayable" << endl;
  else if (type == LITERAL)
    cout << "char: impossible" << endl;
  else
    cout << "char: " << c << endl;
}

void ScalarConverter::print_int(int i, t_type type) {
  if (type == LITERAL)
    cout << "int: impossible" << endl;
  else
    cout << "int: " << i << endl;
}

void ScalarConverter::print_float(float f, string &value, t_type type) {
  if (type == LITERAL)
    cout << "float: " << value << "f" << endl;
  else if (f - static_cast<int>(f) == 0)
    cout << "float: " << f << ".0f" << endl;
  else
    cout << "float: " << f << "f" << endl;
}

void ScalarConverter::print_double(double d, string &value, t_type type) {
  if (type == LITERAL)
    cout << "double: " << value << endl;
  else if (d - static_cast<int>(d) == 0)
    cout << "double: " << d << ".0" << endl;
  else
    cout << "double: " << d << endl;
}

void ScalarConverter::convert(string &value) {
  tc checker[5] = {ScalarConverter::is_literal, ScalarConverter::is_char,
                   ScalarConverter::is_int, ScalarConverter::is_float,
                   ScalarConverter::is_double};
  t_type type = IDK;

  for (int j = 0; j < 5; j++) {
    if (checker[j](value)) {
      type = (j);
      break;
    }
  }
  // string check_type[5] = {"lit", "char", "int", "float", "double"};
  // cout << check_type[type] << endl;

  char c = 0;
  int i = 0;
  float f = 0;
  double d = 0;

  switch (type) {
  case LITERAL:
    if (value == "nanf")
      value = value.substr(0, 3);
    else if (value.length() == 5)
      value = value.substr(0, 4);
  case CHAR:
    c = value[0];
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);
    break;
  case INT:
    i = std::stoi(value);
    c = static_cast<char>(i);
    f = static_cast<float>(i);
    d = static_cast<double>(i);
    break;
  case FLOAT:
    f = std::stod(value);
    // cout << f << endl;
    i = static_cast<int>(f);
    c = static_cast<char>(f);
    d = static_cast<double>(f);
    break;
  case DOUBLE:
    d = std::stod(value);
    i = static_cast<int>(d);
    f = static_cast<float>(d);
    c = static_cast<char>(d);
    break;
  default:
    break;
  }

  if (type == IDK) {
    cout << "char: impossible" << endl;
    cout << "int: impossible" << endl;
    cout << "float: impossible" << endl;
    cout << "double: impossible" << endl;
  } else {
    ScalarConverter::print_char(c, type);
    ScalarConverter::print_int(i, type);
    ScalarConverter::print_float(f, value, type);
    ScalarConverter::print_double(d, value, type);
  }
}
