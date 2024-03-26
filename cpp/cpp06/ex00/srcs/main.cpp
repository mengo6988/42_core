// #include "Bureaucrat.hpp"
#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int ac, char **av) {
  if (ac != 2)
    return EXIT_SUCCESS;
  string test = av[1];
  ScalarConverter::convert(test);
  return EXIT_SUCCESS;
}
