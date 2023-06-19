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

    typedef void (Contact::*SetterFunction)(const std::string&);

    SetterFunction Setters[5];

    void SetFirstName(const std::string &firstName);

    void SetLastName(const std::string &lastName);

    void SetNickname(const std::string &nickName);

    void SetPhoneNumber(const std::string &phoneNumber);

    void SetDarkestSecret(const std::string &darkestSecret);

    const std::string &GetFirstName() const;

    const std::string &GetLastName() const;

    const std::string &GetNickName() const;

    const std::string &GetPhoneNumber() const;

    const std::string &GetDarkestSecret() const;
};

#endif
