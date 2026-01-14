/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realtype.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:46:12 by njung             #+#    #+#             */
/*   Updated: 2026/01/14 18:28:10 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "realtype.hpp"

Base::~Base() {}

Base * generate(void)
{
    int random = std::rand() % 3;
    if (random == 0)
    {
        std::cout << "Generated: A" << std::endl;
        return new A;
    }
    if (random == 1)
    {
        std::cout << "Generated: B" << std::endl;
        return new B;
    }
    if (random == 2)
    {
        std::cout << "Generated: C" << std::endl;
        return new C;
    }
    return 0;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
        return;
    }
    catch (const std::exception& e) {}
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B" << std::endl;
        return;
    }
    catch (const std::exception& e) {}
    try
    {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C" << std::endl;
        return;
    }
    catch (const std::exception& e) {}
}