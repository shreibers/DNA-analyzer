

#ifndef DNA_PROGRAM_SAVECOMMAND_H
#define DNA_PROGRAM_SAVECOMMAND_H


#include "../Icommand.h"

class SaveCommand : public ICommand{
public:
    std::string run(std::vector<std::string> params);
    enum params{
        seq = 1,
        file_name
    };

};


#endif //DNA_PROGRAM_SAVECOMMAND_H
