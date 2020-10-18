//
// Created by a on 7/5/20.
//

#ifndef DNA_ICOMMAND_H
#define DNA_ICOMMAND_H

#include <vector>
#include <iostream>

class ICommand {
public:
    virtual ~ICommand(){}
    virtual std::string run(std::vector<std::string> vec)=0;
};


#endif //DNA_ICOMMAND_H
