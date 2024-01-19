//   File: Doubly_Linked_List.h
//  Class: COP 3530, Summer 2023, 51977
// Author: David West
//   Desc: Header file for the Doubly_Linked_List class.
//         Contains Node and Doubly_Linked_List declarations and definitions (due to templating).
// ---------------------------------------------------------------------

#ifndef SINGLY_LINKED_LIST_DATATYPE
#define SINGLY_LINKED_LIST_DATATYPE

template <typename T>
class Singly_Linked_List {

protected:
    struct Node {
        T _value;
        Node* _nextNode;

        explicit Node( T val ) : _value{val}, _nextNode{nullptr} {}
    };

    // Member Data
    Node* _headNode;
    int _size;

public:
    // Constructors
    Singly_Linked_List();
    ~Singly_Linked_List();

    // Member Functions
    bool insert(T value, int index = -1);
    T remove(int index);
    T  valueAt(int index);
    int findIndex(T value);
    void makeEmpty();
    [[nodiscard]] int size() const;
};



#endif //SINGLY_LINKED_LIST_DATATYPE
