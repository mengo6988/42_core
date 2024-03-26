#include "iter.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

using std::string;

int main() {
  int test[6] = {1, 4, 4, 6, 8, 9};
  string sest[3] = {"hello", "bye", "world"};

  iter(test, 6, print);
  iter(sest, 3, print);
  return EXIT_SUCCESS;
}
