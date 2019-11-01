#include "dic.h"

Dic::Dic(std::string dicpath)
{
    std::ifstream fin;
    fin.open(dicpath);
    assert(fin.is_open());

    std::string entry;
    int i = 0;
    while (1) {
        if (fin >> entry) {
            m_dic[entry] = i;
        }
        else {
            break;
        }
    }
}

bool Dic::find(std::string entry)
{
    return m_dic.count(entry);
}

int Dic::size()
{
    return static_cast<int>(m_dic.size());
}

void Dic::print()
{
    std::unordered_map<std::string, int>::iterator it;
    it = m_dic.begin();
    while (it != m_dic.end()) {
        std::cout << it->first << std::endl;
        it++;
    }
}
