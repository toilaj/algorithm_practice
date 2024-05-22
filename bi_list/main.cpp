#include <iostream>
#include "list.h"

int main() {
    List<int> list;
    for(auto i = 0; i < 100; ++i) {
        list.insert(i);
    }
    list.dump();
    std::cout << "size: " << list.size() << '\n';
    list.remove(20);
    std::cout << "removed size: " << list.size() << '\n';

    Node<int>* n = list.search(20);
    if(n) {
        std::cout << "found the node:" << n << " value:" << n->getValue() << '\n';
    } else {
        std::cout << "not found the node\n";
    }

    return 0;
}
