//
// Created by a on 6/1/20.
//

#ifndef DNA_DNASEQUENCE_H
#define DNA_DNASEQUENCE_H

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <string>
#include "../../view/reader/iRead.h"


class DnaSequence {
private:

    class Nucleotide{
    public:
        friend class test_DNA;
        Nucleotide();
        Nucleotide(char c);
        Nucleotide& operator=(const char c);
        operator char();
        DnaSequence::Nucleotide pairToNucleotide();

        static bool isValidChar(const char& c);

    private:
        char m_char;


    };


public:
    /**CTors**/
    DnaSequence(const char *dnaSequence);
    DnaSequence(const std::string& dnaSequence);
    DnaSequence(const IRead* dnaSequence);
    DnaSequence(const size_t size);

    /**Copy CTor**/
    DnaSequence(const DnaSequence& dnaSequence);

    /**DTor**/
    ~DnaSequence();

    /**get functions**/
    const char* getDnaAsChar()const;
    std::string getDnaAsString()const;
    size_t getLengthSequence()const;

    /**operator functions**/
    DnaSequence& operator=( const DnaSequence& other);
    friend std::ostream& operator<<(std::ostream& out,const DnaSequence& dnaSequence);
    Nucleotide& operator[](size_t index)const;

    /**other functions**/
    DnaSequence slice(size_t start, size_t end);
    DnaSequence pairingDNA();
    size_t find(const DnaSequence& dnaSequence, size_t index=0);
    std::vector<size_t> findAll(const DnaSequence& dnaSequence);
    size_t count(const DnaSequence& dnaSequence);
    std::vector<size_t> findConsensusSequences(DnaSequence& dnaSequence);


private:

    Nucleotide* m_dnaSequence;
    size_t m_length;

    /**help functions**/
    static bool isValidSequence(const char* dnaSequence);
    DnaSequence::Nucleotide* initSequence(const char* dnaSeq)const;
    DnaSequence::Nucleotide* getSeqToAssign(const DnaSequence& dnaSeq);
    static const char* DNA_CHARS;
};




bool operator==(const DnaSequence& sequence1, const DnaSequence& sequence2);
bool operator!=(const DnaSequence& sequence1, const DnaSequence& sequence2);


#endif //DNA_DNASEQUENCE_H
