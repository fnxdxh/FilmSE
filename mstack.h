#ifndef MSTACK_H
#define MSTACK_H

#define STACK_MAX_SIZE 1000

template <typename T>
class MStack
{
private:
    T m_stack[STACK_MAX_SIZE + 1];	//栈的实际下标从1开始
    int m_currentpos = 0;	//0代表空栈

public:
    bool push(T element);
    T pop();
    T top();
    bool isEmpty();
};

template<typename T>
inline bool MStack<T>::push(T element)
{
    if (m_currentpos != STACK_MAX_SIZE) {
        m_currentpos++;
        m_stack[m_currentpos] = element;
        return true;
    }
    return false;
}

template<typename T>
inline T MStack<T>::pop()
{
    if (m_currentpos != 0) {
        m_currentpos--;
        return m_stack[m_currentpos + 1];
    }
    return T();
}

template<typename T>
inline T MStack<T>::top()
{
    return m_stack[m_currentpos];
}

template<typename T>
inline bool MStack<T>::isEmpty()
{
    if (m_currentpos == 0) {
        return true;
    }
    return false;
}

#endif // MSTACK_H
