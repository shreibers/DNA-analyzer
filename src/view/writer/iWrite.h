//
// Created by a on 6/30/20.
//

#ifndef DNA_IWRITE_H
#define DNA_IWRITE_H


#include <string>

class IWrite {
public:
    virtual ~IWrite(){};
    virtual void write(const std::string& sequence)const=0;

};


#endif //DNA_IWRITE_H
