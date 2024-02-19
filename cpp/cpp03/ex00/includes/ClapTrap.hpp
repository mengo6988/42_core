#pragma once
#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
private:
  std::string name;
  unsigned int hp;
  unsigned int mp;
  unsigned int attack_dmg;

public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &other);
  ClapTrap &operator=(const ClapTrap &other);
  ~ClapTrap();

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void display(std::ostream &stream) const;
};

std::ostream &operator<<(std::ostream &stream, ClapTrap const &clap);
#endif
