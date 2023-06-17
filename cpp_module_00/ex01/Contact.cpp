#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact::Contact() {
    this->setters[0] = &Contact::setFirstName;
    this->setters[1] = &Contact::setLastName;
    this->setters[2] = &Contact::setNickname;
    this->setters[3] = &Contact::setPhoneNumber;
    this->setters[4] = &Contact::setDarkestSecret;
}

void Contact::setFirstName(const std::string &first_name) {
    this->first_name = first_name;
}

void Contact::setLastName(const std::string &last_name) {
    this->last_name = last_name;
}

void Contact::setNickname(const std::string &nickname) {
    this->nick_name = nickname;
}

void Contact::setPhoneNumber(const std::string &phone_number) {
    this->phone_number = phone_number;
}

void Contact::setDarkestSecret(const std::string &darkest_secret) {
    this->darkest_secret = darkest_secret;
}

const std::string &Contact::getFirstName() const {
    return this->first_name;
}

const std::string &Contact::getLastName() const {
    return this->last_name;
}

const std::string &Contact::getNickName() const {
    return this->nick_name;
}

const std::string &Contact::getPhoneNumber() const {
    return this->phone_number;
}

const std::string &Contact::getDarkestSecret() const {
    return this->darkest_secret;
}
