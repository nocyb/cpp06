/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:49:32 by njung             #+#    #+#             */
/*   Updated: 2026/01/13 15:56:30 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#include <iomanip>

class ScalarConverter
{
    public:
    static void convert(const std::string& literal);
    ~ScalarConverter();

    private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const & other);
    ScalarConverter & operator=(ScalarConverter const & other);
};