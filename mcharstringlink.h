#ifndef MCHARSTRINGLINK_H
#define MCHARSTRINGLINK_H

#include "mcharstring.h"

class MCharStringNode
{
private:
    MCharString m_element;
    MCharStringNode* m_pre = nullptr;
    MCharStringNode* m_next = nullptr;

public:
    MCharStringNode();
    MCharStringNode(MCharString charstring);
    MCharString getelement();
    void setelement(MCharString charstring);
    MCharStringNode* getpre();
    void setpre(MCharStringNode* charstringnode);
    MCharStringNode* getnext();
    void setnext(MCharStringNode* charstringnode);
};

//链表遵从编程习惯，index从0开始
class MCharStringLink
{
private:
    MCharStringNode* m_head = nullptr;
    MCharStringNode* m_tail = nullptr;
    MCharStringNode* m_current = nullptr;
    int m_length = 0;

public:
    void append(MCharString charstring); //在链表尾部添加一个字符串
    bool remove(MCharString charstring); //删除链表中的一个字符串，未找到则返回false
    bool search(MCharString charstring); //查找一个字符串的index，未找到返回-1
    void print();
};

#endif // MCHARSTRINGLINK_H
