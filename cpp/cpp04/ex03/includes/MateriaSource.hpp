#pragma once
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include <string>

class MateriaSource : public IMateriaSource {
private:
  AMateria *ml[4];

public:
  MateriaSource();
  MateriaSource(const MateriaSource &other);
  MateriaSource &operator=(const MateriaSource &other);
  ~MateriaSource();

  void learnMateria(AMateria *m);
  AMateria *createMateria(std::string const &type);
};

#endif
