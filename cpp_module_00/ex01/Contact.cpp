#include "PhoneBook.hpp"

void	Contact::SetFirstName(const std::string &first_name) {
	this->first_name.assign(first_name);
}

void	Contact::SetLastName(const std::string &last_name) {
	this->last_name.assign(last_name);
}

void	Contact::SetNickname(const std::string &nickname) {
	this->nickname.assign(nickname);
}

void	Contact::SetPhoneNumber(const std::string &phone_number) {
	this->phone_number.assign(phone_number);
}

void	Contact::SetDarkestSecret(const std::string &darkest_secret) {
	this->darkest_secret.assign(darkest_secret);
}

const std::string&	Contact::GetFirstName() {
	return this->first_name;
}

const std::string&	Contact::GetLastName() {
	return this->last_name;
}

const std::string&	Contact::GetNickname() {
	return this->nickname;
}

const std::string&	Contact::GetPhoneNumber() {
	return this->phone_number;
}

const std::string&	Contact::GetDarkestSecret() {
	return this->darkest_secret;
}
