
#include "loadCommandParams.h"

#include "../../../view/reader/readFile.h"
#include "../../exception/myException.h"

void LoadCommandParams::validArgs(args &params) {
    validLenParams(params);
    size_t pos = params[seq].find('.');

    if (!(params[seq].substr(pos+1, params[seq].size() - 1) == "rawdna")) {
        throw MyException("Name file must soffix with 'rawdna'");
    }
    try{
        ReadFile fileReader(params[seq]);

        if(fileReader.read().empty()){
            throw MyException("The file is empty");
        }
    }
    catch (const MyException& e){
        throw e;
    }


    ICreationParams::validNameArg(params, params[seq].substr(0, pos));
    mapInsert(params);



}

