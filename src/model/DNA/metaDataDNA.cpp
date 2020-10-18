
#include "metaDataDNA.h"
#include <iostream>


MetaDataDNA::MetaDataDNA(const DnaSequence& dnaSequence, const std::string& name)try: m_dna_seq(dnaSequence), m_name(name){
    m_status.setStatus(E_new);

}
catch(std::invalid_argument& error){
    throw;
}


