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

  // Overload comparison operators
  bool operator>(Fixed fixed) const;
  bool operator<(Fixed fixed) const;
  bool operator>=(Fixed fixed) const;
  bool operator<=(Fixed fixed) const;
  bool operator==(Fixed fixed) const;
  bool operator!=(Fixed fixed) const;

  // arithmetic operators
  float operator+(Fixed fixed) const;
  float operator-(Fixed fixed) const;
  float operator*(Fixed fixed) const;
  float operator/(Fixed fixed) const;

  // pre increment
  Fixed operator++();
  Fixed operator--();

  // post increment
  Fixed operator++(int);
  Fixed operator--(int);

  // minmax
  static Fixed &min(Fixed &first, Fixed &second);
  static const Fixed &min(Fixed const &first, Fixed const &second);
  static Fixed &max(Fixed &first, Fixed &second);
  static const Fixed &max(Fixed const &first, Fixed const &second);
};
std::ostream &operator<<(std::ostream &stream, const Fixed &num);

#endif
