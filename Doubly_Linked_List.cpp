//
// Created by Dave on 1/18/2024.
//

#include "Doubly_Linked_List.h"

// -----------------------------------------------------------------------------
// Function Definitions
// -----------------------------------------------------------------------------

/**
 * Default Constructor
 */
template <typename T>
Doubly_Linked_List<T>::Doubly_Linked_List() {
    headNode = nullptr;
    tailNode = nullptr;
    _size = 0;
}


/**
 * Destructor
 */
template <typename T>
Doubly_Linked_List<T>::~Doubly_Linked_List() {
    makeEmpty();
}


/**
 * Returns the _size of the list.
 * @return (int) The _size of the list (last position = n - 1).
 */
template <typename T>
inline int Doubly_Linked_List<T>::size() const {
    return _size;
} // end size


/**
 * Deletes each node in the list, resulting in a list with no nodes.
 */
template <typename T>
void Doubly_Linked_List<T>::makeEmpty( ) {
    Node* tempNode;

    while (headNode) {
        tempNode = headNode;
        headNode = headNode->nextNode;

        delete tempNode;
    }

    tailNode = nullptr;
    _size = 0;
} // end makeEmpty


/**
 * Adds a node at the given index.
 * @param data (int) The _value of the new node to be added.
 * @param index (int) The index for the new node to be placed.
 * @return (bool) True if the given index is within the list. False the given
 * index is outside of the list.
 */
template <typename T>
bool Doubly_Linked_List<T>::insert(T data, int index) {
    if (index == -1) index = _size;     // Default index is -1, add to the end

    // Index out of bounds
    if (index < 0 || index > _size)
        return false;

    Node *newNode = new Node(data);

    // Doubly_Linked_List has no nodes
    if (_size == 0) {
        headNode = newNode;
        tailNode = headNode;
    }

        // Doubly_Linked_List has 1+ nodes
    else {
        Node *posNode;
        posNode = headNode;

        // Add to front of list
        if ( index == 0 ) {
            headNode->prevNode = newNode;
            newNode->nextNode = headNode;
            headNode = newNode;
        }

            // Add to rear of list
        else if ( index == _size ) {
            tailNode->nextNode = newNode;
            newNode->prevNode = tailNode;
            tailNode = newNode;
        }

            // Add to middle of list
        else {

            // Traverse list
            for (int i = 0; i < index - 1; i++)
                posNode = posNode->nextNode;

            newNode->nextNode = posNode->nextNode;
            newNode->prevNode = posNode;

            posNode->nextNode = newNode;
            newNode->nextNode->prevNode = newNode;
        } // end add to middle

    } // end list w/ 1+ nodes

    _size++;

    return true;
} // end insert


/**
 * Deletes a node at the given index.
 * @param index (int) Index at which to delete a node.
 * @return (int) Returns the _value of the node that was deleted or -1 if the
 * given index was outside of the list.
 */
template <typename T>
T Doubly_Linked_List<T>::remove(int index ) {
    // Index out of bounds (including no nodes in list)
    // Figure out how to make an out-of-bounds return for template return type.

    Node* posNode;

    // Remove head node
    if (index == 0) {
        posNode = headNode;

        // Removing last node
        if (_size == 1) {
            headNode = nullptr;
            tailNode = nullptr;
        }
        else {
            headNode = headNode->nextNode;
            headNode->prevNode = nullptr;
        }

    }

        // Remove tail node
    else if (index == _size - 1) {
        posNode = tailNode;
        tailNode = tailNode->prevNode;
        tailNode->nextNode = nullptr;
    }

        // Remove middle node
    else {
        posNode = headNode;

        // Traverse to position to remove
        for (int i = 0; i < index; i++)
            posNode = posNode->nextNode;

        posNode->prevNode->nextNode = posNode->nextNode;
        posNode->nextNode->prevNode = posNode->prevNode;
    }

    // Save node's _value to return later
    T tempValue = posNode->_value;
    delete posNode;

    _size--;

    if (_size == 1) {
        if (index == 0) {
            headNode = tailNode;
        } else {
            tailNode = headNode;
        }
    }

    return tempValue;

} // end remove


/**
 * Searches the list for a node with the given _value.
 * @param data (int) The _value to search the list for.
 * @return (int) The index of the first node with the given _value or -1 if the
 * _value was not found within the list.
 */
template <typename T>
int Doubly_Linked_List<T>::findIndex(T data) {
    int index = 0;
    Node* posNode;
    posNode = headNode;

    while (posNode) {
        if (posNode->_value == data)
            return index;
        posNode = posNode->nextNode;
        index++;
    }

    return -1;
} // end findIndex


/**
 * Returns a pointer to the _value held by the node at the given index.
 * @param index - The index of the node from which to retrieve the _value.
 * @return A void pointer to the _value. Must be typecast for use.
 */
template <typename T>
T Doubly_Linked_List<T>::valueAt(int index) {
    Node* posNode;
    posNode = headNode;

    for (int i = 0; i < index; i++) {
        posNode = posNode->nextNode;
    }

    return posNode->_value;
}