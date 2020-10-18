//
// Created by a on 7/5/20.
//

#include <iostream>
#include "readConsule.h"

std::string ReadConsule::read()const{

   std::string line;
   getline(std::cin, line);
   return line;
}