#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif