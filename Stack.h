//   File: Stack.h
//  Class: COP 3530, Summer 2023, 51977
// Author: David West
//   Desc: Header file for the Stack class.
//         Contains Node and Stack declarations and definitions (due to templating).
// ---------------------------------------------------------------------

#ifndef STACK_DATATYPE
#define STACK_DATATYPE

#include "List.h"

template <typename T>
class Stack : protected List<T> {

public:
    // Constructors
    Stack();
    ~Stack();

    // Member Functions
    void push( T data );
    T pop();
    T peek();
    int size();
};


// -----------------------------------------------------------------------------
// Function Definitions
// -----------------------------------------------------------------------------

/**
 * Default Constructor
 */
template <typename T>
Stack<T>::Stack() {
    List<T>::headNode = nullptr;
    List<T>::tailNode = nullptr;
    List<T>::_size = 0;
}


/**
 * Destructor
 */
template <typename T>
Stack<T>::~Stack( ) {
    List<T>::makeEmpty( );
}


/**
 * Adds a node of a given value to the top of the stack.
 * @param data (int) Value of the node to add.
 */
template <typename T>
void Stack<T>::push( T data ) {
    List<T>::insert( data, 0 );
}


/**
 * Deletes a node from the top of the stack.
 * @return (int) Value of the deleted node.
 */
template <typename T>
T Stack<T>::pop() {
    return List<T>::remove( 0 );
}


/**
 * Returns the value of the top node on the stack.
 * @return (int) Value of the top node on the stack.
 */
template <typename T>
T Stack<T>::peek() {
    return List<T>::headNode -> value;
}


/**
 * Returns the number of nodes in the stack.
 * @return (int) The number of nodes in the stack.
 */
template <typename T>
inline int Stack<T>::size( ) {
    return List<T>::_size;
}

#endif //STACK_DATATYPE
