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

    if (isChar(literal)) {
		char c = literal[0];

		int i = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);

		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else if (isInt(literal)) {
		bool negative = (literal[0] == '-');
		size_t start = 0;
		if (literal[0] == '+' || literal[0] == '-')
			start = 1;
		size_t len = literal.length() - start;
	
		if (len > 10 || (len == 10 && ((!negative && literal[literal.length() - 1] > '7') ||
			(negative && literal[literal.length() - 1] > '8')))) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
		int i = std::atoi(literal.c_str());
		char c = static_cast<char>(i);
		float f = static_cast<float>(i);
		double d = static_cast<double>(i);

		if (i < 0 || i > 127)
			std::cout << "char: impossible" << std::endl;
		else if (i < 32 || i == 127)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;

		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << ".0f" << std::endl;
		std::cout << "double: " << d << ".0" << std::endl;
	}
	else if (isFloat(literal)) {
		float f = static_cast<float>(atof(literal.c_str()));
		char c = static_cast<char>(f);
		int i = static_cast<int>(f);
		double d = static_cast<double>(f);

		//char
		if (std::isnan(f) || std::isinf(f) || f < 0.0f || f > 127.0f)
			std::cout << "char : impossible" << std::endl;
		else if (f < 32.0f || f == 127.0f)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
		
		//int
		if (std::isnan(f) || std::isinf(f) || f > static_cast<float>(std::numeric_limits<int>::max()) ||
			f < static_cast<float>(std::numeric_limits<int>::min()))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
		
		// Float
		if (std::isnan(f))
			std::cout << "float: nanf" << std::endl;
		else if (std::isinf(f))
			std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
		else if (f == static_cast<int>(f))
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
		
		// Double
		if (std::isnan(d))
			std::cout << "double: nan" << std::endl;
		else if (std::isinf(d))
			std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
		else if (d == static_cast<int>(d))
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
	else if (isDouble(literal)) {
		double d = atof(literal.c_str());
		char c = static_cast<char>(d);
		int i = static_cast<int>(d);
		float f = static_cast<float>(d);

		//char
		if (std::isnan(d) || std::isinf(d) || d < 0.0 || d > 127.0)
			std::cout << "char: impossible" << std::endl;
		else if (d < 32.0 || d == 127.0)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << c << "'" << std::endl;
		
		//int
		if (std::isnan(d) || std::isinf(d) || d > static_cast<double>(std::numeric_limits<int>::max()) ||
			d < static_cast<double>(std::numeric_limits<int>::min()))
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << i << std::endl;

		//float
		if (std::isnan(f))
			std::cout << "float: nanf" << std::endl;
		else if (std::isinf(f))
			std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
		else if (f == static_cast<int>(f))
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
		
		//double
		if (std::isnan(d))
			std::cout << "double: nan" << std::endl;
		else if (std::isinf(d))
			std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
		else if (d == static_cast<int>(d))
			std::cout << "double: " << d << ".0" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
	else
		std::cout << "Error: invalid input format" << std::endl;
}