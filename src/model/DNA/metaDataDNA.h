//
// Created by a on 7/5/20.
//

#ifndef DNA_METADATADNA_H
#define DNA_METADATADNA_H

#include "dnaSequence.h"
#include "status.h"


class MetaDataDNA{
public:
    MetaDataDNA(const DnaSequence& dnaSequence, const std::string& name);
    const std::string& getName()const{ return m_name;}
    DnaSequence& getDnaSeq(){ return m_dna_seq;}


private:
    DnaSequence m_dna_seq;
    std::string m_name;
    Status m_status;
};


#endif //DNA_METADATADNA_H
