#pragma once

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define DEFAULT "\001\033[0;39m\002"
#define RED "\001\033[1;91m\002"
#define YELLOW "\001\033[1;93m\002"
#define MAGENTA "\001\033[1;95m\002"
#define GRAY "\001\033[1;90m\002"

class Harl {
private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);

public:
  Harl();
  ~Harl();
  void complain(std::string level);
};

#endif
