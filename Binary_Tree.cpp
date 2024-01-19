//
// Created by NeoAp on 1/18/2024.
//

#include "Binary_Tree.h"


// ----------------------------------------------------------------------------
//                               Constructors

/**
 * BinaryTree Default constructor
 */
template <typename K, typename V>
BinaryTree<K,V>::BinaryTree() {
    _treeRoot = nullptr;
    _size = 0;
}


/**
 * BinaryTree Destructor
 */
template <typename K, typename V>
BinaryTree<K,V>::~BinaryTree() {
    _postOrderTraverse(_treeRoot, & BinaryTree::_deleteNode);
}


/**
 * BinaryNode Constructor
 * @tparam K
 * @tparam V
 * @param key
 * @param val
 */
template <typename K, typename V>
BinaryTree<K,V>::BinaryNode::BinaryNode(const K & key, const V & val)
    : _key{key}, _value{val} {
    _leftChild = nullptr;
    _rightChild = nullptr;
}


/**
 * BinaryNode Constructor
 * @tparam K
 * @tparam V
 * @param key
 * @param val
 */
template <typename K, typename V>
BinaryTree<K,V>::BinaryNode::BinaryNode(const K & key, const V && val)
    : _key{key}, _value{std::move(val)} {
    _leftChild = nullptr;
    _rightChild = nullptr;
}


// ---------------------------------------------------------------------
//                  Public Tree Management Methods

/**
 * Adds a (_key, _value) pair to the tree.
 * @param data (int) - Value to be added.
 */
template <typename K, typename V>
void BinaryTree<K,V>::insert(const K & key, const V & value) {
    auto* newNode = new BinaryNode(key, value);
    if (!_treeRoot) {
        // First node to be inserted into the tree
        _treeRoot = newNode;
        ++_size;
        return;
    }

    // A tree root exists
    _insert(_treeRoot, newNode);

} // End insert(_key, _value)


/**
 * Finds the _value stored at a _key is in the tree.
 * @param key (K) - Key to find.
 * @return - Returns a pointer to the value stored at a key.
 *           Returns a nullptr if the key doesn't exist.
 */
template <typename K, typename V>
V BinaryTree<K,V>::findValue(const K & key) {
    BinaryNode* currentNode = _treeRoot;
    bool nodeExists = false;

    while (currentNode and !nodeExists) {
        if (currentNode->_key == key) {
            nodeExists = true;

        } else if (currentNode->_key > key) {
            currentNode = currentNode->_leftChild;

        } else {
            currentNode = currentNode->_rightChild;
        }
    }

    static_assert(currentNode, "Key does not exist in the tree.");

    return currentNode->_value;

} // End findValue(_value)


/**
 * Removes a _key from the tree.
 * @param key - Key to be found and removed.
 * @return - True if _key existed within the tree, false if the _key did not exist.
 */
template <typename K, typename V>
bool BinaryTree<K,V>::remove(const K & key) {
    return _remove(_treeRoot, key);
}


// ---------------------------------------------------------------------
//                  Private Tree Management Methods

/**
 * Private method to add a new node with a given _value to the tree.
 * Called by the public insert() method.
 * Duplicates are added in the left child.
 * @param newNode - Node to be added to the tree.
 * @param root - Value of the current traversal node.
 * @return Returns a pointer to the current node.
 */
template <typename K, typename V>
void BinaryTree<K,V>::_insert(BinaryNode* & root, BinaryNode* & newNode) {

    // Key > root _key, go right
    if (newNode->_key > root->_key) {

        if (!root->_rightChild) {      // Parent does not have a right child
            root->_rightChild = newNode;
            ++_size;
        }
        else {      // Parent has a right child, go to it
            _insert(root->_rightChild, newNode);
        }

    } // end new _key > root _key

        // _key <= parent _key, go left
    else {
        if (!root->_leftChild) {   // Parent does not have a left child
            root->_leftChild = newNode;
            ++_size;
        }
        else {      // Parent has a left child, go to it
            _insert(root->_leftChild, newNode);
        }

    }   // end new _key <= root _key

}   // end _insert(root, newNode)


