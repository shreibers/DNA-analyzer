//
// Created by a on 9/21/20.
//

#ifndef SRC_LENCOMMAND_H
#define SRC_LENCOMMAND_H


#include "../Icommand.h"

class LenCommand : public ICommand {
public:
    std::string run(std::vector<std::string> vector);
};


#endif //SRC_LENCOMMAND_H
