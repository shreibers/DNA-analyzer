//
// Created by a on 6/30/20.
//
#include <fstream>
#include "readFile.h"
#include "../../exception/myException.h"
#include "../../controler/exception/myException.h"

ReadFile::ReadFile(const std::string& file_name):m_file_name(file_name){}



std::string ReadFile::read()const{
    std::string line;
    std::string new_line;
    std::ifstream file(m_file_name.c_str());
    try {
        if (!file.is_open()) {
            throw std::ofstream::failure("Exception opening file");
        }
    }

    catch (std::ofstream::failure& e) {
        throw (MyException(e.what())) ;
    }

    while (getline(file, line)){
        new_line+=line;
    }
    file.close();


    return new_line;
}

