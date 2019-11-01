#include <iostream>
#include <windows.h>
#include "mcharstring.h"
#include "mcharstringlink.h"
#include "mstack.h"
#include "parser.h"
#include "dic.h"
#include "files.h"
#include "test.h"

using namespace std;

int main()
{
    //以下注释部分用于在控制台输出UTF-8编码
    SetConsoleOutputCP (65001);
    CONSOLE_FONT_INFOEX info = { 0 }; // 以下设置字体来支持中文显示。
    info.cbSize = sizeof(info);
    info.dwFontSize.Y = 16; // leave X as zero
    info.FontWeight = FW_NORMAL;
    wcscpy(info.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);

    //载入词典
    std::cout << "加载词典..." << std::endl;
    Dic dic("./dic/dic");

    //载入文件
    std::cout << "读取文件..." << std::endl;
    Files files("./input/");
    int filenum = files.size();

    std::cout << "网页解析..." << std::endl;
    for (int i = 0; i < filenum; i++) {
        std::string inputfile = "./input/";
        std::string outputfile_1 = "./output/";
        std::string outputfile_2 = "./output/";
        inputfile.append(files.at(i).append(".html"));
        outputfile_1.append(files.at(i).append(".info"));
        outputfile_2.append(files.at(i).append(".txt"));
        Parser parser(inputfile);
        parser.start();
        parser.wordSegmentation(dic);
        parser.outputFilmInfo(outputfile_1);
        parser.outputWordSeg(outputfile_2);
    }

    std::cout << "完成！" << std::endl;
    return 0;
}
