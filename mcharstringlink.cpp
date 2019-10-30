#include "mcharstringlink.h"

MCharStringNode::MCharStringNode()
{
}

MCharStringNode::MCharStringNode(MCharString charstring)
{
    m_element.assign(charstring);
}

MCharString MCharStringNode::getelement()
{
    return m_element;
}

void MCharStringNode::setelement(MCharString charstring)
{
    m_element.assign(charstring);
}

MCharStringNode* MCharStringNode::getpre()
{
    return m_pre;
}

void MCharStringNode::setpre(MCharStringNode* charstringnode)
{
    m_pre = charstringnode;
}

MCharStringNode* MCharStringNode::getnext()
{
    return m_next;
}

void MCharStringNode::setnext(MCharStringNode* charstringnode)
{
    m_next = charstringnode;
}

void MCharStringLink::append(MCharString charstring)
{
    MCharStringNode* node = new MCharStringNode(charstring);
    if (m_length == 0) {
        m_head = node;
        m_tail = node;
        m_length++;
    }
    else {
        m_tail->setnext(node);
        node->setpre(m_tail);
        m_tail = node;
        m_length++;
    }
}

bool MCharStringLink::remove(MCharString charstring)
{
    if (m_length == 0) {
        return false;
    }
    MCharStringNode* p = m_head;
    for (int i = 0; i < m_length; i++) {
        if (p->getelement() == charstring) {
            if (i == 0) {
                m_head = p->getnext();
                m_head->setpre(nullptr);
                delete p;
                m_length--;
            }
            else if (i == m_length - 1) {
                m_tail = p->getpre();
                m_tail->setnext(nullptr);
                delete p;
                m_length--;
            }
            else {
                p->getpre()->setnext(p->getnext());
                p->getnext()->setpre(p->getpre());
                delete p;
                m_length--;
            }
            return true;
        }
        else {
            p = p->getnext();
        }
    }
    return false;
}

bool MCharStringLink::search(MCharString charstring)
{
    if (m_length == 0) {
        return false;
    }
    MCharStringNode* p = m_head;
    while (p && p->getelement() != charstring) {
        p = p->getnext();
    }
    if (!p) {
        return false;
    }
    else {
        return true;
    }
}

void MCharStringLink::print()
{
    MCharStringNode* p = m_head;
    while (p) {
        p->getelement().print();
        p = p->getnext();
    }
}
