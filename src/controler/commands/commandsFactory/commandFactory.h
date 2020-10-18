//
// Created by a on 7/5/20.
//

#ifndef DNA_COMMAND_FACTORY_H
#define DNA_COMMAND_FACTORY_H

#include <map>
#include "../Icommand.h"

typedef std::map<const std::string, ICommand*> commands_params_map;
typedef std::vector<std::string> args;

class Command_factory {
public:
    ICommand* get_command_result(const std::string& cmd);

protected:
    static commands_params_map init_map_command();

private:
    static commands_params_map s_commands_map;

};




#endif //DNA_COMMAND_FACTORY_H
