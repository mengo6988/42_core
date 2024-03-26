#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <iterator>
#include <list>
#include <string>
#include <vector>

using std::array;
using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main(int ac, char **av) {
  if (ac != 2) {
    cout << "Error: could not open file" << endl;
    return EXIT_SUCCESS;
  }
  BitcoinExchange btc;

  btc.readData("data.csv");
  // cout << btc << endl;
  btc.readInput(av[1]);
  return EXIT_SUCCESS;
}
