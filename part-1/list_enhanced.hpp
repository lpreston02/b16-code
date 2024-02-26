
#ifndef __list_enhanced__
#define __list_enhanced__

#include "list.hpp"
#include <iostream>

template <typename T> void list_delete_after(Node<T> *node)
{
    // WRITE YOUR CODE HERE
    if (node == nullptr || node->next == nullptr) {
        std::cout << "Invalid node or no node to delete after." << std::endl;
        return;
    }

    Node<T> *nodeToDelete = node->next.release();
    if (nodeToDelete != nullptr) {
        node->next = std::move(nodeToDelete->next);
        delete nodeToDelete; 
    }
}

#endif // __list_enhanced__