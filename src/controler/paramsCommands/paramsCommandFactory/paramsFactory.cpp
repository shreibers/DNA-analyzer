

#include "paramsFactory.h"
#include "../creationParams/newCommandParams.h"
#include "../creationParams/loadCommandParams.h"
#include "../managmentParams/saveCommandParams.h"
#include "../analysisParams/LenCommandsParams.h"
#include "../analysisParams/findCommandParams.h"
#include "../analysisParams/findAllCommandParams.h"
#include "../analysisParams/countCommandParams.h"

commands_params paramsFactory::initMapCommand() {//return by value

    commands_params map;
    map.insert(std::pair<const std::string, ICommandParams*>("new", new NewCommandParams));
    map.insert(std::pair<const std::string, ICommandParams*>("load", new LoadCommandParams));
    map.insert(std::pair<const std::string, ICommandParams*>("save", new SaveCommandParams));
//    map.insert(std::pair<const std::string, ICommandParams*>("len", new LenCommandsParams));
    map.insert(std::pair<const std::string, ICommandParams*>("find", new FindCommandParams));
    map.insert(std::pair<const std::string, ICommandParams*>("findall", new FindAllCommandParams));
    map.insert(std::pair<const std::string, ICommandParams*>("count", new CountCommandParams));
    return map;
}

commands_params paramsFactory::s_commands_map = initMapCommand();


