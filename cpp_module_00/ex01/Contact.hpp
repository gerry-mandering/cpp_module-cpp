#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

class Contact {
private:
    std::string mFirstName;
    std::string mLastName;
    std::string mNickName;
    std::string mPhoneNumber;
    std::string mDarkestSecret;

public:
    Contact();

    typedef void (Contact::*SetterFunction)(const std::string &);
    SetterFunction setters[5];

    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setNickname(const std::string &nickName);
    void setPhoneNumber(const std::string &phoneNumber);
    void setDarkestSecret(const std::string &darkestSecret);

    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getNickName() const;
    const std::string &getPhoneNumber() const;
    const std::string &getDarkestSecret() const;
};

#endif
