#include "PhoneBook.hpp"
#include <cstdio>
#include <strings.h>

std::string print_cell(std::string str) {
  std::string res = str;
  if (res.length() > 10) {
    res = res.substr(0, 8);
    res += ".";
  }
  return res;
}

PhoneBook::PhoneBook(void) : index(0) {
  std::cout << "Welcome to PhoneBook" << std::endl;
}

PhoneBook::~PhoneBook(void) { std::cout << "Bye~" << std::endl; }

void PhoneBook::add(void) {
  std::string input;
  Contact new_contact;
  if (this->index == 8) {
    this->index = 0;
    std::cout << "Warning: " << this->contact_list[this->index].getFirstName()
              << " will be replaced." << std::endl;
  }
  while (1) {
    std::cout << "adding new contact..." << std::endl;
    std::cout << "Please enter first name: ";
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::cin.clear();
      clearerr(stdin);
      return;
    }
    if (input.empty()) {
      std::cout << "Field can't be empty." << std::endl;
      continue;
    }
    new_contact.setFirstName(input);
    break;
  }

  while (1) {
    std::cout << "Please enter last name: ";
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::cin.clear();
      clearerr(stdin);
      return;
    }
    if (input.empty()) {
      std::cout << "Field can't be empty." << std::endl;
      continue;
    }
    new_contact.setLastName(input);
    break;
  }

  while (1) {
    std::cout << "Please enter nickname: ";
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::cin.clear();
      clearerr(stdin);
      return;
    }
    if (input.empty()) {
      std::cout << "Field can't be empty." << std::endl;
      continue;
    }
    new_contact.setNickName(input);
    break;
  }

  while (1) {
    std::cout << "Please enter phone number: ";
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::cin.clear();
      clearerr(stdin);
      return;
    }
    if (input.empty()) {
      std::cout << "Field can't be empty." << std::endl;
      continue;
    }
    if (!input.empty() &&
        input.find_first_not_of("0123456789") != std::string ::npos) {
      std::cout << "Invalid entry..." << std::endl;
      continue;
    }
    new_contact.setPhoneNumber(input);
    break;
  }

  while (1) {
    std::cout << "Please enter darkest secret: ";
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::cin.clear();
      clearerr(stdin);
      return;
    }
    if (input.empty()) {
      std::cout << "Field can't be empty." << std::endl;
      continue;
    }
    new_contact.setDarkestSecret(input);
    break;
  }
  this->contact_list[this->index++] = new_contact;
}

void PhoneBook::search(void) {
  std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
  for (int i = 0; i < 8; i++) {
    std::cout << "|" << std::setw(10) << i << "|" << std::setw(10)
              << print_cell(contact_list[i].getFirstName()) << "|"
              << std::setw(10) << print_cell(contact_list[i].getLastName())
              << "|" << std::setw(10)
              << print_cell(contact_list[i].getNickName()) << "|" << std::endl;
  }
  std::cout << "Please select contact to display (0 - 7)" << std::endl;
  std::string input;
  int index;
  while (1) {
    std::getline(std::cin, input);
    if (std::cin.eof()) {
      std::cin.clear();
      clearerr(stdin);
      return;
    }
    std::cout << input.length() << std::endl;
    if (input.empty()) {
      std::cout << "Please enter an index..." << std::endl;
      continue;
    } else {
      if (!input.find_first_not_of("01234567") || input.length() != 1) {
        std::cout << "Invalid input..." << std::endl;
        continue;
      }
    }
    index = std::atoi(input.c_str());
    std::cout << "First Name: " << contact_list[index].getFirstName()
              << std::endl;
    std::cout << "Last Name: " << contact_list[index].getLastName()
              << std::endl;
    std::cout << "Nickname: " << contact_list[index].getNickName() << std::endl;
    std::cout << "Phone Number: " << contact_list[index].getPhoneNumber()
              << std::endl;
    std::cout << "Darkest Secret: " << contact_list[index].getDarkestSecret()
              << std::endl;
    return;
  }
}
