#pragma once
#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
private:
  std::string type;

public:
  Cure();
  ~Cure();
  Cure(const Cure &other);
  Cure &operator=(const Cure &other);

  Cure *clone() const;
  void use(ICharacter &target);
  std::string const &getType() const;
};

#endif
