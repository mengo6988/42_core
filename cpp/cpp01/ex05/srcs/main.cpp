#include "Harl.hpp"
#include <iostream>

int main() {
  Harl test;

  std::cout << RED << "-----------INFO----------" << std::endl;
  test.complain("INFO");
  std::cout << YELLOW << "--------WARNING----------" << std::endl;
  test.complain("WARNING");
  std::cout << MAGENTA << "----------DEBUG---------" << std::endl;
  test.complain("DEBUG");
  std::cout << GRAY << "----------ERROR---------" << std::endl;
  test.complain("ERROR");

  std::cout << DEFAULT << "test done" << std::endl;
}
