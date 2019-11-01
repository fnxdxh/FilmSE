#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <iostream>
#include <string>
#include <assert.h>
#include <ctype.h>
#include <vector>
#include "mstack.h"
#include "mcharstring.h"
#include "mcharstringlink.h"
#include "dic.h"

#define WORD_MAX_LENGTH 18

class Parser
{
private:
    MCharString m_buffer;
    MCharString m_title;
    MCharString m_info;
    MCharString m_summary;
    std::vector<MCharString> m_wordlist;

public:
    Parser(std::string filepath);
    bool getTitle();
    bool getInfo();
    bool getSummary();

    void start();

    void wordSegmentation(Dic& dic);

    bool outputFilmInfo(std::string filepath);
    bool outputWordSeg(std::string filepath);

    void printbuffer();
    void printtitle();
    void printinfo();
    void printsummary();
};

#endif // PARSER_H
