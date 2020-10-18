//
// Created by a on 6/30/20.
//

#ifndef DNA_IREAD_H
#define DNA_IREAD_H


#include <string>

class IRead {
public:
    virtual ~IRead(){}
    virtual std::string read()const =0;

};


#endif //DNA_IREAD_H
