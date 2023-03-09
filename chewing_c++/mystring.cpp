#include <iostream>

class	MyString {
	private:
		char*	string_content;
		int		string_length;
		int		memory_capacity;

	public:
		explicit MyString(int capacity);
		MyString(const char* str);
		MyString(const MyString& str);
		~MyString();

		int	length() const;
};

MyString::MyString(int capacity) {
	this->string_content = new char[capacity];
	this->string_length = 0;
	this->memory_capacity = capacity;
	std::cout << "Capacity : " << capacity << std::endl;
}

MyString::MyString(const char *str) {
	this->string_length = 0;
	while (str[this->string_length])
		this->string_length++;

	this->string_content = new char[this->string_length];
	this->memory_capacity = this->string_length;

	for (int i = 0; i < this->string_length; i++)
		this->string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
	this->string_length = str.string_length;
	this->string_content = new char[this->string_length];

	for (int i = 0; i < this->string_length; i++)
		this->string_content[i] = str.string_content[i];
}

MyString::~MyString() {
	delete[] this->string_content;
}

int	MyString::length() const {
	return this->string_length;
}

int	main(void) {
	MyString	str = "helloworld!";
	MyString	str1(3);
	//MyString	str2 = 3;
}
