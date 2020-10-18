#include <sstream>

#include "LenCommandsParams.h"
#include "../../exception/myException.h"
#include "../../../model/DNA/dnaContainer.h"

void LenCommandsParams::validArgs(args& args_cmd){
    if(args_cmd.size() != 2){
        throw MyException("Error: The num of params is invalid");
    }

    else if(args_cmd[1][0] != '#'){
        throw MyException("Error: Id must start with #");
    }
    else{
        args_cmd[1] = args_cmd[1].substr(1, (args_cmd[1].length()-1));
    }


    std::stringstream castToNum(args_cmd[1]);
    size_t id;
    castToNum >> id;
    if (!DNAContainer::getDNAContainer().getMetaDataById(id)){
        throw MyException("Error: invalid id");
    }

}