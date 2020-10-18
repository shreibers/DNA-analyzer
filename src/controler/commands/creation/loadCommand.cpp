
#include <sstream>
#include "loadCommand.h"
#include "../../../view/reader/readFile.h"
#include "../../../model/DNA/dnaContainer.h"

std::string LoadCommand::run(std::vector<std::string> params) {
    std::ostringstream castToStr;
    std::string data;
    ReadFile fileReader(params[1]);

    MetaDataDNA *metaDataDna = new MetaDataDNA(fileReader.read(), params[2]);

    DNAContainer::getDNAContainer().insert(metaDataDna);

    castToStr << DNAContainer::getDNAContainer().getIdByName(metaDataDna->getName());
    size_t len = metaDataDna->getDnaSeq().getLengthSequence();
    if(len<=40){
        return "[" + castToStr.str() + "] " + metaDataDna->getName() + ": " + metaDataDna->getDnaSeq().getDnaAsString() + "\n";

    }
    else{
        return "[" + castToStr.str() + "] " + metaDataDna->getName() + ": " + metaDataDna->getDnaSeq().slice(0, 32).getDnaAsChar()
               + "..." + metaDataDna->getDnaSeq().slice(len - 4, len - 1).getDnaAsChar() + "\n";

    }
}


