//
// Created by joe_jing on 24-5-20.
//

#ifndef SKIPLIST_SKIPLIST_H
#define SKIPLIST_SKIPLIST_H

#include <utility>
#include <iostream>
#include <format>
#include "node.h"
#include "random.h"

template<typename K, typename V>
class SkipList final {
public:
    explicit SkipList(K footerKey)
    : m_rnd(), m_nodeCount(0), m_level(0) {
        createList(footerKey);
    }
    ~SkipList() {
        freeList();
    }

    Node<K, V> *search(K key) const;

    bool insert(K key, V value);

    bool remove(K key);

    [[nodiscard]] int getSize() const;

    void dumpList() const;

private:
    void createList(K footerKey);

    void createNode(unsigned int level, Node<K, V>* &node, K key, V value);

    int getRandomLevel();

    void freeList();

    int m_nodeCount;
    int m_level;

    Node<K, V> *m_header;
    Node<K, V> *m_footer;
    Random m_rnd;

    static const int MAX_LEVEL = 16;
};

template<typename K, typename V>
void SkipList<K, V>::createNode(unsigned int level, Node<K, V> *&node, K key, V value) {
    node = new Node<K, V>(key, value);
    node->m_forward = new Node<K, V>* [level + 1];
    node->m_nodeLevel = level;
}

template<typename K, typename V>
void SkipList<K, V>::createList(K footerKey) {
    createNode(0, m_footer, footerKey, 0);
    createNode(MAX_LEVEL, m_header, 0, 0);
    for (unsigned int i = 0; i < MAX_LEVEL; ++i) {
        m_header->m_forward[i] = m_footer;
    }
    m_nodeCount = 0;
    this->m_level = 0;
}

template<typename K, typename V>
int SkipList<K, V>::getRandomLevel() {
    return m_rnd.Uniform(MAX_LEVEL);
}

template<typename K, typename V>
void SkipList<K, V>::freeList() {
    Node<K, V> *p = m_header;
    Node<K, V> *q;
    while(p != nullptr) {
        q = p->m_forward[0];
        delete p;
        p = q;
    }
    delete p;
}

template<typename K, typename V>
Node<K, V>* SkipList<K, V>::search(K key) const {
    Node<K, V> *node = m_header;
    for(int i = m_level; i >= 0; --i) {
        while(node->m_forward[i]->m_key < key) {
            node = node->m_forward[i];
            if(node == m_footer) {
                return nullptr;
            }
        }
    }
    node = node->m_forward[0];
    if(node->m_key == key) {
        return node;
    } else {
        return nullptr;
    }
}

template<typename K, typename V>
bool SkipList<K, V>::insert(K key, V value)  {
    Node<K, V> *update[MAX_LEVEL];
    Node<K, V> *node = m_header;
    if(key >= m_footer->m_key) {
        return false;
    }
    for(int i = m_level; i >= 0; --i) {
        while(node->m_forward[i]->m_key < key) {
            node = node->m_forward[i];
        }
        update[i] = node;
    }
    node = node->m_forward[0];
    if(node->m_key == key) {
        return false;
    }
    int nodeLevel = getRandomLevel();
    if(nodeLevel > m_level) {
        nodeLevel = ++m_level;
        update[nodeLevel] = m_header;
    }
    Node<K, V> *newNode;
    createNode(nodeLevel, newNode, key, value);
    for(int i = nodeLevel; i >= 0; --i) {
        node = update[i];
        newNode->m_forward[i] = node->m_forward[i];
        node->m_forward[i] = newNode;
    }
    m_nodeCount++;
    return true;
}

template<typename K, typename V>
bool SkipList<K, V>::remove(K key) {
    Node<K, V> *node = m_header;
    Node<K, V> *update[MAX_LEVEL];
    Node<K, V> *delNode;
    for(int i = m_level; i >= 0; --i) {
        while(node->m_forward[i]->m_key < key) {
            node = node->m_forward[i];
            if(node == m_footer) {
                return false;
            }
        }
        update[i] = node;
    }
    delNode = node->m_forward[0];
    if(delNode->m_key != key) {
        //not found
        return false;
    }
    for(int i = delNode->m_nodeLevel; i >= 0; --i) {
        node = update[i];
        node->m_forward[i] = delNode->m_forward[i];
    }
    delete delNode;
    --m_nodeCount;

    while(m_level > 0 && m_header->m_forward[m_level] != m_footer) {
        --m_level;
    }
    return true;
}

template<typename K, typename V>
int SkipList<K, V>::getSize() const {
    return m_nodeCount;
}

template<typename K, typename V>
void SkipList<K, V>::dumpList() const {
    Node<K, V> *node = m_header;
        while(node != m_footer) {
            std::cout << std::format("key: {}, value: {}, level: {}\n",
                                     node->m_key, node->m_value, node->m_nodeLevel);
            node = node->m_forward[0];
        }
}

#endif //SKIPLIST_SKIPLIST_H
