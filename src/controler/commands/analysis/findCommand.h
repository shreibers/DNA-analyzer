
#ifndef SRC_FINDCOMMAND_H
#define SRC_FINDCOMMAND_H


#include "../Icommand.h"

class Find: public ICommand{
public:
    std::string run(std::vector<std::string>params);
};



#endif //SRC_FINDCOMMAND_H
