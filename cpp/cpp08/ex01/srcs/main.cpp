#include "Span.hpp"
#include <array>
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

int main() {
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  return 0;
}
