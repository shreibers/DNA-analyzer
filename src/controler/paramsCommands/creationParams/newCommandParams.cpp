
#include <exception>
#include "newCommandParams.h"
#include "../../exception/myException.h"
#include "../../../model/DNA/dnaSequence.h"

void NewCommandParams::validArgs(args& args_cmd){
    validLenParams(args_cmd);

    try{
        DnaSequence dna = DnaSequence(args_cmd[seq]);

    }
    catch (std::exception & e){
        throw MyException(e.what());
    }

    ICreationParams::validNameArg(args_cmd, "seq");
    mapInsert(args_cmd);

}
