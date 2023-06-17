#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact {
private:
    std::string first_name;
    std::string last_name;
    std::string nick_name;
    std::string phone_number;
    std::string darkest_secret;

public:
    Contact();

    typedef void (Contact::*SetterFunction)(const std::string&);

    SetterFunction setters[5];

    void setFirstName(const std::string &first_name);

    void setLastName(const std::string &last_name);

    void setNickname(const std::string &nickname);

    void setPhoneNumber(const std::string &phone_number);

    void setDarkestSecret(const std::string &darkest_secret);

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getNickName() const;

    const std::string &getPhoneNumber() const;

    const std::string &getDarkestSecret() const;
};

#endif
