#include "Queue.h"
// -----------------------------------------------------------------------------
// Function Definitions
// -----------------------------------------------------------------------------

/**
 * Default constructor
 */
template <typename T>
Queue<T>::Queue() {
    Doubly_Linked_List<T>::headNode = nullptr;
    Doubly_Linked_List<T>::tailNode = nullptr;
    Doubly_Linked_List<T>::_size = 0;
}


/**
 * Destructor
 */
template <typename T>
Queue<T>::~Queue( ) {
    Doubly_Linked_List<T>::makeEmpty( );
}


/**
 * Adds a node with the given _value to the back of the queue.
 * @param data (int) - The _value to be held by the node.
 */
template <typename T>
void Queue<T>::enqueue( T data ) {
    Doubly_Linked_List<T>::insert(data, Doubly_Linked_List<T>::_size );
}


/**
 * Removes the first node from the queue.
 * @return (int) The _value of the deleted node.
 */
template <typename T>
T Queue<T>::dequeue( ) {
    return Doubly_Linked_List<T>::remove(0 );
}


/**
 * Returns the _value of the first node of the queue.
 * @return (int) - The _value of the first node of the queue.
 */
template <typename T>
T Queue<T>::peek( ) {
    return Doubly_Linked_List<T>::headNode -> _value;
}


/**
 * Returns the number of nodes in the queue.
 * @return (int) - The number of nodes in the queue.
 */
template <typename T>
inline int Queue<T>::size( ) {
    return Doubly_Linked_List<T>::_size;
}