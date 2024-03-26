#include "Array.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

using std::string;

#define MAX_VAL 20

int main() {
  Array<int> numbers(MAX_VAL);
  int *mirror = new int[MAX_VAL];
  srand(time(NULL));
  for (int i = 0; i < MAX_VAL; i++) {
    const int value = rand();
    numbers[i] = value % 10;
    mirror[i] = value % 10;
  }
  // SCOPE
  {
    Array<int> tmp = numbers;
    Array<int> test(tmp);
  }

  for (int i = 0; i < MAX_VAL; i++) {
    if (mirror[i] != numbers[i]) {
      std::cerr << "didn't save the same value!!" << std::endl;
      return 1;
    }
  }

  cout << "-------------ARRAY---------------" << endl;
  for (int i = 0; i < MAX_VAL; i++)
    cout << numbers[i] << "  |  " << mirror[i] << endl;

  cout << endl;

  try {
    numbers[-2] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  try {
    numbers[MAX_VAL] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }

  try {
    numbers[0] = 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
  cout << numbers[0] << endl;

  for (int i = 0; i < MAX_VAL; i++) {
    numbers[i] = rand();
  }
  delete[] mirror; //
  return 0;
}
