#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  std::cout << "MateriaSource constructor..." << std::endl;

  for (int i = 0; i < 4; i++) {
    this->ml[i] = 0;
  }
}

MateriaSource::MateriaSource(const MateriaSource &other) {
  std::cout << "MateriaSource copy constructor..." << std::endl;
  for (int i = 0; i < 4; i++) {
    if (other.ml[i])
      this->ml[i] = other.ml[i]->clone();
  }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
  std::cout << "MateriaSource assignement operator..." << std::endl;
  for (int i = 0; i < 4; i++) {
    if (this->ml[i])
      delete this->ml[i];
    if (other.ml[i])
      this->ml[i] = other.ml[i]->clone();
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  std::cout << "MateriaSource destructor..." << std::endl;
  for (int i = 0; i < 4; i++) {
    if (this->ml[i])
      delete this->ml[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  int i = 0;

  while ((this->ml)[i])
    i++;
  if (i > 4) {
    std::cout << "Full, can't learn anymore..." << std::endl;
    return;
  } else {
    (this->ml)[i] = m;
    std::cout << m->getType() << " learned at slot " << i << "..." << std::endl;
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  int i = 0;
  // std::cout << "lTEST: " << (this->ml[i])->getType() << std::endl;

  while (i < 4 && (this->ml)[i] && this->ml[i]->getType() != type)
    i++;
  if (!this->ml[i]) {
    std::cout << "Does not exist..." << std::endl;
    return 0;
  }
  std::cout << type << " found, creating now..." << std::endl;
  return (this->ml[i]->clone());
}
