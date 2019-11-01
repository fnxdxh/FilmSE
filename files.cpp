#include "files.h"

Files::Files(std::string path)
{
    long long hFile = 0; //文件句柄
    struct _finddata_t fileinfo;
    std::string p;
    if((hFile = _findfirst(p.assign(path).append("*.html").c_str(),&fileinfo)) !=  -1) {
        do {
            m_files.push_back(fileinfo.name);
        }
        while (_findnext(hFile, &fileinfo)  == 0);
        _findclose(hFile);
    }
    for (int i = 0; i < static_cast<int>(m_files.size()); i++) {
        std::string filename;
        for (int j = 0; j < m_files[i].size() - 5; j++) {
            filename.push_back(m_files[i][j]);
        }
        m_filenames.push_back(filename);
    }
    m_length = m_files.size();
}

int Files::length()
{
    return m_length;
}

int Files::size()
{
    return m_length;
}

std::string Files::at(int index)
{
    assert(index >= 0 && index < m_length);
    return m_filenames[index];
}

void Files::print()
{
    std::cout << m_files.size() << std::endl;
    for (int i = 0; i < static_cast<int>(m_files.size()); i++) {
        std::cout << m_files[static_cast<size_t>(i)] << std::endl;
    }
    for (int i = 0; i < m_filenames.size(); i++) {
        std::cout << m_filenames[i] << std::endl;
    }
}
