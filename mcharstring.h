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
    MCharString(const char* string);
    MCharString(int length, char* string);
    ~MCharString();

    bool init(std::string cstring);     //若初始化时没有传参，则init
    int size();     //返回m_length
    int length();   //同上
    int indexof(MCharString substringBypos); //查找子串位置，查找失败返回-1
    MCharString substringBypos(int head, int tail);    //根据头尾位置生成子串
    MCharString substringBylength(int head, int length);    //根据位置和长度生成子串
    void concat(MCharString charstring);    //连接字符串
    void append(MCharString charstring);    //同上
    void push_back(char c);     //在末尾增加一个字符
    void pop_back();    //在末尾删去一个字符
    void pop_back_to_fit();     //在末尾删去一个字符并释放空间
    char at(int index);    //与[]用法相同
    void assign(MCharString charstring);    //与重载=运算符不同，assign重新申请一块空间
    void clear();
    std::string toSTLstring();
    void print();   //打印

    //重载运算符
    void operator=(const MCharString& charstring);  //赋值运算符并不重新申请空间
    bool operator==(const MCharString& charstring);
    bool operator==(const char* string);
    bool operator==(const std::string cstring);
    bool operator!=(const MCharString& charstring);
    bool operator<(const MCharString& charstring);
    bool operator>(const MCharString& charstring);
    char operator[](int index);
    MCharString operator+(const MCharString& charstring);
};

#endif // MCHARSTRING_H
