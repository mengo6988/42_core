#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <strstream>

class Fixed {
private:
  int value;
  static const int bits = 8;

public:
  // dafault constructor
  Fixed();
  Fixed(const int raw);
  Fixed(const float raw);
  // copy constructor
  Fixed(const Fixed &other);
  // copy assignement overload
  Fixed &operator=(const Fixed &other);
  // destructor
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
  int toInt() const;
  float toFloat() const;
};
std::ostream &operator<<(std::ostream &stream, const Fixed &num);

#endif
