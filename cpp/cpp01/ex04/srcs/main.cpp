#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

// Create a program that takes three parameters in the following order: a
// filename and two strings, s1 and s2. It will open the file <filename> and
// copies its content into a new file <filename>.replace, replacing every
// occurrence of s1 with s2. Using C file manipulation functions is forbidden
// and will be considered cheating. All the member functions of the class
// std::string are allowed, except replace. Use them wisely! Of course, handle
// unexpected inputs and errors. You have to create and turn in your own tests
// to ensure your program works as expected.

int main(int ac, char **av) {
  if (ac != 4)
    return EXIT_FAILURE;

  std::string in_text;
  std::string out_filename = av[1];
  out_filename.append(".replace");
  std::string to_replace = av[2];
  std::string replace = av[3];
  std::ifstream infile(av[1]);
  if (infile.is_open()) {
    std::cerr << "file open err" << std::endl;
    return EXIT_FAILURE;
  }
  std::ofstream outfile(out_filename);
  int idx;

  getline(infile, in_text, '\0');
  while ((idx = in_text.find(to_replace)) != -1) {
    in_text.erase(idx, to_replace.length());
    in_text.insert(idx, replace);
  }
  outfile << in_text;
  outfile.close();
  infile.close();

  return EXIT_SUCCESS;
}
