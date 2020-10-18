//
// Created by a on 9/22/20.
//

#include "findallCommand.h"
#include <sstream>
#include <iterator>
#include "../../../model/DNA/dnaContainer.h"

std::string Findall::run(std::vector<std::string> params) {
    std::ostringstream castToStr;
    std::stringstream castToNum(params[1]);
    std::ostringstream vts;
    size_t id;
    castToNum >> id;
    std::vector<size_t >result = DNAContainer::getDNAContainer().getMetaDataById(id)->getDnaSeq().findAll(DnaSequence(params[2]));

    if (!result.empty())
    {
        std::copy(result.begin(), result.end() - 1, std::ostream_iterator<size_t >(vts, ", "));

        vts << result.back();
    }

    return  vts.str() + '\n';
}

