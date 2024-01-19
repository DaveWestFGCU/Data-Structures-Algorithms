//
// Created by Dave on 1/18/2024.
//

#include <iostream>
#include "Stack.cpp"

using std::cout;
void printStack(Stack<int> & myList);


int main() {

    Stack<int> myStack;

    int values[10] = {5, 12, 37, -1, 10, 55, 14, 27, 37, 89};
    for (auto value : values) {
        myStack.push(value);
    }
    cout << "Size: " << myStack.size() << '\n';
    printStack(myStack);

    myStack.push(64);
    myStack.push(32);

    cout << myStack.peek() << " ";
    cout << myStack.pop();
    cout << myStack.peek() << " ";
    cout << myStack.pop();


    return 0;
}

void printStack(Stack<int> & myList) {
    static int printCall {1};
    cout << "Print " << printCall << ": ";
    ++printCall;

    while (myList.size()) {
        cout << myList.pop() << " ";
    }

    cout << "\n";
}