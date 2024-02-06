#pragma once

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "phone.h"

class Contact {
public:
  Contact(std::string first_name, std::string last_name, std::string nick_name,
          std::string phone_number, std::string darkest_secret);
  ~Contact(void);
  std::string getFirstName(void);
  std::string getLastName(void);
  std::string getNickName(void);
  std::string getPhoneNumber(void);
  std::string getDarkestSecret(void);

private:
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;
};
#endif
