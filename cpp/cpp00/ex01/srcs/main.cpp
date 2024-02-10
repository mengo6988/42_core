#include "phone.hpp"

int main(void) {
  PhoneBook pb;
  std::string input;

  while (1) {
    std::cout << "Please pick a command (SEARCH, ADD, EXIT)" << std::endl;
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::cin.clear();
      clearerr(stdin);
      return EXIT_FAILURE;
    }
    if (input.empty())
      std::cout << "Empty..." << std::endl;
    else {
      if (input == "SEARCH")
        pb.search();
      else if (input == "ADD")
        pb.add();
      else if (input == "EXIT")
        return EXIT_SUCCESS;
      else {
        std::cout << "Please enter a valid command..." << std::endl;
        continue;
      }
    }
  }
}
