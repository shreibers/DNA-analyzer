//
// Created by a on 6/30/20.
//
#include <fstream>
#include <iostream>
#include "writeToFile.h"

WriteToFile::WriteToFile(const std::string& name_file):m_name_file(name_file){}


void WriteToFile::write(const std::string& sequence) const {

    std::ofstream my_file;
    my_file.open(m_name_file.c_str());
    if(!my_file.is_open()){
        throw std::ifstream::failure("Exception opening file\n");
    }
    my_file << sequence <<"\n";
    my_file.close();

}

