#include "Bureaucrat.hpp"
#include <cstdlib>

using std::cout;

int main() {
  try {
    Bureaucrat test("test", 1);
    cout << test << std::endl;
    test.incrementGrade();
  } catch (Bureaucrat::GradeTooHighException &e) {
    cout << "In the catch block now" << std::endl;
    cout << e.what() << std::endl;
  }

  try {
    Bureaucrat test("test2", 150);
    cout << test << std::endl;
    test.decrementGrade();
  } catch (Bureaucrat::GradeTooLowException &e) {
    cout << "In the catch block now" << std::endl;
    cout << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
