#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"
#include <exception>

using std::cout;
using std::endl;

int main() {
  Bureaucrat br("br", 69);
  Bureaucrat pr("President", 1);

  ShrubberyCreationForm test("lmao");
  RobotomyRequestForm robot("rofl");
  PresidentialPardonForm pardon("uwu");

  cout << "\n-----SHRUBBERY TEST------" << endl;
  try {
    br.executeForm(test);
    br.signForm(test);
    br.executeForm(test);
  } catch (const std::exception &e) {
    cout << ANSI_RED << e.what() << ANSI_RESET << endl;
  }
  cout << "-----------------------------\n" << endl;

  cout << "\n-----ROBOTOMY TEST------" << endl;
  try {
    br.signForm(robot);
    br.executeForm(robot);
    pr.executeForm(robot);
  } catch (const std::exception &e) {
    cout << ANSI_RED << e.what() << ANSI_RESET << endl;
  }
  cout << "-----------------------------\n" << endl;

  cout << "\n-----PRESIDENTIAL TEST------" << endl;
  try {
    br.signForm(pardon);
    pr.signForm(pardon);
    br.executeForm(pardon);
    pr.executeForm(pardon);
  } catch (const std::exception &e) {
    cout << ANSI_RED << e.what() << ANSI_RESET << endl;
  }
  cout << "-----------------------------\n" << endl;

  return EXIT_SUCCESS;
}
