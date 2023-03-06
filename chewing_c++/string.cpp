#include <cstring>
#include <iostream>

class	String {
	public:
		char	*str;
		int		len;

		String(char c, int n);
		String(const char* s);
		String(const String& s);
		~String();

		void	add_string(const String& s);
		void	copy_string(const String& s);
		int		strlen();
};

String::String(char c, int n) {
	int	i = 0;

	this->str = new char[n + 1];

	while (i < n) {
		this->str[i] = c;
		i++;
	}
	this->str[i] = '\0';
	this->len = n;
}

String::String(const char* s) {
	int	i = 0;

	this->str = new char[std::strlen(s) + 1];

	while (s[i] != '\0') {
		this->str[i] = s[i];
		i++;
	}
	this->len = std::strlen(s);
}

String::String(const String& s) {
	int	i = 0;

	this->str = new char[std::strlen(s.str) + 1];

	while (s.str[i] != '\0') {
		this->str[i] = s.str[i];
		i++;
	}
	this->len = std::strlen(s.str);
}

String::~String() {
	delete[] this->str;
}

void	String::add_string(const String &s) {
	int		total_length = this->len + s.len + 1;
	int		i = 0;
	int		j = 0;
	char	*new_string = new char[total_length];

	while (this->str[i] != '\0') {
		new_string[i] = this->str[i];
		i++;
	}
	while (s.str[j] != '\0')
		new_string[i++] = s.str[j++];
	delete[] this->str;
	this->str = new_string;
}

void	String::copy_string(const String &s) {
	int		length = std::strlen(s.str) + 1;
	int		i = 0;
	char*	new_string = new char[length];

	delete[] this->str;
	while (s.str[i] != '\0') {
		new_string[i] = s.str[i];
		i++;
	}
	this->str = new_string;
}

int	String::strlen() {
	return this->len;
}

int	main(void) {
	String*	str1 = new String('s', 33);
	String*	str2 = new String("Hello World!");
	String*	str3 = new String(*str2);

	std::cout << str1->str << std::endl;
	std::cout << str2->str << std::endl;
	std::cout << str3->str << std::endl;

	str1->add_string(*str2);
	std::cout << str1->str << std::endl;

	str3->copy_string(*str1);
	std::cout << str3->str << std::endl;

	return 0;
}
