#ifndef FILES_H
#define FILES_H

#include <string>
#include <vector>
#include <io.h>
#include <iostream>

class Files
{
private:
    std::vector<std::string> m_files;
    std::vector<std::string> m_filenames;

public:
    Files(std::string path);
    void print();
};

#endif // FILES_H
