//
// Created by a on 9/21/20.
//

#ifndef SRC_ICREATIONPARAMS_H
#define SRC_ICREATIONPARAMS_H


#include "../iCommandParams.h"

class ICreationParams: public ICommandParams {

protected:
    void validLenParams(args& args_cmd);
    void validNameArg(args& args_cmd, const std::string &defaultName);
    void mapInsert(args& args_cmd);
    enum params{
        command,
        seq,
        seq_name
    };

private:
    static std::map<const std::string, size_t > s_counter_names_map;

};



#endif //SRC_ICREATIONPARAMS_H