/**
 * Recursive function to find and delete a _key from the tree.
 * @param key - Value to be found and removed.
 * @param node - BinaryNode* to the root of a tree or subtree.
 * @param isFound - Bool to be returned by calling function for whether _key was found within the tree.
 * @return Returns true if the _key to remove was found.
 */
template <typename K, typename V>
typename BinaryTree<K,V>::BinaryNode* BinaryTree<K,V>::_remove(BinaryNode* root, const K & key) {
    // Base case 1: End of findValue, _key not in tree
    if (!root)
        return nullptr;

    // Base case 2: Value found at this node.
    // 3 Sub-cases: 1) Value found in a parent of 2 children
    //              2) Value found in a parent of 1 child
    //              3) Value found in a leaf
    //TODO: Fix this mess
    if (root->_key == key) {
        if (root->_leftChild and root->_rightChild) {      // Parent of 2 children
            root->_key = _findMinKey(root->_rightChild);
            _remove(root->_key, root->_rightChild);

        } else if (root->_leftChild or root->_rightChild) {        // Parent of 1 child
            BinaryNode* tempNode = root;
            root = (root->_leftChild) ? root->_leftChild : root->_rightChild;

            root->parent = tempNode->parent;

            if (tempNode->parent->_leftChild == tempNode)
                tempNode->parent->_leftChild = root;
            else
                tempNode->parent->_rightChild = root;

            delete tempNode;
            --_size;

        } else {    // Leaf
            delete root;
            --_size;
        }

        return true;
    }

    // Recursive case: Value higher or lower than current node's _key
    if (key > root->_key) {
        return _remove(key, root->_rightChild);
    } else {
        return _remove(key, root->_leftChild);
    }

} // End _remove()


/**
 * Finds the minimum _value in a tree or subtree of a given root.
 * @param root - Root of the tree or subtree to be searched.
 * @return Returns the minimum _value.
 */
template <typename K, typename V>
typename BinaryTree<K,V>::BinaryNode* BinaryTree<K,V>::_findMinKey(BinaryNode* root) {

    BinaryNode* minValue = root;

    // Traverse to leaf
    while (minValue->_leftChild) {
        minValue = minValue->_leftChild;
    }

    return minValue;

} // End _findMinKey(root)


/**
 *
 * @tparam K Key for tree positioning/balancing.
 * @tparam V Value stored at given _key.
 * @return Returns the number of elements in the array.
 */
template <typename K, typename V>
inline int BinaryTree<K,V>::size() {
    return _size;
}


// ---------------------------------------------------------------------
//                       Public Traversal Methods

/**
 * Traverses tree or subtree in the order of:
 * 1. Visit root node
 * 2. Visit left subtree
 * 3. Visit right subtree
 **/
template <typename K, typename V>
void BinaryTree<K,V>::preOrderTraverse() {
    _preOrderTraverse(_treeRoot, &_printValue);
}


/**
 * Traverses tree or subtree in the order of:
 * 1. Visit left subtree
 * 2. Visit root node
 * 3. Visit right subtree
 */
template <typename K, typename V>
void BinaryTree<K,V>::inOrderTraverse() {
    _inOrderTraverse(_treeRoot, &_printValue);
}


/**
 * Traverses tree or subtree in the order of:
 * 1. Visit left subtree
 * 2. Visit right subtree
 * 3. Visit root node
 */
template <typename K, typename V>
void BinaryTree<K,V>::postOrderTraverse() {
    _postOrderTraverse(_treeRoot, &_printValue);
}


/**
 * Traverses the tree or subtree from in order of depth, from left to right.
 */
template <typename K, typename V>
void BinaryTree<K,V>::breadthFirstTraverse() {
    _breadthFirstTraverse(_treeRoot, &_printValue);

} // End breadthFirstTraverse()


// ---------------------------------------------------------------------
//                       Private Traversal Methods
//           Applies an operation (function) to each node during traversal.

