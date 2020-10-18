
#include "commandFactory.h"

#include "../managment/saveCommand.h"
#include "../creation/newCommand.h"
#include "../creation/loadCommand.h"
#include "../analysis/lenCommand.h"
#include "../analysis/findCommand.h"
#include "../analysis/findallCommand.h"
#include "../analysis/countCommand.h"


commands_params_map Command_factory:: init_map_command() {

    commands_params_map map;
    map.insert(std::pair<const std::string, ICommand*>("new", new NewCommand));
    map.insert(std::pair<const std::string, ICommand*>("load", new LoadCommand));
    map.insert(std::pair<const std::string, ICommand*>("save", new SaveCommand));
//    map.insert(std::pair<const std::string, ICommand*>("len", new LenCommand));
    map.insert(std::pair<const std::string, ICommand*>("find", new Find));
    map.insert(std::pair<const std::string, ICommand*>("findall", new Findall));
    map.insert(std::pair<const std::string, ICommand*>("count", new Count));

    return map;
}



commands_params_map Command_factory::s_commands_map = init_map_command();

ICommand* Command_factory::get_command_result(const std::string& cmd){
        return s_commands_map.at(cmd);
}

