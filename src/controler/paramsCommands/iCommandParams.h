

#ifndef SRC_IPARAMS_H
#define SRC_IPARAMS_H

#include <string>
#include <vector>
#include <map>

typedef std::vector<std::string> args;

class ICommandParams {
public:
    virtual ~ICommandParams(){}
    virtual void validArgs(args& args_cmd)=0;

};


#endif //SRC_IPARAMS_H
