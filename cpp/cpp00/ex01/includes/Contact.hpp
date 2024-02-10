#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
public:
  Contact(void);
  ~Contact(void);
  std::string getFirstName(void);
  std::string getLastName(void);
  std::string getNickName(void);
  std::string getPhoneNumber(void);
  std::string getDarkestSecret(void);
  void setFirstName(std::string first_name);
  void setLastName(std::string last_name);
  void setNickName(std::string nick_name);
  void setPhoneNumber(std::string phone_number);
  void setDarkestSecret(std::string darkest_secret);

private:
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;
};
#endif
