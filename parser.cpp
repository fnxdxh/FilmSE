#include "parser.h"

Parser::Parser(std::string filepath)
{
    std::ifstream fin;
    fin.open(filepath);
    assert(fin.is_open());
    std::istreambuf_iterator<char> begin(fin), end;
    std::string buffer(begin, end);
    fin.close();
    m_buffer.init(buffer);
}

bool Parser::getTitle()
{
    MCharString target("<span property=\"v:itemreviewed\">");
    if (m_buffer.indexof(target) != -1) {
        std::cout << m_buffer.indexof(target) << std::endl;
        return true;
    }
    return false;
}

void Parser::printbuffer()
{
    m_buffer.print();
}
