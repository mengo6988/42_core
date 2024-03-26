#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"
#include <exception>

using std::cout;
using std::endl;

int main() {
  Intern someRandomIntern;
  AForm *rrf;
  Bureaucrat pres("President", 1);

  try {
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    pres.signForm(*rrf);
    pres.executeForm(*rrf);
  } catch (std::exception &e) {
    cout << ANSI_RED << e.what() << ANSI_RESET << endl;
  }
}
