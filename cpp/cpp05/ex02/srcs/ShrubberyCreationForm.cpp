#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;
using std::ostream;
using std::string;

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(string target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm("ShrubberyCreationForm", 145, 137), target(other.getTarget()) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    target = other.getTarget();
  }
  return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (executor.getGrade() > this->getGradeToExecute())
    throw AForm::GradeTooLowException();
  else if (this->getSignedState() == false)
    throw AForm::NotSignedException();
  else {
    std::ofstream outfile(this->getTarget().append("_shrubbery").c_str());

    outfile << "			   ,@@@@@@@,\n"
            << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
            << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
            << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
            << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
            << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
            << "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
            << "       |o|        | |         | |\n"
            << "       |.|        | |         | |\n"
            << "    \\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << endl;

    outfile.close();
  }
}

string ShrubberyCreationForm::getTarget() const { return this->target; }

ostream &operator<<(ostream &o, const ShrubberyCreationForm &f) {
  string b = f.getSignedState() ? "signed" : "unsigned";

  o << f.getName() << ", " << b << ", Grade to sign: " << f.getGradeToSign()
    << ", Grade to execute: " << f.getGradeToExecute();
  return o;
}
