/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 17:05:40 by njung             #+#    #+#             */
/*   Updated: 2026/01/14 18:27:04 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "realtype.hpp"

int main() {
    std::srand(std::time(0));

    Base* obj = generate();

    std::cout << "Identify with pointer: ";
    identify(obj);

    std::cout << "Identify with reference: ";
    identify(*obj);

    delete obj;
    return 0;
}