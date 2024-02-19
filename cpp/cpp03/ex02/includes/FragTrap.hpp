
#pragma once
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap {
public:
  FragTrap();
  FragTrap(std::string name);
  ~FragTrap();
  FragTrap(const FragTrap &other);

  void display(std::ostream &stream) const;
  void highFivesGuys();

protected:
};

std::ostream &operator<<(std::ostream &stream, FragTrap const &scav);
#endif
