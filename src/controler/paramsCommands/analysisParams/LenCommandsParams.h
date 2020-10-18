
#ifndef SRC_LENCOMMANDSPARAMS_H
#define SRC_LENCOMMANDSPARAMS_H


#include "../iCommandParams.h"

class LenCommandsParams :public ICommandParams{
public:
    /*virtual*/ void validArgs(args& args_cmd);
};


#endif //SRC_LENCOMMANDSPARAMS_H
