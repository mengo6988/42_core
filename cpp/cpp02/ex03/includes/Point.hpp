#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
private:
  Fixed x;
  Fixed y;

public:
  Point();
  Point(const Fixed x, const Fixed y);
  Point(Point &other);
  ~Point();

  Point &operator=(const Point &other);

  // getter
  const Fixed &getx() const;
  const Fixed &gety() const;
};
#endif
