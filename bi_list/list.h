//
// Created by joe_jing on 24-5-22.
//

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"

template<typename T> requires intergral_num<T>
class List final {
public:
    List() : m_header(nullptr), m_nodeCount(0){
        createList();
    }

    ~List() {
        freeList();
    }

    [[nodiscard]] Node<T>* search(T value);

    bool insert(T value);

    void remove(T value);

    [[nodiscard]] unsigned int size() const;

    void dump();
private:
    void createList();

    void freeList();

    Node<T> *m_header;

    unsigned int m_nodeCount;
};

template<typename T> requires intergral_num<T>
void List<T>::createList() {
    m_header = new Node<T>(0);
    m_header->m_next = m_header;
    m_header->m_pre = m_header;
}

template<typename T> requires intergral_num<T>
void List<T>::freeList() {
    Node<T>* node = m_header;
    m_header->m_pre->m_next = nullptr;
    while(node) {
        Node<T>* tmp = node->m_next;
        delete node;
        node = tmp;
    }
}

template<typename T> requires intergral_num<T>
Node<T>* List<T>::search(T value) {
    Node<T> *node = m_header->m_next;
    while(node != m_header) {
        if(node->m_value == value) {
            return node;
        }
        node = node->m_next;
    }
    return nullptr;
}

template<typename T> requires intergral_num<T>
bool List<T>::insert(T value) {
    Node<T>* node = m_header;
    Node<T>* newNode = new Node<T>(value);

    newNode->m_next = node->m_next;
    node->m_next = newNode;
    newNode->m_pre = node;
    newNode->m_next->m_pre = newNode;
    ++m_nodeCount;
    return true;
}

template<typename T> requires intergral_num<T>
void List<T>::remove(T value) {
    Node<T> *node = m_header->m_next;
    while(node != m_header) {
        if(node->m_value == value) {
            Node<T>* pre = node->m_pre;
            Node<T>* next = node->m_next;
            pre->m_next = next;
            next->m_pre = pre;
            delete node;
            --m_nodeCount;
            return;
        }
        node = node->m_next;
    }
}

template<typename T> requires intergral_num<T>
void List<T>::dump() {
    Node<T>* node = m_header->m_next;
    while(node != m_header) {
        std::cout << "node: " << node << " value: " << node->getValue()
            << " previous: " << node->m_pre << " next: " << node->m_next << '\n';
        node = node->m_next;
    }
}


template<typename T> requires intergral_num<T>
unsigned int List<T>::size() const {
    return m_nodeCount;
}
#endif //LIST_H
