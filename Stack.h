//   File: Stack.h
//  Class: COP 3530, Summer 2023, 51977
// Author: David West
//   Desc: Header file for the Stack class.
//         Contains Node and Stack declarations and definitions.
// ---------------------------------------------------------------------

#include "Singly_Linked_List.cpp"

#ifndef STACK_DATATYPE
#define STACK_DATATYPE

template <typename T>
class Stack : protected Singly_Linked_List<T> {

public:
    // Constructors
    Stack();
    ~Stack();

    // Member Functions
    void push(T data);
    T pop();
    T peek();
    int size();
};


#endif //STACK_DATATYPE
