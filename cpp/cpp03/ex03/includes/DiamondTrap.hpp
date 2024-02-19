
#pragma once
#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
public:
  DiamondTrap();
  DiamondTrap(std::string name);
  ~DiamondTrap();
  DiamondTrap(const DiamondTrap &other);

  void whoAmI();
  using ScavTrap::attack;
  void display(std::ostream &stream) const;

private:
  std::string name;
};

std::ostream &operator<<(std::ostream &stream, DiamondTrap const &scav);

#endif
