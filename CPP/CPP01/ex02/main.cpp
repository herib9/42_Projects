#include <iostream>
#include <string>

int	main(void) {

	std::cout << std::endl;

	std::string str = "HI THIS IS BRAIN";
	std::string *ptr = &str;
	std::string &ref = str;

	std::cout << "Variable, pointer and reference initialized" << std::endl;

	std::cout << std::endl;
	std::cout << "MEMORY ADRESS" << std::endl;
	std::cout << std::endl;

	std::cout << "VARIABLE string address: " << &str << std::endl;
	std::cout << "POINTER string address: " << ptr << std::endl; 
	std::cout << "REFERENCE string address: " << &ref << std::endl;

	std::cout << std::endl;
	std::cout << "VALUES" << std::endl;
	std::cout << std::endl;

	std::cout << "VARIABLE string value: " << str << std::endl;
	std::cout << "POINTER string value: " << *ptr << std::endl;
	std::cout << "REFERENCE string value: " << ref << std::endl;

	std::cout << std::endl;

	return (0);
}