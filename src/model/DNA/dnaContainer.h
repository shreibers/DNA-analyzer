
#ifndef DNA_DNA_H
#define DNA_DNA_H

#include <iostream>
#include <map>
#include "metaDataDNA.h"

class DNAContainer {
    public:
        bool insert(MetaDataDNA* dna);

        static DNAContainer& getDNAContainer(){
            static DNAContainer dna;
            return dna;
        }

    MetaDataDNA* getMetaDataById(const size_t id){
        if(m_name_hash.find(id) != m_name_hash.end()){
            return m_name_hash.at(id);
        }
        return NULL;

    }

    size_t getIdByName(const std::string& name){
        if(m_id_hash.find(name) != m_id_hash.end()){
            return m_id_hash.at(name);
        }
        return 0;

    }
     MetaDataDNA* getMetaDataByName(const std::string& name){
         if(m_name_hash.find(m_id_hash[name]) != m_name_hash.end()){
             return m_name_hash.at(m_id_hash[name]);
         }
         return NULL;
    }

private:
    DNAContainer(): m_id_dna(1){}
    DNAContainer(const DNAContainer& other){}
    std::map<std::string ,size_t > m_id_hash;
    std::map<size_t , MetaDataDNA*> m_name_hash;
    size_t m_id_dna;

};


#endif //DNA_DNA_H
