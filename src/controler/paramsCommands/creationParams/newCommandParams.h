#ifndef SRC_NEWCOMMANDPARAMS_H
#define SRC_NEWCOMMANDPARAMS_H



#include "iCreationParams.h"

class NewCommandParams : public ICreationParams{
public:
    /*virtual*/ void validArgs(args& args_cmd);

};



#endif //SRC_NEWCOMMANDPARAMS_H
