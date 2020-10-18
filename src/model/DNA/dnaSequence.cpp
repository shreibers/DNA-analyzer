

#include "dnaSequence.h"
#include <cstring>

const char* DnaSequence::DNA_CHARS = "AGCT";

bool DnaSequence::Nucleotide::isValidChar(const char& c){
    return strchr(DNA_CHARS, c);
}

bool DnaSequence::isValidSequence(const char* dnaSequence){
    for(size_t i=0; i < strlen(dnaSequence) ;++i){

        if(!Nucleotide::isValidChar(dnaSequence[i])){
            return false;
        }
    }
    return true;
}

DnaSequence::Nucleotide* DnaSequence::initSequence(const char* dnaSequence)const{
    size_t length_of_seq= strlen(dnaSequence);
    Nucleotide *new_dna_seq = new Nucleotide[length_of_seq + 1];

    for(size_t i=0; i < length_of_seq; ++i) {
        if (dnaSequence[i] >= 97 && dnaSequence[i] <= 122) {
            new_dna_seq[i] = Nucleotide(dnaSequence[i]) - 32;
        }
        else{
            new_dna_seq[i] = Nucleotide(dnaSequence[i]);
        }

    }
    new_dna_seq[length_of_seq + 1] = '\0';

    if(!isValidSequence((char*)new_dna_seq))
        throw std::invalid_argument("Error: Invalid_argument");

    return new_dna_seq;

}

DnaSequence::Nucleotide* DnaSequence::getSeqToAssign(const DnaSequence& dnaSequence){
    Nucleotide *new_dna_seq = new Nucleotide[dnaSequence.m_length + 1];

    for(size_t i=0;  i<dnaSequence.m_length; ++i){
        new_dna_seq[i] = Nucleotide(dnaSequence[i]);
    }
    new_dna_seq[dnaSequence.m_length] = '\0';
    return new_dna_seq;
}


DnaSequence::DnaSequence(const char *dnaSequence):m_dnaSequence(initSequence(dnaSequence)), m_length(strlen(dnaSequence)) {}


DnaSequence::DnaSequence(const std::string& dnaSequence):m_dnaSequence(initSequence(dnaSequence.c_str())), m_length(strlen(dnaSequence.c_str())){}

DnaSequence::DnaSequence(const size_t size){
    m_dnaSequence = new Nucleotide[size];
    m_length = size;
}

DnaSequence::DnaSequence(const DnaSequence &dnaSequence):m_dnaSequence(getSeqToAssign(dnaSequence)),m_length(dnaSequence.m_length){}

DnaSequence::DnaSequence(const IRead* dnaSequence):m_dnaSequence(initSequence((dnaSequence->read().c_str()))), m_length(dnaSequence->read().size()){}

DnaSequence::~DnaSequence() {
    delete m_dnaSequence;
}

const char* DnaSequence::getDnaAsChar()const{
    return (char*) m_dnaSequence;
}

std::string DnaSequence::getDnaAsString()const{
    return getDnaAsChar();
}

std::ostream& operator<<(std::ostream& out,const DnaSequence& dnaSequence){
    for(size_t i = 0;i<dnaSequence.m_length;i++){
        out<<dnaSequence[i];
    }
    out<<std::endl;
    return out;
}

DnaSequence& DnaSequence::operator=(const DnaSequence& other) {
    if(other == *this)
        return *this;
    DnaSequence::Nucleotide* temp = getSeqToAssign(other);
    delete[] m_dnaSequence;
    m_dnaSequence = temp;
    m_length = other.m_length;
    return *this;
}

bool operator==(const DnaSequence& sequence1, const DnaSequence& sequence2){
    size_t i;
    size_t lengthSequence1 = sequence1.getLengthSequence();
    size_t lengthSequence2 = sequence2.getLengthSequence();
    for( i=0;i<lengthSequence1 && i<lengthSequence2;i++){
        if(sequence1[i]!=sequence2[i])
            return false;
    }
    return i==lengthSequence1&&i==lengthSequence2;
}

bool operator!=(const DnaSequence& sequence1, const DnaSequence& sequence2){
    return !(sequence1==sequence2);
}

DnaSequence::Nucleotide& DnaSequence::operator[](size_t index)const {
    if(index > m_length)
        throw std::out_of_range("Error: Index out of range");
    return m_dnaSequence[index];
}

size_t DnaSequence::getLengthSequence()const{
    return m_length;
}

DnaSequence::Nucleotide::Nucleotide() {}

DnaSequence::Nucleotide::Nucleotide(char c):m_char(c) {}

DnaSequence::Nucleotide& DnaSequence::Nucleotide::operator=(const char c){
    if(!isValidChar(c))
        throw std::invalid_argument("Error: Invalid argument");

    m_char = c;
    return *this;
}

DnaSequence::Nucleotide::operator char(){
    return m_char;
}

DnaSequence DnaSequence::slice(size_t start, size_t end){
    DnaSequence dnaSequence(end-start+1);
    for(size_t i=start;i<end;++i){
        dnaSequence[i-start] = m_dnaSequence[i];
    }
    dnaSequence[end-start] = '\0';
    return dnaSequence;

}


DnaSequence::Nucleotide DnaSequence::Nucleotide::pairToNucleotide(){
    if(this->m_char == 'A')
        return 'T';
    else if(this->m_char == 'T')
        return 'A';
    else if(this->m_char == 'G')
        return 'C';
    else
        return 'G';

}

DnaSequence DnaSequence::pairingDNA(){
    DnaSequence dnaSequence(m_length);
    for(size_t i=0;i<m_length;i++){
        dnaSequence[m_length-i-1] = m_dnaSequence[i].pairToNucleotide();
    }
    return dnaSequence;

}

size_t DnaSequence::find(const DnaSequence& dnaSequence, size_t index){
    return getDnaAsString().find(dnaSequence.getDnaAsString(), index);
}

size_t DnaSequence::count(const DnaSequence& dnaSequence){
    size_t countOccurrences=0;

    for(size_t index=find(dnaSequence);index!=std::string::npos;index=find(dnaSequence, index+1)){
        std::cout<< countOccurrences<<std::endl;
        countOccurrences++;
    }

    return countOccurrences;
}

std::vector<size_t> DnaSequence::findAll(const DnaSequence& dnaSequence) {
    std::vector<size_t> indexes;
    for (size_t index = find(dnaSequence);index != std::string::npos; index = find(dnaSequence, index + 1)) {
        indexes.push_back(index);
    }
    return indexes;

}

std::vector<size_t> DnaSequence::findConsensusSequences(DnaSequence& dnaSequence){
    std::vector<size_t> startCodon = dnaSequence.findAll("ATG");
    std::vector<size_t>::iterator it;
    std::vector<size_t> codon;
    size_t end;

    for(it=startCodon.begin(); it != startCodon.end(); ++it) {
        end = find("TAG", *it);
        if (end != std::string::npos && !(((end - *it)+3) % 3)) {
            codon.push_back(end);
        }

        end = find("TGA", *it);
        if (end != std::string::npos && !(((end - *it)+3) % 3)) {
            codon.push_back(end);
        }

        end = find("TAA", *it);
        if (end != std::string::npos && !(((end - *it)+3) % 3)){
            codon.push_back(end);
        }
    }
    return codon;
}


