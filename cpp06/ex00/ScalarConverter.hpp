#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>   // INT_MIN, INT_MAX
#include <cstdlib>  // strtol
#include <cerrno>   // errno, ERANGE
#include <cmath>
#include <iomanip>

class ScalarConverter {
    public :
        static void convert(const std::string value);
};

#endif