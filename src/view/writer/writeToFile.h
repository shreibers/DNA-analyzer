//
// Created by a on 6/30/20.
//

#ifndef DNA_WRITETOFILE_H
#define DNA_WRITETOFILE_H

#include <string>
#include "iWrite.h"

class WriteToFile {
public:
    WriteToFile(const std::string& name_file);
    void write(const std::string& sequence)const;
private:
    std::string m_name_file;
};


#endif //DNA_WRITETOFILE_H
