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
    int index = m_buffer.indexof(target);
    MCharString tmp;
    char c;
    int i = index;
    int status = 1; //0表示在标签内，1表示不在标签内
    if (index != -1) {
        while (1) {
            c = m_buffer[i];
            if (c == '<') {
                if (tmp.size() && status == 1) {
                    m_title.append(tmp);
                }
                status = 0;
                tmp.clear();
                tmp.push_back(c);
            }
            else if (c == '>') {
                if (tmp == "</span") {
                    break;
                }
                if (tmp == "<br" || tmp == "<br/" || tmp == "<br /") {
                    m_title.push_back('\n');
                }
                status = 1;
                tmp.clear();
            }
            else {
                if (!isspace(c)) {
                    tmp.push_back(c);
                }
            }
            i++;
        }
        return true;
    }
    return false;
}

bool Parser::getInfo()
{
    MCharString target("<div id=\"info\">");
    int index = m_buffer.indexof(target);
    MCharString tmp;
    char c;
    int i = index;
    int status = 1; //0表示在标签内，1表示不在标签内
    if (index != -1) {
        while (1) {
            c = m_buffer[i];
            if (c == '<') {
                if (tmp == "IMDb链接:") {
                    m_info.pop_back();
                    return true;
                }
                if (tmp.size() && status == 1) {
                    m_info.append(tmp);
                }
                status = 0;
                tmp.clear();
                tmp.push_back(c);
            }
            else if (c == '>') {
                if (tmp == "</div") {
                    break;
                }
                if (tmp == "<br" || tmp == "<br/" || tmp == "<br /") {
                    m_info.push_back('\n');
                }
                status = 1;
                tmp.clear();
            }
            else {
                if (!isspace(c)) {
                    tmp.push_back(c);
                }
            }
            i++;
        }
        return true;
    }
    return false;
}

bool Parser::getSummary()
{
    MCharString target("<span property=\"v:summary\" class=\"\">");
    int index = m_buffer.indexof(target);
    MCharString tmp;
    char c;
    int i = index;
    int status = 1; //0表示在标签内，1表示不在标签内
    if (index != -1) {
        while (1) {
            c = m_buffer[i];
            if (c == '<') {
                if (tmp.size() && status == 1) {
                    m_summary.append(tmp);
                }
                status = 0;
                tmp.clear();
                tmp.push_back(c);
            }
            else if (c == '>') {
                if (tmp == "</span") {
                    break;
                }
                if (tmp == "<br" || tmp == "<br/" || tmp == "<br /") {
                    m_summary.push_back('\n');
                }
                status = 1;
                tmp.clear();
            }
            else {
                //处理全角字符
                //全角空格编码为-29,-128,-128
                if (c == -29 && m_buffer[i+1] == -128 && m_buffer[i+2] == -128) {
                    i += 2;
                }
                else if (!isspace(c)) {
                    tmp.push_back(c);
                }
            }
            i++;
        }
        return true;
    }
    return false;
}

bool Parser::outputFilmInfo(std::string filepath)
{
    std::ofstream fout;
    fout.open(filepath);
    if (fout.is_open()) {
        int titlelength = m_title.length();
        int infolength = m_info.length();
        int summarylength = m_summary.length();
        for (int i = 0; i < titlelength; i++) {
            fout << m_title[i];
        }
        fout << std::endl;
        for (int i = 0; i < infolength; i++) {
            fout << m_info[i];
        }
        fout << std::endl;
        fout << "剧情简介:" << std::endl;
        for (int i = 0; i < summarylength; i++) {
            fout << m_summary[i];
        }
        return true;
    }
    return false;
}

bool Parser::outputWordSeg(std::string filepath)
{
    return false;
}

void Parser::printbuffer()
{
    m_buffer.print();
}

void Parser::printtitle()
{
    m_title.print();
}

void Parser::printinfo()
{
    m_info.print();
}

void Parser::printsummary()
{
    m_summary.print();
}
