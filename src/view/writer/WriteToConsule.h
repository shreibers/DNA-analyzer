//
// Created by a on 7/5/20.
//

#ifndef DNA_WRITETOCONSULE_H
#define DNA_WRITETOCONSULE_H

#include <iostream>
#include "iWrite.h"


class WriteToConsule : public IWrite{
public:
    void write(const std::string& sequence)const{std::cout<<sequence;}
};


#endif //DNA_WRITETOCONSULE_H
