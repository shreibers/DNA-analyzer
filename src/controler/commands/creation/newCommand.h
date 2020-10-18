//
// Created by a on 7/5/20.
//

#ifndef DNA_NEWCOMMAND_H
#define DNA_NEWCOMMAND_H

#include <bits/basic_string.h>
#include <vector>

#include "../Icommand.h"

class NewCommand :public ICommand{
public:
    enum params{
        command,
        seq,
        seq_name
    };
    std::string run(std::vector<std::string> params);
};


#endif //DNA_NEWCOMMAND_H
