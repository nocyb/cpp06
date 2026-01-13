/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:49:32 by njung             #+#    #+#             */
/*   Updated: 2026/01/13 19:47:58 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <climits>
#include <iomanip>
#include <cstdlib>


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