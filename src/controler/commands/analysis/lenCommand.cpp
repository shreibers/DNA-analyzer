#include <sstream>
#include "lenCommand.h"
#include "../../../model/DNA/dnaContainer.h"

std::string LenCommand::run(std::vector<std::string> vector){
    std::ostringstream castToStr;
    std::stringstream castToNum(vector[1]);
    size_t id;
    castToNum >> id;

    castToStr << DNAContainer::getDNAContainer().getMetaDataById(id)->getDnaSeq().getLengthSequence();
    return  castToStr.str() + '\n';
}

