#include "mcharstring.h"

MCharString::MCharString()
{
    m_string = nullptr;
}

MCharString::MCharString(std::string cstring)
{
    m_length = static_cast<int>(cstring.size());
    m_string = new char[m_length];
    for (int i = 0; i < m_length; i++) {
        m_string[i] = cstring[static_cast<size_t>(i)];
    }
}

MCharString::MCharString(char *string)
{
    m_length = static_cast<int>(strlen(string));
    m_string = new char[m_length];
    for (int i = 0; i < m_length; i++) {
        m_string[i] = string[i];
    }
}

MCharString::MCharString(const char *string)
{
    m_length = static_cast<int>(strlen(string));
    m_string = new char[m_length];
    for (int i = 0; i < m_length; i++) {
        m_string[i] = string[i];
    }
}

MCharString::MCharString(int length, char *string)
{
    m_length = length;
    m_string = new char[m_length];
    for (int i = 0; i < m_length; i++) {
        m_string[i] = string[i];
    }
}

MCharString::~MCharString()
{
    if (!m_string) {
        delete[] m_string;
    }
}

bool MCharString::init(std::string cstring)
{
    if (!m_length && !m_string) {
        m_length = static_cast<int>(cstring.size());
        m_string = new char[m_length];
        for (int i = 0; i < m_length; i++) {
            m_string[i] = cstring[static_cast<size_t>(i)];
        }
        return true;
    }
    return false;
}

int MCharString::size()
{
    return m_length;
}

int MCharString::length()
{
    return m_length;
}

int MCharString::indexof(MCharString substring)
{
    //在本次实验条件下，使用kmp算法价值不大，逐字匹配
    int mainlength = m_length;
    int sublength = substring.length();
    int i = 0;
    int j = 0;
    for (i = 0; i < mainlength - sublength + 1; i++) {
        for (j = 0; j < sublength; j++) {
            //std::cout << m_string[i + j] << " " << substring[j] << std::endl;
            if (m_string[i + j] != substring[j]) {
                break;
            }
        }
        if (j == sublength) {
            return i;
        }
    }
    return -1;
}

MCharString MCharString::substringBypos(int head, int tail)
{
    if (head >= 0 && head <= tail && tail < m_length) {
        std::string cstring;
        for (int i = head; i <= tail; i++) {
            cstring.push_back(m_string[i]);
        }
        return MCharString(cstring);
    }
    return MCharString();
}

MCharString MCharString::substringBylength(int head, int length)
{
    if (head >= 0 && head <= m_length) {
        std::string cstring;
        if (head + length < m_length) {
            for (int i = head; i < head + length; i++) {
                cstring.push_back(m_string[i]);
            }
        }
        else {
            for (int i = head; i < m_length; i++) {
                cstring.push_back(m_string[i]);
            }
        }
        return MCharString(cstring);
    }
    return MCharString();
}

void MCharString::concat(MCharString charstring)
{
    if (m_length == 0) {
        m_length = charstring.length();
        m_string = new char[m_length];
        for (int i = 0; i < m_length; i++) {
            m_string[i] = charstring[i];
        }
    }
    else {
        char* temp = m_string;
        int newlength = m_length + charstring.size();
        m_string = new char[newlength];
        for (int i = 0; i < m_length; i++) {
            m_string[i] = temp[i];
        }
        for (int i = m_length; i < newlength; i++) {
            m_string[i] = charstring[i - m_length];
        }
        m_length = newlength;
        delete[] temp;
    }
}

void MCharString::append(MCharString charstring)
{
    if (m_length == 0) {
        m_length = charstring.length();
        m_string = new char[m_length];
        for (int i = 0; i < m_length; i++) {
            m_string[i] = charstring[i];
        }
    }
    else {
        char* temp = m_string;
        int newlength = m_length + charstring.size();
        m_string = new char[newlength];
        for (int i = 0; i < m_length; i++) {
            m_string[i] = temp[i];
        }
        for (int i = m_length; i < newlength; i++) {
            m_string[i] = charstring[i - m_length];
        }
        m_length = newlength;
        delete[] temp;
    }
}

