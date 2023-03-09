#include <iostream>

class	String {
	private:
		char*	str;
		int		length;
		int		memory_capacity;

	public:
		String();
		String(char c);
		String(const char* str);
		String(const String& str);

		int		strlen() const;
		void	strjoin(const char* input_str);
		int		compare(const char* input_str);

		String&	assign(const char* input_str);
		String&	assign(const String& input_str);

		int		capacity() const;
		void	reserve(int size);

		char	at(int i) const;

		String&	insert(int loc, const String& input_str);
		String&	insert(int loc, const char* input_str);
		String&	insert(int loc, char c);

		String&	erase(int loc, int num);

		int		find(int find_from, String& input_str) const;
		int		find(int find_from, const char *input_str) const;
		int		find(int find_from, char c) const;

		void	print() const;
		void	println() const;

		bool	operator==(String& input_str);
		bool	operator==(const char* input_str);

		~String();
};

String::String() {
	this->str = nullptr;
	this->length = 0;
}

String::String(char c) {
	this->str = new char[1];
	this->str[0] = c;
	this->length = 1;
	this->memory_capacity = 1;
}

String::String(const char* str) {
	int	i;

	this->length = std::strlen(str);
	this->memory_capacity = this->length;
	this->str = new char[length];
	i = 0;
	while (i < length)
	{
		this->str[i] = str[i];
		i++;
	}
}

String::String(const String& str) {
	int	i;

	this->length = str.length;
	this->memory_capacity = this->length;
	this->str = new char[length];
	i = 0;
	while (i < length)
	{
		this->str[i] = str.str[i];
		i++;
	}
}

int	String::strlen() const {
	return this->length;
}

void	String::strjoin(const char *input_str) {
	char*	new_str;
	int		total_length;
	int		i;
	int		j;

	total_length = this->length + std::strlen(input_str);
	new_str = new char[total_length];
	i = 0;
	while (i < this->length)
	{
		new_str[i] = this->str[i];
		i++;
	}
	while (i < total_length)
	{
		new_str[i] = input_str[j];
		i++;
		j++;
	}
	delete[] this->str;
	this->str = new_str;
	this->length = total_length;
}

int	String::compare(const char *input_str) {
	int	input_str_length;
	int	i;

	input_str_length = std::strlen(input_str);
	i = 0;
	while (i < this->length && i < input_str_length && this->str[i] == input_str[i])
		i++;
	if (i == this->length && i == input_str_length)
		return 0;
	else
		return this->str[i] - input_str[i];
}

String&	String::assign(const char* input_str) {
	int	input_str_length;

	input_str_length = std::strlen(input_str);

	if (input_str_length > this->memory_capacity) {
		delete[] this->str;
		this->str = new char[input_str_length];
		this->memory_capacity = input_str_length;
	}

	for (int i = 0; i < input_str_length; i++)
		this->str[i] = input_str[i];

	this->length = input_str_length;

	return *this;
}

String&	String::assign(const String& input_str) {
	if (input_str.length > this->memory_capacity) {
		delete[] this->str;
		this->str = new char[input_str.length];
		this->memory_capacity = input_str.length;
	}

	for (int i = 0; i < input_str.length; i++)
		this->str[i] = input_str.str[i];

	this->length = input_str.length;

	return *this;
}

int	String::capacity() const {
	return this->memory_capacity;
}

void	String::reserve(int size) {
	char	*new_str;

	if (size > this->memory_capacity)
	{
		new_str = new char[size];
		this->memory_capacity = size;

		for (int i = 0; i < this->length; i++)
			new_str[i] = this->str[i];

		delete[] this->str;
		this->str = new_str;
	}
}

char	String::at(int i) const {
	if (i < 0 || i > this->length)
		return 0;
	else
		return this->str[i];
}

String&	String::insert(int loc, const String& input_str) {
	char*	prev_string_content;
	int		i, j;

	if (loc < 0 || loc > this->length)
		return *this;

	if (this->length + input_str.length > this->memory_capacity) {
		if (this->memory_capacity * 2 > this->length + input_str.length)
			this->memory_capacity *= 2;
		else
			this->memory_capacity = this->length + input_str.length;

		prev_string_content = this->str;
		this->str = new char[this->memory_capacity];

		for (i = 0; i < loc; i++)
			this->str[i] = prev_string_content[i];

		for (j = 0; j < input_str.length; j++)
			this->str[i + j] = input_str.str[j];

		for (; i < this->length; i++)
			this->str[input_str.length + i] = prev_string_content[i];

		delete[] prev_string_content;
		this->length = memory_capacity;

		return *this;
	}

	for (int i = this->length - 1; i >= loc; i--)
		this->str[i + input_str.length] = this->str[i];

	for (int i = 0; i < input_str.length; i++)
		this->str[loc + i] = input_str.str[i];

	this->length += input_str.length;
	return *this;
}

String&	String::insert(int loc, const char* input_str) {
	String	temp(input_str);

	insert(loc, temp);
	return *this;
}

String&	String::insert(int loc, char c) {
	String	temp(c);

	insert(loc, temp);
	return *this;
}

String&	String::erase(int loc, int num) {
	if (num <= 0 || loc < 0 || loc > this->length)
		return *this;

	for (int i = loc; i < loc + num; i++)
		this->str[i] = this->str[i + num];

	this->length -= num;

	return *this;
}

int	String::find(int find_from, String& input_str) const {
	int	i, j;

	if (input_str.length == 0)
		return -1;
	i = find_from;
	while (this->str[i] != '\0') {
		if (this->str[i] == input_str.str[0]) {
			j = 0;
			while (this->str[i + j] == input_str.str[j])
				j++;
			if (j == input_str.length)
				return i;
		}
		i++;
	}
	return -1;
}

int	String::find(int find_from, const char* input_str) const {
	String	temp(input_str);

	return find(find_from, temp);
}

int	String::find(int find_from, char c) const {
	String	temp(c);

	return find(find_from, temp);
}

void	String::print() const {
	for (int i = 0; i < this->length; i++) {
		std::cout << this->str[i];
	}
}

void	String::println() const {
	for (int i = 0; i< this->length; i++) {
		std::cout << this->str[i];
	}
	std::cout << std::endl;
}

bool	String::operator==(String &input_str) {
	return !compare(input_str.str);
}

bool	String::operator==(const char* input_str) {
	return !compare(input_str);
}

String::~String() {
	if (this->str != nullptr)
		delete[] this->str;
	this->length = 0;
}

int	main(void) {
	String	str1("very very very long string");
	String	str2("<inserting>");
	str1.reserve(30);

	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.strlen() << std::endl;
	str1.println();

	str1.insert(5, str2);
	std::cout << "Capacity : " << str1.capacity() << std::endl;
	std::cout << "String length : " << str1.strlen() << std::endl;
	str1.println();

	String	str3("abcd");
	String	str4("abcd");

	if (str3 == str4)
		std::cout << "operator == " << std::endl;
	if (str3 == "acd")
		std::cout << "operator == " << std::endl;
	std::cout << "compare : " << str3.compare("abcc") << std::endl;
	std::cout << str3.find(0, "bc") << std::endl;
	str3.println();
	str3.erase(1, 3);
	str3.println();

	return 0;
}
