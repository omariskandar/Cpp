/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omar-iskandarani <omar-iskandarani@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 22:58:05 by omar-iskand       #+#    #+#             */
/*   Updated: 2025/08/24 22:58:56 by omar-iskand      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter() {}

bool ScalarConverter::isChar(const std::string& s) {
    return (s.length() == 1 && !isdigit(s[0]));
}

bool ScalarConverter::isInt(const std::string& s) {
    char* end;
    strtol(s.c_str(), &end, 10);
    return (*end == '\0');
}

bool ScalarConverter::isFloat(const std::string& s) {
    if (s == "nanf" || s == "+inff" || s == "-inff") return true;
    char* end;
    strtof(s.c_str(), &end);
    return (*end == 'f' && *(end + 1) == '\0');
}

bool ScalarConverter::isDouble(const std::string& s) {
    if (s == "nan" || s == "+inf" || s == "-inf") return true;
    char* end;
    strtod(s.c_str(), &end);
    return (*end == '\0');
}

void ScalarConverter::convert(const std::string& literal) {
    std::cout.setf(std::ios::fixed);
    std::cout.precision(1);

    if (isChar(literal)) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    // INT
    if (isInt(literal)) {
        long val = strtol(literal.c_str(), NULL, 10);
        if (val < CHAR_MIN || val > CHAR_MAX)
            std::cout << "char: impossible" << std::endl;
        else if (!isprint(static_cast<char>(val)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;

        std::cout << "int: " << val << std::endl;
        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(val) << std::endl;
        return;
    }

    if (isFloat(literal)) {
        float val = strtof(literal.c_str(), NULL);
        if (std::isnan(val) || std::isinf(val))
            std::cout << "char: impossible" << std::endl;
        else if (!isprint(static_cast<char>(val)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;

        if (val > INT_MAX || val < INT_MIN)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(val) << std::endl;

        std::cout << "float: " << val << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(val) << std::endl;
        return;
    }

    // DOUBLE
    if (isDouble(literal)) {
        double val = strtod(literal.c_str(), NULL);
        if (std::isnan(val) || std::isinf(val))
            std::cout << "char: impossible" << std::endl;
        else if (!isprint(static_cast<char>(val)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;

        if (val > INT_MAX || val < INT_MIN)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(val) << std::endl;

        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
        std::cout << "double: " << val << std::endl;
        return;
    }
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}
