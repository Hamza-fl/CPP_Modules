#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other; return *this;
}

ScalarConverter::~ScalarConverter() {}

bool isChar(const std::string& str) {
    return (str.length() == 1 && !isdigit(str[0]));
}

bool isInt(const std::string& str) {
    size_t i = 0;

	if (str[i] == '+' || str[i] == '-')
        i++;
	if (i >= str.length())
        return false;
	
	while (i < str.length()) {
		if (!isdigit(str[i]))
            return false;
		i++;
	}
	return true;
}

bool isFloat(const std::string& str) {
    if (str.length() < 2 || str[str.length() - 1] != 'f')
        return false;
    if (str == "nanf" || str == "+inff" || str == "-inff" || str == "inff")
        return true;
    std::string num = str.substr(0, str.length() - 1);
    size_t i = 0;
    if (num[i] == '+' || num[i] == '-')
        i++;

    bool hasDot = false;
    bool hasDigit = false;
    while (i < num.length()) {
        if (num[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else if (isdigit(num[i])) {
            hasDigit = true;
        } else
            return false;
        i++;
    }
    return hasDigit && hasDot;
}

bool isDouble(const std::string& str) {
    if (str == "nan" || str == "+inf" || str == "-inf" || str == "inf")
        return true;
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;

    bool hasDot = false;
    bool hasDigit = false;
    while (i < str.length()) {
        if (str[i] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        }else if (isdigit(str[i])) {
            hasDigit = true;
        } else {
            return false;
        }
        i++;
    }
    return hasDigit && hasDot;
}

void ScalarConverter::convert(const std::string& literal) {

    if (literal.empty()) {
        std::cout << "Error: empty string" << std::endl;
        return;
    }

    
}