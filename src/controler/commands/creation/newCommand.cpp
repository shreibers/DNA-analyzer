
#include <stdexcept>
#include "newCommand.h"
#include "../../../model/DNA/dnaContainer.h"
#include <sstream>


std::string NewCommand::run(std::vector<std::string> params){
    std::ostringstream castToStr;
    MetaDataDNA* metaDataDna = new MetaDataDNA(params[seq], params[seq_name]);

    DNAContainer::getDNAContainer().insert(metaDataDna);


    size_t len = metaDataDna->getDnaSeq().getLengthSequence();
    castToStr << DNAContainer::getDNAContainer().getIdByName(metaDataDna->getName());
    if(len>40){
        return "[" + castToStr.str() + "] " + metaDataDna->getName() + ": " + metaDataDna->getDnaSeq().slice(0, 32).getDnaAsChar() + "..." +
               metaDataDna->getDnaSeq().slice(len - 4, len - 1).getDnaAsChar() + "\n";
    }
    else{
        return "[" + castToStr.str() + "] " + metaDataDna->getName() + ": " + metaDataDna->getDnaSeq().getDnaAsChar() + "\n";
    }




}
