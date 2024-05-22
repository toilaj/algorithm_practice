//
// Created by joe_jing on 24-5-22.
//

#ifndef NODE_H
#define NODE_H
#include <ostream>
template<typename T>
concept intergral_num = std::is_integral_v<T>;
template<typename T> requires intergral_num<T> class List;

template<typename T> requires intergral_num<T>
class Node final{
    friend class List<T>;
    friend std::ostream& operator<<(std::ostream& out, Node* node) {
        out << static_cast<void*>(node);
        return out;
    }
public:
    explicit Node(T value): m_value(value), m_pre(nullptr), m_next(nullptr) {}
    ~Node() {
        m_next = nullptr;
        m_pre = nullptr;
    }
    T getValue() const {
        return m_value;
    }
private:
    T m_value;
    Node* m_pre;
    Node* m_next;
};


#endif //NODE_H
