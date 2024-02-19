#pragma once
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap();
  ScavTrap(std::string name);
  ~ScavTrap();
  ScavTrap(const ScavTrap &other);

  void guardGate();
  void attack(const std::string &target);
  void display(std::ostream &stream) const;

protected:
};

std::ostream &operator<<(std::ostream &stream, ScavTrap const &scav);

#endif
