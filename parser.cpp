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
    MCharString target("<title>");
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
                if (tmp == "</title") {
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
        m_title.pop_back();
        m_title.pop_back();
        m_title.pop_back();
        m_title.pop_back();
        m_title.pop_back();
        m_title.pop_back();
        m_title.pop_back();
        m_title.pop_back();
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
    MCharString target1("<span class=\"all hidden\">");
    MCharString target2("<span property=\"v:summary\"");
    int index1 = m_buffer.indexof(target1);
    int index2 = m_buffer.indexof(target2);
    char c;
    if (index1 != -1) {
        MCharString tmp1;
        int i = index1;
        int status = 1; //0表示在标签内，1表示不在标签内
        while (1) {
            c = m_buffer[i];
            if (c == '<') {
                if (tmp1.size() && status == 1) {
                    m_summary.append(tmp1);
                }
                status = 0;
                tmp1.clear();
                tmp1.push_back(c);
            }
            else if (c == '>') {
                if (tmp1 == "</span") {
                    break;
                }
                if (tmp1 == "<br" || tmp1 == "<br/" || tmp1 == "<br /") {
                    m_summary.push_back('\n');
                }
                status = 1;
                tmp1.clear();
            }
            else {
                //处理全角字符
                //全角空格编码为-29,-128,-128
                if (c == -29 && m_buffer[i+1] == -128 && m_buffer[i+2] == -128) {
                    i += 2;
                }
                else if (!isspace(c)) {
                    tmp1.push_back(c);
                }
            }
            i++;
        }
        return true;
    }
    else if (index2 != -1) {
        MCharString tmp2;
        int i = index2;
        int status = 1; //0表示在标签内，1表示不在标签内
        while (1) {
            c = m_buffer[i];
            if (c == '<') {
                if (tmp2.size() && status == 1) {
                    m_summary.append(tmp2);
                }
                status = 0;
                tmp2.clear();
                tmp2.push_back(c);
            }
            else if (c == '>') {
                if (tmp2 == "</span") {
                    break;
                }
                if (tmp2 == "<br" || tmp2 == "<br/" || tmp2 == "<br /") {
                    m_summary.push_back('\n');
                }
                status = 1;
                tmp2.clear();
            }
            else {
                //处理全角字符
                //全角空格编码为-29,-128,-128
                if (c == -29 && m_buffer[i+1] == -128 && m_buffer[i+2] == -128) {
                    i += 2;
                }
                else if (!isspace(c)) {
                    tmp2.push_back(c);
                }
            }
            i++;
        }
        return true;
    }
    return false;
}

void Parser::start()
{
    getTitle();
    getInfo();
    getSummary();
}

void Parser::wordSegmentation(Dic &dic)
{
    int summarylength = m_summary.length();
    int i = 0;
    while (i < summarylength) {
        for (int j = WORD_MAX_LENGTH; j > 0; j--) {
            MCharString word = m_summary.substringBylength(i, j);
            if (dic.find(word.toSTLstring())) {
                m_wordlist.push_back(word);
                i += j;
                break;
            }
            else if (j == 1) {
                i++;
                break;
            }
        }
    }
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
    std::ofstream fout;
    fout.open(filepath);
    if (fout.is_open()) {
        int vectorlength = m_wordlist.size();
        if (vectorlength == 0) {
            return false;
        }
        for (int i = 0; i < vectorlength; i++) {
            for (int j = 0; j < m_wordlist[i].size(); j++) {
                fout << m_wordlist[i][j];
            }
            fout << std::endl;
        }
        return true;
    }
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
