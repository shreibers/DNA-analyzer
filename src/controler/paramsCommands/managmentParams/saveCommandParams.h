//
// Created by a on 9/15/20.
//

#ifndef SRC_SAVECOMMANDPARAMS_H
#define SRC_SAVECOMMANDPARAMS_H

#include <string>
#include <vector>
#include "../iCommandParams.h"

typedef std::vector<std::string> args;

class SaveCommandParams :public ICommandParams{
public:

    /*virtual*/ void validArgs(args& args_cmd);
    enum params{
        seq = 1,
        file_name
    };

private:
    void isSeq(std::string &param);
    void validLenParams(args &args_cmd);
};


#endif //SRC_SAVECOMMANDPARAMS_H
