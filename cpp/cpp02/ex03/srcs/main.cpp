#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

bool bsp(const Point &a, const Point &b, const Point &c, const Point &p);

int main(void) {
  const Point a;
  const Point b(10, 0);
  const Point c(0, 10);
  const Point point(1, 1);
  std::cout << "The point( x= " << point.getx() << "\t\ty= " << point.gety()
            << "\t) is inside the triangle\n"
            << "\ta( x= " << a.getx() << "\t\ty= " << a.gety() << "\t)\n"
            << "\tb( x= " << b.getx() << "\ty= " << b.gety() << "\t)\n"
            << "\tc( x= " << c.getx() << "\t\ty= " << c.gety() << "\t)\n"
            << std::endl;
  if (bsp(a, b, c, point) == true)
    std::cout << "\033[32mTRUE\033[0m" << std::endl;
  else
    std::cout << "\033[31mFALSE\033[0m" << std::endl;
  std::cout << "\n-------------------------------------------------------------"
               "--------\n"
            << std::endl;
  const Point a1((float)-1.5, (float)-1.5);
  const Point b1((float)2.5, (float)2.5);
  const Point c1((float)-1, (float)-2);
  const Point point1((float)8.5, (float)-9);

  std::cout << "The point( x= " << point.getx() << "\t\ty= " << point1.gety()
            << "\t) is inside the triangle\n"
            << "\ta( x= " << a1.getx() << "\ty= " << a1.gety() << "\t)\n"
            << "\tb( x= " << b1.getx() << "\ty= " << b1.gety() << "\t)\n"
            << "\tc( x= " << c1.getx() << "\ty= " << c1.gety() << "\t)\n"
            << std::endl;
  if (bsp(a1, b1, c1, point1) == true)
    std::cout << "\033[32mTRUE\033[0m" << std::endl;
  else
    std::cout << "\033[31mFALSE\033[0m" << std::endl;
  return (0);
}
