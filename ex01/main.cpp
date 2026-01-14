/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:26:13 by njung             #+#    #+#             */
/*   Updated: 2026/01/14 16:29:10 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <iostream>

int main()
{
    Data myData;
    myData.id = 42;
    myData.name = "Example Data";

    std::cout << "Original address: " << &myData << std::endl;
    std::cout << "Original values: " << myData.id << ", " << myData.name << std::endl;

    uintptr_t raw = Serializer::serialize(&myData);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Deserialized address: " << ptr << std::endl;
    std::cout << "Deserialized values: " << ptr->id << ", " << ptr->name << std::endl;

    if (ptr == &myData) {
        std::cout << "SUCCESS: Pointers are equal." << std::endl;
    } else {
        std::cout << "FAILURE: Pointers are different." << std::endl;
    }
    return 0;
}