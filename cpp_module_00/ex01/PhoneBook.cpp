#include "PhoneBook.hpp"

void	PhoneBook::Add() {
	if (this->current_index == 8)
		this->current_index = 0;

	this->current_index++;
}

void	PhoneBook::Search() {

}
