#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : value(0) {
  // std::cout << "Default Constructor called..." << std::endl;
}

Fixed::Fixed(int const raw) : value(raw << this->bits) {
  // std::cout << "Int Constructor called..." << std::endl;
}

Fixed::Fixed(float const raw) : value(roundf(raw * (1 << this->bits))) {
  // std::cout << "Float Constructor called..." << std::endl;
}

Fixed::Fixed(const Fixed &other) : value(other.value) {
  // std::cout << "Copy Constructor called..." << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  // std::cout << "Assignment operator called..." << std::endl;
  if (this != &other) {
    this->value = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() {
  // std::cout << "Destructor called..." << std::endl;
}

int Fixed::getRawBits() const {
  // std::cout << "getRawBits called..." << std::endl;
  return this->value;
}

void Fixed::setRawBits(int const raw) { this->value = raw; }

int Fixed::toInt() const { return this->value >> Fixed::bits; }
float Fixed::toFloat() const {
  return ((float)this->value / (float)(1 << this->bits));
}

std::ostream &operator<<(std::ostream &stream, Fixed const &num) {
  stream << num.toFloat();
  return stream;
}

// Overload comparison operators
bool Fixed::operator<(Fixed fixed) const {
  return (this->toFloat() < fixed.toFloat());
}

bool Fixed::operator>(Fixed fixed) const {
  return (this->toFloat() > fixed.toFloat());
}

bool Fixed::operator<=(Fixed fixed) const {
  return (this->toFloat() <= fixed.toFloat());
}

bool Fixed::operator>=(Fixed fixed) const {
  return (this->toFloat() >= fixed.toFloat());
}

bool Fixed::operator==(Fixed fixed) const {
  return (this->toFloat() == fixed.toFloat());
}

bool Fixed::operator!=(Fixed fixed) const {
  return (this->toFloat() != fixed.toFloat());
}

// arithmetic operators

float Fixed::operator+(Fixed fixed) const {
  return (this->toFloat() + fixed.toFloat());
}

float Fixed::operator-(Fixed fixed) const {
  return (this->toFloat() - fixed.toFloat());
}

float Fixed::operator*(Fixed fixed) const {
  return (this->toFloat() * fixed.toFloat());
}

float Fixed::operator/(Fixed fixed) const {
  return (this->toFloat() / fixed.toFloat());
}

// pre-increment
Fixed Fixed::operator++() {
  this->value++;
  return *this;
}
Fixed Fixed::operator--() {
  this->value--;
  return *this;
}

// post increment
Fixed Fixed::operator++(int) {
  Fixed new_fix = *this;
  ++this->value;
  return new_fix;
}
Fixed Fixed::operator--(int) {
  Fixed new_fix = *this;
  --this->value;
  return new_fix;
}

// minmax
Fixed &Fixed::min(Fixed &first, Fixed &second) {
  if (first.toFloat() <= second.toFloat()) {
    return first;
  } else {
    return second;
  }
}

const Fixed &Fixed::min(Fixed const &first, Fixed const &second) {
  if (first.toFloat() <= second.toFloat()) {
    return first;
  } else {
    return second;
  }
}

Fixed &Fixed::max(Fixed &first, Fixed &second) {
  if (first.toFloat() >= second.toFloat()) {
    return first;
  } else {
    return second;
  }
}

const Fixed &Fixed::max(Fixed const &first, Fixed const &second) {
  if (first.toFloat() >= second.toFloat()) {
    return first;
  } else {
    return second;
  }
}
