

#include "findCommand.h"

#include <sstream>
#include "../../../model/DNA/dnaContainer.h"

std::string Find::run(std::vector<std::string> params) {
    std::ostringstream castToStr;
    std::stringstream castToNum(params[1]);
    size_t id;
    castToNum >> id;
    castToStr << DNAContainer::getDNAContainer().getMetaDataById(id)->getDnaSeq().find(DnaSequence(params[2]), 0);
    return  castToStr.str() + '\n';
}
