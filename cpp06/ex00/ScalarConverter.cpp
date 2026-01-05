#include "ScalarConverter.hpp"

bool isPseudo(const std::string& s) {
    return (s == "nan" || s == "nanf" || s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff");
}

bool isInt(const std::string& s) {
    char* end;
    std::strtol(s.c_str(), &end, 10);
    return (*end == '\0');
}

bool isChar(const std::string& s) {
    return (s.length() == 1 && !std::isdigit(s[0]));
}

bool isFloat(const std::string& s) {
    if (s[s.length() - 1] != 'f')
        return false;
    char* end;
    std::strtof(s.c_str(), &end);
    return (end == s.c_str() + s.length() - 1);
}

bool isDouble(const std::string& s) {
    char* end;
    std::strtod(s.c_str(), &end);
    return (*end == '\0');
}

void ScalarConverter::convert (const std::string value) {

    std::cout << std::fixed << std::setprecision(1);

    if (isInt(value)) {
        char* end;
        errno = 0;
        long l = std::strtol(value.c_str(), &end, 10);

        if (errno == ERANGE || l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max()) {

            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }

        int i = static_cast<int>(l);

        if (i >= 32 && i <= 126)
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
        return;
    }

    if (isChar(value)) {
        char c = value[0];

        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    if (isFloat(value)) {
        float f = std::strtof(value.c_str(), NULL);

        if (std::isnan(f) || f < 0 || f > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<char>(f)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;

        if (f < std::numeric_limits<int>::min() ||
            f > std::numeric_limits<int>::max() ||
            std::isnan(f) || std::isinf(f))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;

        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        return;
    }

    if (isDouble(value)) {
        double d = std::strtod(value.c_str(), NULL);

        if (std::isnan(d) || d < 0 || d > 127)
            std::cout << "char: impossible" << std::endl;
        else if (!std::isprint(static_cast<char>(d)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;

        if (d < std::numeric_limits<int>::min() ||
            d > std::numeric_limits<int>::max() ||
            std::isnan(d) || std::isinf(d))
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;

        if (d < -std::numeric_limits<float>::max() ||
            d > std::numeric_limits<float>::max())
            std::cout << "float: impossible" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

        std::cout << "double: " << d << std::endl;
        return;
    }

    if (isPseudo(value)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (value == "nan" || value == "nanf") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (value[0] == '-') {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        } else {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        return;
    }

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}