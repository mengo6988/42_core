#include <cctype>
#include <iostream>
#include <string>

int main(int ac, char **av) {
  std::string res;
  if (ac == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  else {
    for (int i = 1; i < ac; i++) {
      res.append(av[i]);
    }
    for (int i = 0; res[i]; i++) {
      res[i] = toupper(res[i]);
    }
    std::cout << res << std::endl;
  }
  return 0;
}
