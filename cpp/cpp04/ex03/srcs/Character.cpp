#include "Character.hpp"
#include <iostream>
#include <string>

Character::Character(std::string name) : name(name) {
  std::cout << "Character constructor..." << std::endl;
  for (int i = 0; i < 4; i++) {
    this->inv[i] = 0;
  }
}

Character::~Character() {
  std::cout << "Character destructor..." << std::endl;
  for (int i = 0; i < 4; i++) {
    if (this->inv[i]) {
      delete this->inv[i];
    }
  }
}

Character::Character(const Character &other) : name(other.name) {
  std::cout << "Character Copy constructor" << std::endl;
  for (int i = 0; i < 4; i++) {
    if (other.inv[i])
      this->inv[i] = other.inv[i]->clone();
  }
}

Character &Character::operator=(const Character &other) {
  std::cout << "Character Copy assignement..." << std::endl;
  if (this != &other) {
    for (int i = 0; i < 4; i++) {
      if (other.inv[i])
        this->inv[i] = other.inv[i]->clone();
    }
  }
  return *this;
}

std::string const &Character::getName() const { return this->name; }

void Character::equip(AMateria *m) {
  int i = 0;
  if (!m) {
    std::cout << "Nothing to equip..." << std::endl;
    return;
  }
  while (this->inv[i])
    i++;
  if (i >= 4) {
    std::cout << "Inventory full..." << std::endl;
    return;
  }
  this->inv[i] = m;
  std::cout << name << " equipped " << this->inv[i]->getType() << " in slot "
            << i << "..." << std::endl;
}
void Character::unequip(int idx) {
  if (!this->inv[idx]) {
    std::cout << "Nothing equipped at slot..." << std::endl;
  } else if (idx < 0 || idx > 4) {
    std::cout << "Index out of range..." << std::endl;
  } else {
    std::cout << this->inv[idx]->getType() << " unequipped from slot " << idx
              << "..." << std::endl;
    this->inv[idx] = 0;
  }
}
void Character::use(int idx, ICharacter &target) {
  if (!this->inv[idx]) {
    std::cout << "Nothing equipped at slot..." << std::endl;
  } else if (idx < 0 || idx > 4) {
    std::cout << "Index out of range..." << std::endl;
  } else {
    std::cout << this->getName();
    this->inv[idx]->use(target);
  }
}

AMateria *Character::getInv(int idx) { return this->inv[idx]; }
