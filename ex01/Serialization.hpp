/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 20:02:55 by njung             #+#    #+#             */
/*   Updated: 2026/01/14 16:29:07 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cctype>
#include <climits>
#include <iomanip>
#include <cstdlib>
#include <stdint.h>

struct Data {
    int id;
    std::string name;
};

class Serializer
{
    public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
    ~Serializer();

    private:
    Serializer();
    Serializer(Serializer const & other);
    Serializer & operator=(Serializer const & other);
};