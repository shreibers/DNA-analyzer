
#ifndef DNA_PROGRAM_LOADCOMMAND_H
#define DNA_PROGRAM_LOADCOMMAND_H


#include <string>
#include <vector>
#include "../Icommand.h"

class LoadCommand: public ICommand {
public:
    std::string run(std::vector<std::string> vector);
};


#endif //DNA_PROGRAM_LOADCOMMAND_H
