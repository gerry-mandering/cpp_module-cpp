#include "Contact.hpp"
#include <iostream>

Contact::Contact() {
    this->Setters[0] = &Contact::SetFirstName;
    this->Setters[1] = &Contact::SetLastName;
    this->Setters[2] = &Contact::SetNickname;
    this->Setters[3] = &Contact::SetPhoneNumber;
    this->Setters[4] = &Contact::SetDarkestSecret;
}

void Contact::SetFirstName(const std::string &firstName) {
    this->mFirstName = firstName;
}

void Contact::SetLastName(const std::string &lastName) {
    this->mLastName = lastName;
}

void Contact::SetNickname(const std::string &nickName) {
    this->mNickName = nickName;
}

void Contact::SetPhoneNumber(const std::string &phoneNumber) {
    this->mPhoneNumber = phoneNumber;
}

void Contact::SetDarkestSecret(const std::string &darkestSecret) {
    this->mDarkestSecret = darkestSecret;
}

const std::string &Contact::GetFirstName() const {
    return this->mFirstName;
}

const std::string &Contact::GetLastName() const {
    return this->mLastName;
}

const std::string &Contact::GetNickName() const {
    return this->mNickName;
}

const std::string &Contact::GetPhoneNumber() const {
    return this->mPhoneNumber;
}

const std::string &Contact::GetDarkestSecret() const {
    return this->mDarkestSecret;
}
