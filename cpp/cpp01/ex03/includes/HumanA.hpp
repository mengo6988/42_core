#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class HumanA {
private:
  std::string name;
  Weapon &weapon;

public:
  HumanA(std::string name, Weapon &weapon);
  ~HumanA();

  void attack();
};
/* better to use a reference in this case, as humanA will ALWAYS HAVE A WEAPON
 */

#endif
