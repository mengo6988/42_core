#include "BitcoinExchange.hpp"
#include <algorithm>
#include <ctime>
#include <exception>
#include <fstream>
#include <iomanip>
#include <string>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  *this = other;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other)
    data = other.getData();
  return *this;
}

const map<time_t, double> &BitcoinExchange::getData() const { return data; }

std::ostream &operator<<(std::ostream &o, const BitcoinExchange &btc) {
  map<time_t, double> mp = btc.getData();
  map<time_t, double>::iterator bg;
  map<time_t, double>::iterator en = mp.end();

  for (bg = mp.begin(); bg != en; bg++) {
    cout << "key: " << std::put_time(localtime(&(bg->first)), "%Y-%m-%d")
         << " value: " << bg->second << std::setprecision(10) << endl;
  }
  return o;
}

void BitcoinExchange::readData(string filename) {
  std::fstream fs(filename, std::fstream::in);

  if (!fs.is_open())
    throw(std::exception());
  string key;
  size_t pos;
  double val;
  struct tm when;
  time_t time;
  string line;
  std::getline(fs, line);
  for (string line; std::getline(fs, line);) {
    pos = line.find(',');
    key = line.substr(0, pos);
    val = std::stod(line.substr(pos + 1));
    strptime(key.c_str(), "%Y-%m-%d", &when);
    time = mktime(&when);
    data.insert(std::pair<time_t, double>(time, val));
  }
  fs.close();
}

void BitcoinExchange::readInput(string filename) {
  std::fstream fs(filename, std::fstream::in);

  if (!fs.is_open()) {
    throw std::exception();
  }
  string key;
  string line;
  string head;
  // size_t pos;
  size_t delim;
  time_t time;
  double val;
  std::getline(fs, head);
  for (string line; std::getline(fs, line);) {
    delim = line.find_first_not_of("0123456789-");
    key = line.substr(0, delim);
    if (line[++delim] != '|') {
      cout << "Error: bad input => " << line << endl;
      continue;
    }
    // cout << "key: |" << key << "|" << endl;
    val = std::stod(line.substr(delim + 1));
    if (val > 1000) {
      cout << "Error: too large a number." << endl;
      continue;
    } else if (val < 0) {
      cout << "Error: not a positive number." << endl;
      continue;
    }
    time = BitcoinExchange::convertTime(key);
    // cout << "time: " << std::put_time(localtime(&time), "%Y-%m-%d") << endl;
    if (!time)
      continue;
    map<time_t, double>::iterator it = data.lower_bound(time);
    // cout << "iterator: " << (--it)->first << " | time: " << time << " | value
    // "
    //      << it->second << endl;
    if (it == data.end())
      cout << "Error: date not found in database" << endl;
    else if (it->first == time)
      cout << std::put_time(localtime(&time), "%Y-%m-%d") << " => " << val
           << " = " << val * it->second << endl;
    else {
      it--;
      cout << std::put_time(localtime(&time), "%Y-%m-%d") << " => " << val
           << " = " << val * it->second << endl;
    }
  }
}

// WARN: tm_mon: months since jan(0-11)
// tm_mday: day of month (1-31)

time_t BitcoinExchange::convertTime(const string &date) {
  struct tm when;
  time_t test;

  // cout << "date before: |" << date << "|" << endl;
  // cout << "date cstr: " << date.c_str() << endl;
  // strptime(date.c_str(), "%Y-%m-%d", &when);
  if (!strptime(date.c_str(), "%Y-%m-%d", &when)) {
    cout << "Error: bad input => " << date << endl;
    return NULL;
  }
  // std::cout << "tm_year: " << when.tm_year << std::endl;
  // std::cout << "tm_mon: " << when.tm_mon << std::endl;
  // std::cout << "tm_mday: " << when.tm_mday << std::endl;
  // cout << "tm_hour: " << when.tm_hour << endl;
  // cout << "tm_min: " << when.tm_min << endl;
  // cout << "tm_sec: " << when.tm_sec << endl;

  when.tm_hour = 0;
  when.tm_min = 0;
  when.tm_sec = 0;
  test = mktime(&when);
  // cout << "time to check: " << test << endl;
  if (when.tm_mon <= 6 && when.tm_mon % 2 == 1 && when.tm_mday == 31)
    return NULL;
  else if (when.tm_mon >= 6 && when.tm_mon % 2 == 0 && when.tm_mday == 31)
    return NULL;
  else if (when.tm_mday == 0)
    return NULL;
  else {
    // return mktime(&when);
    return test;
  }
}
