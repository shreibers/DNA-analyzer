
#include "dnaContainer.h"
#include "metaDataDNA.h"


bool DNAContainer::insert(MetaDataDNA* dna){
    if(m_id_hash.find(dna->getName()) != m_id_hash.end()){
        return false;
    }
    m_id_hash.insert(std::pair<std::string, size_t>(dna->getName(), m_id_dna));
    m_name_hash.insert(std::pair<size_t, MetaDataDNA*>(m_id_dna, dna));
    ++m_id_dna;
    return true;
}