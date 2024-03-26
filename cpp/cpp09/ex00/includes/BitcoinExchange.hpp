#pragma once

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <ostream>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;

class BitcoinExchange {
private:
  map<time_t, double> data;

public:
  BitcoinExchange();
  ~BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &other);
  BitcoinExchange &operator=(const BitcoinExchange &other);

  const map<time_t, double> &getData() const;

  void readData(string filename);
  void readInput(string filename);
  time_t convertTime(const string &date);
};

std::ostream &operator<<(std::ostream &o, const BitcoinExchange &btc);

#endif
