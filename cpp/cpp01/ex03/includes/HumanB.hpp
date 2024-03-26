
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class HumanB {
private:
  std::string name;
  Weapon *weapon;

public:
  HumanB(std::string name);
  ~HumanB();

  // getters & setters
  void setName(std::string name);
  void setWeapon(Weapon &weapon);
  std::string getName();
  Weapon getWeapon();

  void attack();
};

#endif
