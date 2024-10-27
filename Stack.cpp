#include <iostream>
using namespace std;
#define CAPACITY 100

class Stack {
    int top;

    public:

        int stack[CAPACITY];

        Stack() {
            top = -1;
        }

        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push( int x )  {
    if ( top == CAPACITY - 1) return false;
    stack[++top] = x;
    return true;
}

int Stack::pop() {
    if ( !isEmpty() ) {
        int removedElement = stack[top--];
        return removedElement;
    }
    return top;
}

int Stack::peek() {
    if ( !isEmpty() ) {
        return stack[top];
    }
    return top;
}

bool Stack::isEmpty() {
    if ( top == -1 ) return true;
    return false;
}

int main () {

    Stack stackDS;
    cout << stackDS.isEmpty() << endl;
    stackDS.push(10);
    stackDS.push(20);
    stackDS.push(30);
    stackDS.push(40);

    cout << stackDS.peek() << endl;

    cout << stackDS.pop() << " is poped from Stack, Current top is: " << stackDS.peek() << endl;

    cout << stackDS.isEmpty() << endl;

    return 0;
}