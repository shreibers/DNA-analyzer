
#include "saveCommand.h"
#include "../../../view/writer/writeToFile.h"
#include "../../../model/DNA/dnaContainer.h"

std::string SaveCommand::run(std::vector<std::string> params) {

    WriteToFile writeToFile(params[file_name]);

    writeToFile.write((DNAContainer::getDNAContainer().getMetaDataByName(params[seq])->getDnaSeq().getDnaAsChar()));

    return "";
}