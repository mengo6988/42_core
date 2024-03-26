#include "Intern.hpp"

const string Intern::form_list[3] = {"shrubbery creation",
                                     "presidential pardon", "robotomy request"};
const F Intern::form_func[3] = {&Intern::ShrubberyCreation,
                                &Intern::PresidentialPardon,
                                &Intern::RobotomyRequest};

AForm *Intern::ShrubberyCreation(const string &target) const {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::RobotomyRequest(const string &target) const {
  return new RobotomyRequestForm(target);
}

AForm *Intern::PresidentialPardon(const string &target) const {
  return new PresidentialPardonForm(target);
}

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern &other) { *this = other; }

Intern &Intern::operator=(const Intern &other) {
  if (this != &other) {
  }
  return *this;
}

AForm *Intern::makeForm(const string &type, const string &target) const {
  for (int i = 0; i < 3; i++) {
    if (type == form_list[i])
      return (this->*(form_func[i]))(target);
  }
  throw FormNotFoundException();
}
