
#include "saveCommandParams.h"
#include "../../exception/myException.h"
#include "../../../model/DNA/dnaContainer.h"

void SaveCommandParams::validArgs(args& params) {
    std::string soffix_file;

    validLenParams(params);
    isSeq(params[seq]);

    if (params.size() == 3) {
        size_t pos = params[file_name].find('.');
        soffix_file = params[file_name].substr(pos + 1, params[file_name].size() - 1);
        if (soffix_file != "rawdna") {
            throw MyException("Name must sofix with 'rawdna'");
        }
    }

    else {
        params.push_back(params[seq] + ".rawdna");
    }
}

void SaveCommandParams::isSeq(std::string &param) {
    if (!DNAContainer::getDNAContainer().getMetaDataByName(param)){
        throw MyException("Error: invalid seq");
    }

}

void SaveCommandParams::validLenParams(args &args_cmd) {
    if(args_cmd.size() < 2 || args_cmd.size() > 3){
        throw MyException("The num of params is invalid");
    }
}





