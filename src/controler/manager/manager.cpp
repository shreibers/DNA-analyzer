
#include "manager.h"
#include "../../view/reader/readConsule.h"
#include "../../view/parser/parsing.h"
#include "../../view/writer/WriteToConsule.h"
#include "../exception/myException.h"
#include "../commands/commandsFactory/commandFactory.h"
#include "../paramsCommands/paramsCommandFactory/paramsFactory.h"

void manager::run(){
    ReadConsule read_consule;
    WriteToConsule write_to_consule;
    Command_factory  factory;
    std::string input;


    while(true){
        write_to_consule.write("> cmd >>> ");
        input = read_consule.read();
        Parsing parsing(input);
        paramsFactory params_factory;
        args args_cmd = parsing.getCommands();

        try {
            params_factory.getParamsCmd(args_cmd[0])->validArgs(args_cmd);
            write_to_consule.write(factory.get_command_result(args_cmd[0])->run(args_cmd));
            write_to_consule.write("\n");
        }

        catch(MyException& error){
            write_to_consule.write(error.what());

        }
    }
}