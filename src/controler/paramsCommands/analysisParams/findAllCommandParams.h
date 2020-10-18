//
// Created by a on 9/22/20.
//

#ifndef SRC_FINDALLCOMMANDPARAMS_H
#define SRC_FINDALLCOMMANDPARAMS_H


#include "../iCommandParams.h"

class FindAllCommandParams: public ICommandParams{
public:
    /*virtual*/ void validArgs(args& args_cmd);

private:
    void isIdParam(std::string &param);

};


#endif //SRC_FINDALLCOMMANDPARAMS_H
