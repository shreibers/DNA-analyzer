
#include "iCreationParams.h"
#include "../../exception/myException.h"

#include <sstream>


std::map<const std::string, size_t > ICreationParams::s_counter_names_map;

void ICreationParams::validLenParams(args &args_cmd) {
    if(args_cmd.size() < 2 || args_cmd.size() > 3){
        throw MyException("The num of params is invalid");
    }
}

void ICreationParams::validNameArg(args &args_cmd, const std::string &defaultName) {
    if(args_cmd.size() == 3) {
        if(args_cmd[seq_name][0] == '@'){
            args_cmd[seq_name].replace(0, 1, "");
        }
        else{

            throw MyException("Name must start with @");
        }
    }
    else{

        args_cmd.push_back(defaultName);
    }
}

void ICreationParams::mapInsert(args &args_cmd) {
    std::ostringstream cast_to_str;
    if(args_cmd[seq_name][-1] == '_'){
        if(ICreationParams::s_counter_names_map.find(args_cmd[seq_name]) != ICreationParams::s_counter_names_map.end()){
            cast_to_str << ++ICreationParams::s_counter_names_map.at(args_cmd[seq_name]);
            args_cmd[seq_name] += cast_to_str.str();
        }
        ICreationParams::s_counter_names_map.insert(std::pair<const std::string, size_t>(args_cmd[seq_name], 0));

    }
    if(ICreationParams::s_counter_names_map.find(args_cmd[seq_name]) != ICreationParams::s_counter_names_map.end()){
        cast_to_str << ++ICreationParams::s_counter_names_map.at(args_cmd[seq_name]);
        args_cmd[seq_name] += cast_to_str.str();
    }
    ICreationParams::s_counter_names_map.insert(std::pair<const std::string, size_t>(args_cmd[seq_name], 0));
}

