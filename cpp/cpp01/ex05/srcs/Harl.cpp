#include "Harl.hpp"
#include <iostream>
#include <string>

#define DEBUG_MSG                                                              \
  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- " \
  "ketchup burger. I really do!"
#define INFO_MSG                                                               \
  "I cannot believe adding extra bacon costs more money. You didn’t put "    \
  "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
#define WARNING_MSG                                                              \
  "I think I deserve to have some extra bacon for free. I’ve been coming for " \
  "years whereas you started working here since last month."
#define ERROR_MSG "This is unacceptable! I want to speak to the manager now."

void Harl::debug() { std::cout << DEBUG_MSG << std::endl; }

void Harl::info() { std::cout << INFO_MSG << std::endl; }

void Harl::warning() { std::cout << WARNING_MSG << std::endl; }

void Harl::error() { std::cout << ERROR_MSG << std::endl; }

Harl::Harl() { std::cout << "Harl came in..." << std::endl; }

Harl::~Harl() { std::cout << "Harl has left..." << std::endl; }

void Harl::complain(std::string level) {
  void (Harl::*func_ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning,
                                 &Harl::error};
  std::string func_lst[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  for (int i = 0; i < 4; i++) {
    if (level == func_lst[i]) {
      (this->*func_ptr[i])();
      break;
    }
  }
}
