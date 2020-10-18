//
// Created by a on 7/5/20.
//

#ifndef DNA_READCONSULE_H
#define DNA_READCONSULE_H

#include "iRead.h"

class ReadConsule :public IRead{
public:
    std::string read()const;
};


#endif //DNA_READCONSULE_H
