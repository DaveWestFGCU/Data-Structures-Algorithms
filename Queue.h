//   File: Queue.h
//  Class: COP 3530, Summer 2023, 51977
// Author: David West
//   Desc: Header file for the Queue class.
//         Contains Node and Queue declarations and definitions (due to templating).
// ---------------------------------------------------------------------

#ifndef QUEUE_DATATYPE
#define QUEUE_DATATYPE

#include "List.h"

template <typename T>
class Queue : protected List<T> {

public:
    // Constructors
    Queue();
    ~Queue();

    // Member Functions
    void enqueue( T data );
    T dequeue();
    T peek();
    int size();
};


// -----------------------------------------------------------------------------
// Function Definitions
// -----------------------------------------------------------------------------

/**
 * Default constructor
 */
template <typename T>
Queue<T>::Queue() {
    List<T>::headNode = nullptr;
    List<T>::tailNode = nullptr;
    List<T>::_size = 0;
}


/**
 * Destructor
 */
template <typename T>
Queue<T>::~Queue( ) {
    List<T>::makeEmpty( );
}


/**
 * Adds a node with the given value to the back of the queue.
 * @param data (int) - The value to be held by the node.
 */
template <typename T>
void Queue<T>::enqueue( T data ) {
    List<T>::insert( data, List<T>::_size );
}


/**
 * Removes the first node from the queue.
 * @return (int) The value of the deleted node.
 */
template <typename T>
T Queue<T>::dequeue( ) {
    return List<T>::remove( 0 );
}


/**
 * Returns the value of the first node of the queue.
 * @return (int) - The value of the first node of the queue.
 */
template <typename T>
T Queue<T>::peek( ) {
    return List<T>::headNode -> value;
}


/**
 * Returns the number of nodes in the queue.
 * @return (int) - The number of nodes in the queue.
 */
template <typename T>
inline int Queue<T>::size( ) {
    return List<T>::_size;
}

#endif //QUEUE_DATATYPE
