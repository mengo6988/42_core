#include "Base.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
  srand(time(NULL));
  Base *t0 = generate();
  Base *t1 = generate();
  Base *t2 = generate();
  Base *t3 = generate();
  Base *t4 = generate();

  cout << "t0: " << endl;
  identify(t0);
  cout << "&t0: " << endl;
  identify(*t0);
  cout << endl;

  cout << "t1: " << endl;
  identify(t1);
  cout << "&t1: " << endl;
  identify(*t1);
  cout << endl;

  cout << "t2: " << endl;
  identify(t2);
  cout << "&t2: " << endl;
  identify(*t2);
  cout << endl;

  cout << "t3: " << endl;
  identify(t3);
  cout << "&t3: " << endl;
  identify(*t3);
  cout << endl;

  cout << "t4: " << endl;
  identify(t4);
  cout << "&t4: " << endl;
  identify(*t4);
  cout << endl;
}
