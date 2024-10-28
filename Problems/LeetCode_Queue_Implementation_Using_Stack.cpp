#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2; // Two stacks to simulate queue

public:
    MyQueue() {
        // No special initialization needed, stacks are empty by default
    }
    
    void push(int x) {
        // Step 1: Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        
        // Step 2: Push the new element onto s1
        s1.push(x);
        
        // Step 3: Move everything back from s2 to s1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        if (s1.empty()) return -1; // Indicate the queue is empty
        int poppedValue = s1.top();
        s1.pop();
        return poppedValue;
    }
    
    int peek() {
        if (s1.empty()) return -1; // Indicate the queue is empty
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};

// Driver code
int main() {
    MyQueue* queue = new MyQueue();
    queue->push(10);
    queue->push(20);
    queue->push(30);

    cout << "Front element: " << queue->peek() << endl; // Should print 10
    cout << "Popped element: " << queue->pop() << endl; // Should print 10
    cout << "Front element after pop: " << queue->peek() << endl; // Should print 20

    cout << "Is queue empty? " << (queue->empty() ? "Yes" : "No") << endl; // Should print No

    delete queue; // Free allocated memory
    return 0;
}
