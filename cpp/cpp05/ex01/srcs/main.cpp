#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "colors.hpp"
#include <exception>

using std::cout;
using std::endl;

int main() {
  Bureaucrat br("br", 69);

  try {
    Form test("test", 10000, 20);
  } catch (const std::exception &e) {
    cout << ANSI_BRIGHT_RED << "Error: " << e.what() << ANSI_RESET << endl;
  }

  try {
    Form test("test", 20, 0000);
  } catch (const std::exception &e) {
    cout << ANSI_BRIGHT_RED << "Error: " << e.what() << ANSI_RESET << endl;
  }
  try {
    Form fr("fr", 88, 88);
    cout << fr << endl;
    br.signForm(fr);
    br.signForm(fr);
  } catch (const std::exception &e) {
    cout << ANSI_BRIGHT_RED << "Error: " << e.what() << ANSI_RESET << endl;
  }
  try {
    Form test("test", 1, 1);
    cout << test << endl;
    br.signForm(test);
  } catch (const std::exception &e) {
    cout << ANSI_BRIGHT_RED << "Error:" << e.what() << ANSI_RESET << endl;
  }

  return EXIT_SUCCESS;
}
