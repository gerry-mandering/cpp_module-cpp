#include "Contact.hpp"

Contact::Contact() {
    this->setters[0] = &Contact::setFirstName;
    this->setters[1] = &Contact::setLastName;
    this->setters[2] = &Contact::setNickname;
    this->setters[3] = &Contact::setPhoneNumber;
    this->setters[4] = &Contact::setDarkestSecret;
}

void Contact::setFirstName(const std::string &firstName) {
    this->mFirstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
    this->mLastName = lastName;
}

void Contact::setNickname(const std::string &nickName) {
    this->mNickName = nickName;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
    this->mPhoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
    this->mDarkestSecret = darkestSecret;
}

const std::string &Contact::getFirstName() const {
    return this->mFirstName;
}

const std::string &Contact::getLastName() const {
    return this->mLastName;
}

const std::string &Contact::getNickName() const {
    return this->mNickName;
}

const std::string &Contact::getPhoneNumber() const {
    return this->mPhoneNumber;
}

const std::string &Contact::getDarkestSecret() const {
    return this->mDarkestSecret;
}
