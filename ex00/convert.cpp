/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:51:11 by njung             #+#    #+#             */
/*   Updated: 2026/01/13 20:00:09 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other)
{
    *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool isSpecial(const std::string &literal)
{
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff" || literal == "inf" ||
            literal == "-nan" || literal == "-nanf" ||
            literal == "inff");
}

bool isChar(const std::string &literal)
{
    if (literal.length() == 1)
    {
        if (!isdigit(literal[0]))
            return true;
    }
    return false;
}

bool isInt(const std::string &literal)
{
    size_t i = 0;

    if (literal.empty())
        return false;
    if (literal[0] == '+' || literal[0] == '-')
    {
        if (literal.length() == 1)
            return false;
        i = 1;
    }
    while (i < literal.length())
    {
        if (!isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

bool isFloat(const std::string &literal)
{
    if (literal.empty())
        return false;
    int end = literal.length() - 1;
    if (literal[end] != 'f')
        return false;
    int nbPoints = 0;
    int nbDigit = 0;
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-')
    {
        if (literal.length() < 3)
            return false;
        i = 1;
    }
    while (i < (literal.length() - 1))
    {
        if (literal[i] == '.')
        {
            nbPoints++;
            if (nbPoints > 1)
                return false;
        }
        else if (isdigit(literal[i]))
            nbDigit++;
        else
        {
            return false;
        }
        i++;
    }
    if (nbPoints == 1 && nbDigit > 0)
        return true;
    return false;
}

bool isDouble(const std::string &literal)
{
    if (literal.empty())
        return false;
    int nbPoints = 0;
    int nbDigit = 0;
    size_t i = 0;
    if (literal[0] == '+' || literal[0] == '-')
    {
        if (literal.length() < 2)
            return false;
        i = 1;
    }
    while (i < literal.length())
    {
        if (literal[i] == '.')
        {
            nbPoints++;
            if (nbPoints > 1)
                return false;
        }
        else if (isdigit(literal[i]))
            nbDigit++;
        else
        {
            return false;
        }
        i++;
    }
    if (nbPoints == 1 && nbDigit > 0)
        return true;
    return false;
}

void printChar(double value)
{
    std::cout << "char: ";
    if (value < 0 || value > 127 || std::isnan(value))
        std::cout << "impossible" << std::endl;
    else if (!isprint(static_cast<int>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    if (isSpecial(literal))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nan" || literal == "nanf")
        {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        else if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
        {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else if (literal == "-inf" || literal == "-inff")
        {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        return;
    }
    if (isChar(literal))
    {
        char c = literal[0];

        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);

        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }
    if (isInt(literal))
    {
        double temp = strtod(literal.c_str(), NULL); // overflow check
        if (temp < INT_MIN || temp > INT_MAX)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << static_cast<float>(temp) << "f" << std::endl;
            std::cout << "double: " << temp << std::endl;
            return;
        }
        int realInt = static_cast<int>(temp);
        printChar(temp);
        std::cout << "int: " << realInt << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(realInt) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(realInt) << std::endl;
        return;
    }
    if (isFloat(literal))
    {
        double temp = strtod(literal.c_str(), NULL);
        float f = static_cast<float>(temp);
        char c = static_cast<char>(f);
        int i = static_cast<int>(f);
        double d = static_cast<double>(f);
        printChar(c);
        if (temp < INT_MIN || temp > INT_MAX)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double " << d << std::endl;
        return;
    }
    if (isDouble(literal))
    {
        double realDouble = strtod(literal.c_str()  , NULL);
        char c = static_cast<char>(realDouble);
        int i = static_cast<int>(realDouble);
        float f = static_cast<float>(realDouble);
        printChar(c);
        if (realDouble < INT_MIN || realDouble > INT_MAX)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << realDouble << std::endl;
        return;
    }
    else
        std::cout << "Error" << std::endl;   
}