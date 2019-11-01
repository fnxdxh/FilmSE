#ifndef DIC_H
#define DIC_H

#include <string>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <assert.h>

class Dic
{
private:
    std::unordered_map<std::string, int> m_dic;
    
public:
    Dic(std::string dicpath);
    bool find(std::string entry);
    int size();
    void print();
};

#endif // DIC_H
