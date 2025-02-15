#include <string>
#include <iostream>

int main(void) {
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "Address of string: " << &str << std::endl;
    std::cout << "Address of pointer: " << &stringPTR << std::endl;
    std::cout << "Address of reference: " << &stringREF << std::endl;

    std::cout << "Value of string: " << str << std::endl;
    std::cout << "Value of pointer: " << stringPTR << std::endl;
    std::cout << "Value of reference: " << stringREF << std::endl;
}