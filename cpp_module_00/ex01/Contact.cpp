#include "PhoneBook.hpp"
#include "Contact.hpp"

void	Contact::setFirstName(const std::string &first_name) {
	this->first_name.assign(first_name);
}

void	Contact::setLastName(const std::string &last_name) {
	this->last_name.assign(last_name);
}

void	Contact::setNickname(const std::string &nickname) {
	this->nick_name.assign(nickname);
}

void	Contact::setPhoneNumber(const std::string &phone_number) {
	this->phone_number.assign(phone_number);
}

void	Contact::setDarkestSecret(const std::string &darkest_secret) {
	this->darkest_secret.assign(darkest_secret);
}

const std::string&	Contact::getFirstName() const {
	return this->first_name;
}

const std::string&	Contact::getLastName() const {
	return this->last_name;
}

const std::string&	Contact::getNickName() const {
	return this->nick_name;
}

const std::string&	Contact::getPhoneNumber() const {
	return this->phone_number;
}

const std::string&	Contact::getDarkestSecret() const {
	return this->darkest_secret;
}
