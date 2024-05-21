//
// Created by joe_jing on 24-5-20.
//

#ifndef SKIPLIST_NODE_H
#define SKIPLIST_NODE_H

template<typename K, typename V>
class SkipList;

template<typename K, typename V>
class Node {
    friend class SkipList<K, V>;
public:
    Node(K key, V value) : m_key(key), m_value(value) {}
    ~Node() {
        delete []m_forward;
    }

    K getKey() const {
        return m_key;
    }

    K getValue() const {
        return m_value;
    }
private:
    K m_key;
    V m_value;
    Node<K,V> **m_forward;
    unsigned int m_nodeLevel;
};


#endif //SKIPLIST_NODE_H
