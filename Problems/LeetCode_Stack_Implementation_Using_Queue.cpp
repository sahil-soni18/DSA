#include <iostream>
#include <queue>
using namespace std;

class MyStack {
private:
    queue<int> q1, q2; // Two queues to simulate stack

public:
    MyStack() {
        // No special initialization needed, queues are empty by default
    }
    
    void push(int x) {
        // Step 1: Push the new element onto q2
        q2.push(x);
        
        // Step 2: Push all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    int pop() {
        if (q1.empty()) return -1; // Indicate the stack is empty
        int poppedValue = q1.front();
        q1.pop();
        return poppedValue;
    }
    
    int top() {
        if (q1.empty()) return -1; // Indicate the stack is empty
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

// Driver code
int main() {
    MyStack* stack = new MyStack();
    stack->push(10);
    stack->push(20);
    stack->push(30);

    cout << "Top element: " << stack->top() << endl; // Should print 30
    cout << "Popped element: " << stack->pop() << endl; // Should print 30
    cout << "Top element after pop: " << stack->top() << endl; // Should print 20

    cout << "Is stack empty? " << (stack->empty() ? "Yes" : "No") << endl; // Should print No

    delete stack; // Free allocated memory
    return 0;
}
