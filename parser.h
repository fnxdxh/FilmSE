#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <iostream>
#include <string>
#include <assert.h>
#include "mstack.h"
#include "mcharstring.h"
#include "mcharstringlink.h"

class Parser
{
private:
    MCharString m_buffer;
    std::string m_result;

public:
    Parser(std::string filepath);
    bool getTitle();
    void printbuffer();
};

#endif // PARSER_H
