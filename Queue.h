//   File: Queue.h
//  Class: COP 3530, Summer 2023, 51977
// Author: David West
//   Desc: Header file for the Queue class.
//         Contains Node and Queue declarations and definitions (due to templating).
// ---------------------------------------------------------------------

#ifndef QUEUE_DATATYPE
#define QUEUE_DATATYPE

#include "Doubly_Linked_List.h"

template <typename T>
class Queue : protected Doubly_Linked_List<T> {

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

#endif //QUEUE_DATATYPE
