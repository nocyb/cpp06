/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realtype.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njung <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 16:46:18 by njung             #+#    #+#             */
/*   Updated: 2026/01/14 18:27:02 by njung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <string>

class Base
{
    public:
    virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base * generate(void);
void identify(Base *p);
void identify(Base &p);