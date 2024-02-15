#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
  int value;
  static const int bits = 8;

public:
  // dafault constructor
  Fixed();
  // copy constructor
  Fixed(const Fixed &other);
  // copy assignement overload
  Fixed &operator=(const Fixed &other);
  // destructor
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif
