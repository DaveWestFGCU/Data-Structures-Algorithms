//   File: Doubly_Linked_List.h
//  Class: COP 3530, Summer 2023, 51977
// Author: David West
//   Desc: Header file for the Doubly_Linked_List class.
//         Contains Node and Doubly_Linked_List declarations and definitions (due to templating).
// ---------------------------------------------------------------------

#ifndef DOUBLY_LINKED_LIST_DATATYPE
#define DOUBLY_LINKED_LIST_DATATYPE

template <typename T>
class Doubly_Linked_List {

protected:
    struct Node {
        T _value;
        Node* nextNode;
        Node* prevNode;

        explicit Node( T val ) : _value{val}, nextNode{nullptr}, prevNode{nullptr} {}
    };

    // Member Data
    Node* headNode;
    Node* tailNode;
    int _size;

public:
    // Constructors
    Doubly_Linked_List();
    ~Doubly_Linked_List();

    // Member Functions
    bool insert(T data, int index = -1);
    T remove(int index);
    T  valueAt(int index);
    int findIndex(T data);
    void makeEmpty();
    [[nodiscard]] int size() const;
};



#endif //DOUBLY_LINKED_LIST_DATATYPE
