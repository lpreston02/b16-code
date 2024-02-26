#ifndef __binary_saerch_tree_enhanced__
#define __binary_saerch_tree_enhanced__

#include "binary_search_tree.hpp"

template <typename T> T bst_min(const T &tree)
{
    // WRITE YOUR CODE HERE
    //We want to go down the tree on the left hand side

    //Check if node is null or doesn't have a left child
    if (!tree || !left(tree)){
        return tree; //Returns current value as the left most node and min value
    }
    else {
        return bst_min(left(tree)); // If the node has left child the function is called recursively on left child
    }
}

template <typename T> T bst_max(const T &tree)
{
    // WRITE YOUR CODE HERE
    //We want to go down the tree on the right hand side
    //Check if node is null or doesn't have a right child
    if (!tree || !right(tree)){
        return tree; //Returns current value as the right most node and max value
    }
    else {
        return bst_max(right(tree)); // If the node has left child the function is called recursively on right child
    }
}

#endif // __binary_saerch_tree_enhanced__