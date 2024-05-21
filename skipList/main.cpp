
#include "skipList.h"
int main() {
    SkipList<int, int> s(1000);
    for (int i = 0; i < 1000; i++) {
        s.insert(i, i + 100);
    }

    s.dumpList();
    Node<int,int> *node = s.search(18);
    if(node) {
        std::cout << std::format("find the node, key: {}, value: {}\n", node->getKey(),node->getValue());
    } else {
        std::cout << "not found node\n";
    }
    s.remove(18);
    node = s.search(18);
    if(node) {
        std::cout << std::format("find the node, key: {}, value: {}\n", node->getKey(),node->getValue());
    } else {
        std::cout << "not found node\n";
    }
    return 0;
}