/**
 * Recursive method for Pre-Order traversal: root -> left -> right
 * @param root - The root of the tree or subtree to be traversed.
 * @param operation - Function to execute on each node.
 */
template <typename K, typename V>
void BinaryTree<K,V>::_preOrderTraverse(BinaryNode* & root, void(*operation)(BinaryNode*)) {
    // Do something
    operation(root);

    // Visit left child
    if (root->_leftChild)
        _preOrderTraverse(root->_leftChild , &_printValue);

    // Visit right child
    if (root->_rightChild)
        _preOrderTraverse(root->_rightChild , &_printValue);

} // End _preOrderTraverse


/**
 * Recursive method for In-Order traversal: left -> root -> right
 * @param root - The root of the tree or subtree to be traversed.
 * @param operation - Function to execute on each node.
 */
template <typename K, typename V>
void BinaryTree<K,V>::_inOrderTraverse(BinaryNode* & root, void(*operation)(BinaryNode*)) {
    // Visit left child
    if (root->_leftChild)
        _inOrderTraverse(root->_leftChild, &_printValue);

    // Do something
    operation(root);

    // Visit right child
    if (root->_rightChild)
        _inOrderTraverse(root->_rightChild, &_printValue);

} // End _inOrderTraverse()


/**
 * Recursive method for Post-Order traversal: left -> right -> root
 * @param root - The root of the tree or subtree to be traversed.
 * @param operation - Function to execute on each node.
 */
template <typename K, typename V>
void BinaryTree<K,V>::_postOrderTraverse(BinaryNode* & root, void(*operation)(BinaryNode*)) {
    // Visit left child
    if (root->_leftChild)
        _postOrderTraverse(root->_leftChild, operation);

    // Visit right child
    if ( root -> _rightChild)
        _postOrderTraverse(root->_rightChild, operation);

    // Do something
    operation(root);

} // End _postOrderTraverse()


/**
 * Traverses the tree or subtree from in order of depth, from left to right, but recursively.
 * @param root - Root of tree or subtree to evaluate.
 * @param operation - Pointer to a function to perform at each node.
 */
template <typename K, typename V>
void BinaryTree<K,V>::_breadthFirstTraverse(BinaryNode* root, void(*operation)(BinaryNode*)) {
    Queue<BinaryNode*> unvisitedNodes;
    unvisitedNodes.enqueue(root);

    while(!unvisitedNodes.isEmpty()) {
        BinaryNode* currentNode = unvisitedNodes.deque();

        if (currentNode->_leftChild) { unvisitedNodes.enqueue(currentNode->_leftChild); }
        if (currentNode->_rightChild) { unvisitedNodes.enqueue(currentNode->_rightChild); }

        operation(currentNode);
    }

} // End _breadthFirstTraverse()


// ---------------------------------------------------------------------
//                       Traversal Operations

/**
 * Deletes a node.
 * @param node - The node to delete.
 */
template <typename K, typename V>
void BinaryTree<K,V>::_deleteNode(BinaryNode* node) {
    delete node;
}


/**
 * Prints the _value of node to console.
 * @param node - The node whose _value will be printed to console.
 */
template <typename K, typename V>
void BinaryTree<K,V>::_printValue(BinaryNode* node) {
    cout << "( " << node->_value << " | " << (node->color ? "R" : "B") << " ) ";
}


/**
 * Finds and sets the height of a node. Used in a breadth first findValue for AVL re-balancing.
 * @param node - BinaryNode whose height needs to be evaluated.
 */
template <typename K, typename T>
void BinaryTree<K,T>::_calcHeight(BinaryNode* node) {

    if (node->_leftChild && node->_rightChild)
        node->height = std::max(node->_leftChild->height, node->_rightChild->height) + 1;

    else if (node->_leftChild)
        node->height = node->_leftChild->height + 1;

    else if (node->_rightChild)
        node->height = node->_rightChild->height + 1;

    else
        node->height = 0;

}