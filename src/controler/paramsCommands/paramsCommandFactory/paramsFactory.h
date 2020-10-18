
#ifndef SRC_PARAMSFACTORY_H
#define SRC_PARAMSFACTORY_H


#include <map>
#include "../iCommandParams.h"

typedef std::map<const std::string, ICommandParams*> commands_params;

class paramsFactory {
public:
    ICommandParams* getParamsCmd(const std::string& cmd){ return s_commands_map.at(cmd);}

protected:
    static commands_params initMapCommand();

private:
    static commands_params s_commands_map;
};


#endif //SRC_PARAMSFACTORY_H
