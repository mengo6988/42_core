#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0) {
  std::cout << "Default Constructor called..." << std::endl;
}

Fixed::Fixed(const Fixed &other) : value(other.value) {
  std::cout << "Copy Constructor called..." << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Assignment operator called..." << std::endl;
  if (this != &other) {
    this->setRawBits(other.getRawBits());
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called..." << std::endl; }

int Fixed::getRawBits() const {
  std::cout << "getRawBits called..." << std::endl;
  return this->value;
}

void Fixed::setRawBits(int const raw) { this->value = raw; }
