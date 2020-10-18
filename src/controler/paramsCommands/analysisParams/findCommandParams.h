//
// Created by a on 9/22/20.
//

#ifndef SRC_FINDCOMMANDPARAMS_H
#define SRC_FINDCOMMANDPARAMS_H

#include "../iCommandParams.h"
#include "../../../exception/myException.h"

class FindCommandParams: public ICommandParams{
public:
    /*virtual*/ void validArgs(args& args_cmd);

private:
    void isIdParam(std::string &param);

};

#endif //SRC_FINDCOMMANDPARAMS_H
