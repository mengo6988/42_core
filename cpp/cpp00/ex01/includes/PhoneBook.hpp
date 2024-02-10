#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>

class PhoneBook {
private:
  Contact contact_list[8];
  int index;

public:
  PhoneBook(void);
  ~PhoneBook(void);
  void add(void);
  void search(void);
};

std::string print_cell(std::string str);

#endif
