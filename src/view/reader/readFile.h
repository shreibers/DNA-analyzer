//
// Created by a on 6/30/20.
//

#ifndef DNA_READFILE_H
#define DNA_READFILE_H

#include "iRead.h"


class ReadFile: public IRead {
public:
    ReadFile(const std::string& file_name);
    std::string read()const;

private:
    std::string m_file_name;
};


#endif //DNA_READFILE_H
