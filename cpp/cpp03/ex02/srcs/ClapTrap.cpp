#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <utility>

ClapTrap::ClapTrap() : name(""), hp(10), mp(10), attack_dmg(0) {
  std::cout << "clap default constructor..." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : name(name), hp(10), mp(10), attack_dmg(0) {
  std::cout << "clap name constructor..." << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int mp,
                   unsigned int attack_dmg)
    : name(name), hp(hp), mp(mp), attack_dmg(attack_dmg) {
  std::cout << "clap param constructor..." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "clap copy constructor..." << std::endl;
  operator=(other);
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "clap assignment constructor..." << std::endl;
  if (this != &other) {
    name = other.name;
    hp = other.hp;
    mp = other.mp;
    attack_dmg = other.attack_dmg;
  }
  return *this;
}

ClapTrap::~ClapTrap() { std::cout << "clap destructor..." << std::endl; }

void ClapTrap::attack(const std::string &target) {
  // ClapTrap <name> attacks <target>, causing <damage> points of
  // damage!
  if (mp > 0) {
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
              << attack_dmg << " damage!" << std::endl;
    mp--;
  } else {
    std::cout << "Not enough energy..." << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap " << name << " took " << amount << " damage."
            << std::endl;
  if (hp <= amount) {
    std::cout << "ClapTrap " << name << " died..." << std::endl;
    hp = 0;
  } else {
    hp -= amount;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  std::cout << "ClapTrap " << name << " repaired " << amount << " hp."
            << std::endl;
  hp += amount;
}

void ClapTrap::display(std::ostream &stream) const {
  stream << "Name: " << name << ", Hp: " << hp << ", Mp: " << mp
         << ", Attack_dmg: " << attack_dmg << std::endl;
}

std::ostream &operator<<(std::ostream &stream, ClapTrap const &clap) {
  clap.display(stream);
  return stream;
}
