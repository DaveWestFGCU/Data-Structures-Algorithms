
#include "Stack.h"

// -----------------------------------------------------------------------------
// Stack Method Definitions
// -----------------------------------------------------------------------------

/**
 * Default Constructor
 */
template <typename T>
Stack<T>::Stack() {
    Singly_Linked_List<T>::_headNode = nullptr;
    Singly_Linked_List<T>::_size = 0;
}


/**
 * Destructor
 */
template <typename T>
Stack<T>::~Stack() {
    Singly_Linked_List<T>::makeEmpty();
}


/**
 * Adds a node of a given _value to the top of the stack.
 * @param data (int) Value of the node to add.
 */
template <typename T>
void Stack<T>::push(T data) {
    Singly_Linked_List<T>::insert(data, 0);
}


/**
 * Deletes a node from the top of the stack.
 * @return (int) Value of the deleted node.
 */
template <typename T>
T Stack<T>::pop() {
    return Singly_Linked_List<T>::remove(0);
}


/**
 * Returns the _value of the top node on the stack.
 * @return (int) Value of the top node on the stack.
 */
template <typename T>
T Stack<T>::peek() {
    return Singly_Linked_List<T>::_headNode->_value;
}


/**
 * Returns the number of nodes in the stack.
 * @return (int) The number of nodes in the stack.
 */
template <typename T>
inline int Stack<T>::size() {
    return Singly_Linked_List<T>::_size;
}
