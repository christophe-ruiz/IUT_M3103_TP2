#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

template <typename T>
class CNode
{
private:
    T m_Data;
    CNode* m_Next;
public:
    //constructor
    CNode (const T & Data = 0, CNode* const & Next = nullptr)
        : m_Data (Data), m_Next(Next) {}
    //destructor
    ~CNode () {
        std::cout << "CNode supprimé, valeur: " << GetData() << std::endl;
    }

    const T& GetData() const {
        return m_Data;
    }

    CNode* const & GetNextNode() const {
        return m_Next;
    }

    void setData(const T & data) {
        m_Data = data;
    }

    void setNextNode(CNode* const & Next) {
        m_Next = Next;
    }

};

#endif // NODE_HPP
