#ifndef MCHARSTRING_H
#define MCHARSTRING_H

#include <iostream>
#include <string>
#include <cstring>

class MCharString
{
private:
    char* m_string;
    int m_length = 0;

public:
    MCharString();
    MCharString(std::string cstring);
    MCharString(char* string);
    MCharString(int length, char* string);
    ~MCharString();

    bool init(std::string cstring);     //若初始化时没有传参，则init
    int size();     //返回m_length
    int length();   //同上
    int indexof(MCharString substring); //查找子串位置，查找失败返回-1
    MCharString substring(int head, int tail);    //根据头尾位置生成子串
    void concat(MCharString charstring);    //连接字符串
    char at(int index);    //与[]用法相同
    void assign(MCharString charstring);    //与重载=运算符不同，assign重新申请一块空间
    void print();   //打印

    //重载运算符
    void operator=(const MCharString& charstring);  //赋值运算符并不重新申请空间
    bool operator==(const MCharString& charstring);
    bool operator!=(const MCharString& charstring);
    bool operator<(const MCharString& charstring);
    bool operator>(const MCharString& charstring);
    char operator[](int index);
    MCharString operator+(const MCharString& charstring);
};

#endif // MCHARSTRING_H
