
#include "parsing.h"
#include "cstring"

Parsing::Parsing(std::string command){

    size_t pos = 0;
    std::string token;
    while ((pos = command.find(' ')) != std::string::npos)
    {
        token = command.substr(0, pos);
        m_commands.push_back(token);
        command.erase(0, pos + 1);
    }
    m_commands.push_back(command);

}

const std::vector<std::string>& Parsing::getCommands(){ return m_commands;}
