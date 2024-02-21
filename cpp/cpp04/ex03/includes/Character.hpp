#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <iostream>
#include <string>

class Character : public ICharacter {
private:
  std::string const name;
  AMateria *(inv[4]);

public:
  Character(std::string name);
  ~Character();
  Character(const Character &other);
  Character &operator=(const Character &other);

  std::string const &getName() const;
  AMateria *getInv(int idx);
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);
};

#endif
