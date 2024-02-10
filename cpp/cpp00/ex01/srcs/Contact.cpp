#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::getFirstName(void) { return firstName; }
std::string Contact::getLastName(void) { return lastName; }
std::string Contact::getNickName(void) { return nickName; }
std::string Contact::getPhoneNumber(void) { return phoneNumber; }
std::string Contact::getDarkestSecret(void) { return darkestSecret; }

void Contact::setFirstName(std::string first_name) {
  this->firstName = first_name;
}
void Contact::setLastName(std::string last_name) { this->lastName = last_name; }
void Contact::setNickName(std::string nick_name) { this->nickName = nick_name; }
void Contact::setPhoneNumber(std::string phone_number) {
  this->phoneNumber = phone_number;
}
void Contact::setDarkestSecret(std::string darkest_secret) {
  this->darkestSecret = darkest_secret;
}
