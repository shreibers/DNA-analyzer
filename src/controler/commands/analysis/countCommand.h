//
// Created by a on 9/22/20.
//

#ifndef SRC_COUNTCOMMAND_H
#define SRC_COUNTCOMMAND_H


#include <sstream>
#include "../Icommand.h"

class Count: public ICommand{
public:
    std::string run(std::vector<std::string> params);
};



#endif //SRC_COUNTCOMMAND_H
