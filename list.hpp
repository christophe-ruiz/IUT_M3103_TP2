#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"

template <typename T>
class CList
{
private:
    CNode<T>* m_fictionaHead;
    CNode<T>* m_Tail;
public:
    CList (CNode<T>* const & Head = new CNode<T>(), CNode<T>* const & Tail = new CNode<T>()) : m_fictionaHead (Head), m_Tail(Tail){
        m_fictionaHead->setNextNode(m_Tail);
    }
    ~CList (){}
   //ajout en tête de liste
    void push_front (const T & val) {
        CNode<T>* newNode = new CNode<T>(val, m_fictionaHead->GetNextNode());
        m_fictionaHead->setNextNode(newNode);
    }

   //affichage
    void Show () const {
        CNode<T>* iter = m_fictionaHead->GetNextNode();
        while (iter != nullptr) {
            std::cout << iter->GetData() << ", ";
            iter = iter->GetNextNode();
        }
        std::cout << std::endl;
    }

    //recherche d'un élément dans la liste, renvoie le pointeur du maillon si l'élément est présent, nullptr sinon
    CNode<T>* Find (const T & val) const {
        CNode<T>* iter = m_fictionaHead->GetNextNode();
        while (iter != nullptr) {
            if (iter->GetData() == val) return iter;
            iter = iter->GetNextNode();
        }
        return iter;
    }

    //ajout d'une valeur après un maillon de la liste
    void Add (const T & val, CNode<T>* & Noeud) {
        CNode<T>* newNode = new CNode<T> (val, Noeud->GetNextNode());
        Noeud->setNextNode(newNode);
        if (Noeud == this->m_Tail) m_Tail = newNode;
    }

    void push_back (const T & val) {
        Add(val, m_Tail);
    }

    //détache un maillon de la liste et le supprime
    void Delete (CNode<T>* & suppr) {
        CNode<T>* iter = m_fictionaHead;
        while (iter->GetNextNode() != suppr) {
            iter = iter->GetNextNode();
        }
        iter->setNextNode(suppr->GetNextNode());
        delete suppr;
        suppr = nullptr;
    }
};

#endif // LIST_HPP
