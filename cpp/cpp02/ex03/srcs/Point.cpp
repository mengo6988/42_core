#include "Point.hpp"
#include "Fixed.hpp"
#include <iostream>

Point::Point() : x(0), y(0) { std::cout << "default called" << std::endl; }
Point::Point(const Fixed x, const Fixed y) : x(x), y(y) {
  // std::cout << "constructor called" << std::endl;
}
Point::~Point() {
  // std::cout << "destructor called" << std::endl;
}

// Copy Constructor
Point::Point(Point &other) : x(other.x), y(other.y) {
  // std::cout << "copy constructor called" << std::endl;
}

Point &Point::operator=(const Point &other) {
  // std::cout << "assignment called" << std::endl;
  if (this != &other) {
    this->x = other.getx();
    this->y = other.gety();
  }
  return *this;
}

// getter
const Fixed &Point::getx() const { return this->x; }
const Fixed &Point::gety() const { return this->y; }
