//
// Created by a on 9/22/20.
//

#ifndef SRC_FINDALLCOMMAND_H
#define SRC_FINDALLCOMMAND_H


#include "../Icommand.h"

class Findall: public ICommand{
public:
    std::string run(std::vector<std::string>params);
};



#endif //SRC_FINDALLCOMMAND_H
