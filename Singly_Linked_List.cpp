
#include "Singly_Linked_List.h"

// -----------------------------------------------------------------------------
// Function Definitions
// -----------------------------------------------------------------------------

/**
 * Default Constructor
 */
template <typename T>
Singly_Linked_List<T>::Singly_Linked_List() {
    _headNode = nullptr;
    _size = 0;
}


/**
 * Destructor
 */
template <typename T>
Singly_Linked_List<T>::~Singly_Linked_List() {
    makeEmpty();
}


/**
 * Returns the _size of the list.
 * @return (int) The _size of the list (last position = n - 1).
 */
template <typename T>
inline int Singly_Linked_List<T>::size() const {
    return _size;
} // end size


/**
 * Deletes each node in the list, resulting in a list with no nodes.
 */
template <typename T>
void Singly_Linked_List<T>::makeEmpty( ) {
    Node* tempNode;

    while (_headNode) {
        tempNode = _headNode;
        _headNode = _headNode->_nextNode;

        delete tempNode;
    }

    _size = 0;
} // end makeEmpty


/**
 * Adds a node at the given index.
 * @param value (int) The value of the new node to be added.
 * @param index (int) The index for the new node to be placed.
 * @return (bool) True if the given index is within the list. False the given
 * index is outside of the list.
 */
template <typename T>
bool Singly_Linked_List<T>::insert(T value, int index) {
    if (index == -1) index = _size;     // Add to the tail if no index is given

    // Check for index out-of-bounds
    if (index < 0 || index > _size)
        return false;

    Node *newNode = new Node(value);

    // List has no nodes
    if (_size == 0) {
        _headNode = newNode;
    }

        // List has 1+ nodes
    else {
        // Add into head position
        if ( index == 0 ) {
            newNode->_nextNode = _headNode;
            _headNode = newNode;
        }

            // Add into the list
        else {
            Node *positionNode;
            positionNode = _headNode;

            // Traverse list
            for (int i = 0; i < index - 1; i++)
                positionNode = positionNode->_nextNode;

            newNode->_nextNode = positionNode->_nextNode;

            positionNode->_nextNode = newNode;
        } // end add to middle

    } // end list w/ 1+ nodes

    _size++;

    return true;
} // end insert


/**
 * Deletes a node at the given index.
 * @param index (int) Index at which to delete a node.
 * @return (int) Returns the value of the node that was deleted or -1 if the
 * given index was outside of the list.
 */
template <typename T>
T Singly_Linked_List<T>::remove(int index) {
    // Index out of bounds (including no nodes in list)
    // Figure out how to make an out-of-bounds return for template return type.

    Node* deadNode;

    // Remove head node
    if (index == 0) {
        deadNode = _headNode;

        // Removing last node
        if (_size == 1) {
            _headNode = nullptr;
        }
        else {
            _headNode = _headNode->_nextNode;
        }
    }

        // Remove middle node
    else {
        Node* positionNode;
        positionNode = _headNode;

        // Traverse to position to remove
        for (int i = 0; i < index-1; i++)
            positionNode = positionNode->_nextNode;

        deadNode = positionNode->_nextNode;
        positionNode->_nextNode = deadNode->_nextNode;
    }

    // Save node's value to return later
    T tempValue = deadNode->_value;
    delete deadNode;

    _size--;

    return tempValue;

} // end remove


/**
 * Searches the list for a node with the given value.
 * @param data (int) The value to search the list for.
 * @return (int) The index of the first node with the given value or -1 if the
 * value was not found within the list.
 */
template <typename T>
int Singly_Linked_List<T>::findIndex(T value) {
    int index = 0;
    Node* posNode;
    posNode = _headNode;

    while (posNode) {
        if (posNode->_value == value)
            return index;
        posNode = posNode->_nextNode;
        index++;
    }

    return -1;
} // end findIndex


/**
 * Returns a pointer to the value held by the node at the given index.
 * @param index - The index of the node from which to retrieve the value.
 * @return A void pointer to the value. Must be typecast for use.
 */
template <typename T>
T Singly_Linked_List<T>::valueAt(int index) {
    Node* posNode;
    posNode = _headNode;

    for (int i = 0; i < index; i++) {
        posNode = posNode->_nextNode;
    }

    return posNode->_value;
}