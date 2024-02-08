#include <iomanip>
#include <iostream>
#include <string>

int main(void) {
  std::string my_string = "HI THIS IS BRAIN";
  std::string *str_ptr = &my_string;
  std::string &str_ref = my_string;

  std::cout << std::setiosflags(std::ios::left) << std::setw(29)
            << "memory address of my_string: " << &my_string << std::endl;
  std::cout << std::setiosflags(std::ios::left) << std::setw(29)
            << "memory address of str_ptr: " << str_ptr << std::endl;
  std::cout << std::setiosflags(std::ios::left) << std::setw(29)
            << "memory address of str_ref: " << &str_ref << std::endl;

  std::cout << std::setiosflags(std::ios::left) << std::setw(29)
            << "value of my_string: " << my_string << std::endl;
  std::cout << std::setiosflags(std::ios::left) << std::setw(29)
            << "value of str_ptr: " << *str_ptr << std::endl;
  std::cout << std::setiosflags(std::ios::left) << std::setw(29)
            << "value of str_ref: " << str_ref << std::endl;
}
