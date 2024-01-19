//   File: Binary_Tree.h
//   Date: January 13, 2024
// Author: David West
//   Desc: Basic binary tree data structure without balancing.
//         This header file contains the class method declarations.
// ---------------------------------------------------------------------

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "Queue.h" // Used in breadth-first search

#include <iostream>
using std::cout;

template <typename K, typename V>
class BinaryTree {
private:
    struct BinaryNode {
        K _key;
        V _value;
        BinaryNode* _leftChild;
        BinaryNode* _rightChild;

        // Constructors
        BinaryNode(const K & key, const V & val);
        BinaryNode(const K & key, const V && val);

    };  // End BinaryNode

    BinaryNode* _treeRoot;
    int _size;

public:
    // Constructors
    BinaryTree();
    ~BinaryTree();

    // Tree Management Methods
    void insert(const K & key, const V & value);
    bool remove(const K & key);
    V findValue(const K & key);
    int size();

    // Traversal Methods
    void preOrderTraverse();
    void inOrderTraverse();
    void postOrderTraverse();
    void breadthFirstTraverse();

private:
    // Tree Management Methods
    void _insert(BinaryNode* & root, BinaryNode* & newNode);
    BinaryNode* _remove(BinaryNode* root, const K & key);
    BinaryNode* _findMinKey(BinaryNode* root);

    // Traversal Methods
    void _preOrderTraverse(BinaryNode* & root, void(*operation)(BinaryNode*));
    void _inOrderTraverse(BinaryNode* & root, void(*operation)(BinaryNode*));
    void _postOrderTraverse(BinaryNode* & root, void(*operation)(BinaryNode*));
    void _breadthFirstTraverse(BinaryNode* root, void(*operation)(BinaryNode*));

    // Traversal Operations
    static void _deleteNode(BinaryNode* node);
    static void _printValue(BinaryNode* node);
    static void _calcHeight(BinaryNode* node);
};


#endif //REDBLACKTREE_H
