

#include <sstream>

#include "findCommandParams.h"
#include "../../../model/DNA/dnaContainer.h"
#include "../../exception/myException.h"

void FindCommandParams::validArgs(args &args_cmd) {
    if(args_cmd.size() != 3){
        throw MyException("Error: the num of params is invalid");
    }

    if(args_cmd[1][0] == '#'){
        isIdParam(args_cmd[1]);
    }

    if(args_cmd[2][0] == '#'){
        isIdParam(args_cmd[2]);
        std::stringstream castToNum(args_cmd[2]);
        size_t id;
        castToNum >> id;
        args_cmd[2] = DNAContainer::getDNAContainer().getMetaDataById(id)->getDnaSeq().getDnaAsString();

    }

    try{
        DnaSequence dna = DnaSequence(args_cmd[2]);
    }
    catch (std::exception & exception){
        throw exception.what();
    }
}

void FindCommandParams::isIdParam(std::string &param) {
    param = param.substr(1, (param.length() - 1));
    std::stringstream castToNum(param);
    size_t id;
    castToNum >> id;
    if (!DNAContainer::getDNAContainer().getMetaDataById(id)){
        throw MyException("Error: invalid id");
    }

}
