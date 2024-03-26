#include "Base.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base() {}

Base *generate() {
  int random = std::rand();
  if (random % 3 == 0)
    return new A();
  else if (random % 3 == 1)
    return new B();
  else
    return new C();
}
void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    cout << "A" << endl;
  else if (dynamic_cast<B *>(p))
    cout << "B" << endl;
  else if (dynamic_cast<C *>(p))
    cout << "C" << endl;
  else
    cout << "idk" << endl;
}

void identify(Base &p) {
  try {
    A &t1 = dynamic_cast<A &>(p);
    cout << "A" << endl;
    (void)t1;
  } catch (std::exception &e) {
  }

  try {
    B &b = dynamic_cast<B &>(p);
    cout << "B" << endl;
    (void)b;
  } catch (std::exception &e) {
  }

  try {
    C &c = dynamic_cast<C &>(p);
    cout << "C" << endl;
    (void)c;
  } catch (std::exception &e) {
  }
}
