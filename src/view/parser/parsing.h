//
// Created by a on 7/5/20.
//

#ifndef DNA_PARSING_H
#define DNA_PARSING_H

#include <string>
#include <vector>

class Parsing {
public:
    Parsing(std::string command);
    const std::vector<std::string>& getCommands();

private:
    std::vector<std::string> m_commands;
};


#endif //DNA_PARSING_H
