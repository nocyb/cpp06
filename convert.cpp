/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <njung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:51:11 by njung             #+#    #+#             */
/*   Updated: 2026/01/06 19:23:51 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & other)
{
    *this = other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool isSpecial(const std::string& literal) {
    return (literal == "nan" || literal == "nanf" ||
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff");
}

bool isChar(const std::string& literal)
{
    if (literal.length() == 1)
    {
        if (!isdigit(literal[0]))
            return true;
    }
    return false;
}

bool isInt(const std::string& literal)
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

bool isFloat(const std::string& literal)
{
    if (literal.empty())
        return false;
    int end = literal.length() - 1;
    if (literal[end] != 'f')
        return false;
    int nbPoints = 0;
    int nbDigit = 0;
    int i = 0;
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

bool isDouble(const std::string& literal)
{
    if (literal.empty())
        return false;
    int nbPoints = 0;
    int nbDigit = 0;
    int i = 0;
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
void ScalarConverter::convert(const std::string& literal)
{
    if (isSpecial(literal))
    {
        // impossible blabla;
    }
}