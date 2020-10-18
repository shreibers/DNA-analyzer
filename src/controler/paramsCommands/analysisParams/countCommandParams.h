//
// Created by a on 9/22/20.
//

#ifndef SRC_COUNTCOMMANDPARAMS_H
#define SRC_COUNTCOMMANDPARAMS_H

#include "../iCommandParams.h"

class CountCommandParams: public ICommandParams{
public:
    /*virtual*/ void validArgs(args& args_cmd);

private:
    void isIdParam(std::string &param);

};

#endif //SRC_COUNTCOMMANDPARAMS_H
