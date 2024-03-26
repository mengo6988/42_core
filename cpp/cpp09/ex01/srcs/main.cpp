#include "RPN.hpp"
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

using std::array;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main(int ac, char **av) {
  if (ac != 2) {
    cout << "Error: invalid argument" << endl;
    return EXIT_SUCCESS;
  }
  RPN r;

  r.calculate(av[1]);
  return EXIT_SUCCESS;
}
