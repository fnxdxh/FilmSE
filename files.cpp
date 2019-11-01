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
}

void Files::print()
{
    std::cout << m_files.size() << std::endl;
    for (int i = 0; i < static_cast<int>(m_files.size()); i++) {
        std::cout << m_files[static_cast<size_t>(i)] << std::endl;
    }
}
