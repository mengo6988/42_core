#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point &a, const Point &b, const Point &c, const Point &p) {
  // Calculate barycentric coordinates
  // alpha = area pbc/ area abc
  // beta = area pac/ area abc
  // gamma = area abp / area abc
  // alpha + gamma + beta = 1
  float detT = (b.gety().toFloat() - c.gety().toFloat()) *
                   (a.getx().toFloat() - c.getx().toFloat()) +
               (c.getx().toFloat() - b.getx().toFloat()) *
                   (a.gety().toFloat() - c.gety().toFloat());
  float alpha = ((b.gety().toFloat() - c.gety().toFloat()) *
                     (p.getx().toFloat() - c.getx().toFloat()) +
                 (c.getx().toFloat() - b.getx().toFloat()) *
                     (p.gety().toFloat() - c.gety().toFloat())) /
                detT;
  float beta = ((c.gety().toFloat() - a.gety().toFloat()) *
                    (p.getx().toFloat() - c.getx().toFloat()) +
                (a.getx().toFloat() - c.getx().toFloat()) *
                    (p.gety().toFloat() - c.gety().toFloat())) /
               detT;
  float gamma = 1.0f - alpha - beta;

  // Check if the point is inside the triangle
  return alpha >= 0 && beta >= 0 && gamma >= 0;
}