void MCharString::push_back(char c)
{
    if (m_length == 0) {
        m_length = 1;
        m_string = new char[1];
        m_string[0] = c;
    }
    else {
        char* temp = m_string;
        int newlength = m_length + 1;
        m_string = new char[newlength];
        for (int i = 0; i < m_length; i++) {
            m_string[i] = temp[i];
        }
        m_string[m_length] = c;
        m_length = newlength;
        delete[] temp;
    }
}

void MCharString::pop_back()
{
    if (m_length != 0) {
        m_length--;
    }
}

void MCharString::pop_back_to_fit()
{
    if (m_length != 0) {
        m_length--;
        char* tmp = m_string;
        m_string = new char[m_length];
        for (int i = 0; i < m_length; i++) {
            m_string[i] = tmp[i];
        }
        delete [] tmp;
    }
}

char MCharString::at(int index)
{
    if (index >= 0 && index < m_length) {
        return m_string[index];
    }
    return 0;
}

void MCharString::assign(MCharString charstring)
{
    if (!m_string) {
        delete[] m_string;
    }
    m_length = charstring.m_length;
    m_string = new char[m_length];
    for (int i = 0; i < m_length; i++) {
        m_string[i] = charstring.m_string[i];
    }
}

void MCharString::clear()
{
    if (m_length != 0) {
        m_length = 0;
        delete[] m_string;
    }
}

std::string MCharString::toSTLstring()
{
    std::string cstring;
    for (int i = 0; i < m_length; i++) {
        cstring.push_back(m_string[i]);
    }
    return cstring;
}

void MCharString::print()
{
    for (int i = 0; i < m_length; i++) {
        std::cout << m_string[i];
    }
    std::cout << std::endl;
}

void MCharString::operator=(const MCharString &charstring)
{
    if (!m_string) {
        delete[] m_string;
    }
    m_length = charstring.m_length;
    m_string = charstring.m_string;
}

bool MCharString::operator==(const MCharString &charstring)
{
    if (m_length == charstring.m_length) {
        for (int i = 0; i < m_length; i++) {
            if (m_string[i] != charstring.m_string[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool MCharString::operator==(const char *string)
{
    if (m_length == static_cast<int>(strlen(string))) {
        for (int i = 0; i < m_length; i++) {
            if (m_string[i] != string[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool MCharString::operator==(const std::string cstring)
{
    if (m_length == static_cast<int>(cstring.size())) {
        for (int i = 0; i < m_length; i++) {
            if (m_string[i] != cstring[static_cast<size_t>(i)]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool MCharString::operator!=(const MCharString &charstring)
{
    if (m_length != charstring.m_length) {
        return true;
    }
    else {
        for (int i = 0; i < m_length; i++) {
            if (m_string[i] != charstring.m_string[i]) {
                return true;
            }
        }
    }
    return false;
}

bool MCharString::operator<(const MCharString &charstring)
{
    int n = m_length ? charstring.m_length : m_length < charstring.m_length;
    for (int i = 0; i < n; i++) {
        if (m_string[i] < charstring.m_string[i]) {
            return true;
        }
        if (m_string[i] > charstring.m_string[i]) {
            return false;
        }
    }
    if (m_length < charstring.m_length) {
        return true;
    }
    return false;
}

bool MCharString::operator>(const MCharString &charstring)
{
    int n = m_length ? charstring.m_length : m_length < charstring.m_length;
    for (int i = 0; i < n; i++) {
        if (m_string[i] > charstring.m_string[i]) {
            return true;
        }
        if (m_string[i] < charstring.m_string[i]) {
            return false;
        }
    }
    if (m_length > charstring.m_length) {
        return true;
    }
    return false;
}

char MCharString::operator[](int index)
{
    if (index >= 0 && index < m_length) {
        return m_string[index];
    }
    return 0;
}

MCharString MCharString::operator+(const MCharString &charstring)
{
    int length = m_length + charstring.m_length;
    char* String = new char[length];
    for (int i = 0; i < m_length; i++) {
        String[i] = m_string[i];
    }
    for (int i = m_length; i < length; i++) {
        String[i] = charstring.m_string[i - m_length];
    }
    return MCharString(length, String);
}

