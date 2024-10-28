#include <iostream>
using namespace std;

class Queue {

    public:
        int Cap, front, rear, size;
        int *arr;

        // Member functions
        bool Enqueue(Queue *queue, int x);
        int Dequeue(Queue *queue);
        int getFront(Queue *queue);
        int getRear(Queue *queue);
        bool isFull(Queue *queue);
        bool isEmpty(Queue *queue);
};

Queue *createQueue(int Cap) {

    Queue *queue = new Queue();
    queue->Cap = Cap;
    queue->front = queue->size = 0;
    queue->rear = Cap - 1;
    queue->arr = new int[(queue->Cap * sizeof(int))];

    return queue;
}

bool Queue::isFull(Queue *queue) {

    return queue->size == queue->Cap;

}

bool Queue::isEmpty(Queue *queue) {
    return queue->size == 0;
}

bool Queue::Enqueue(Queue *queue, int x) {
    if (isFull(queue)) {
        cout << "Queue is full, cannot enqueue " << x << endl;
        return false;
    }

    queue->rear = (queue->rear + 1) % queue->Cap;
    queue->arr[queue->rear] = x;
    queue->size = queue->size + 1;
    cout << x << " has been added to the queue successfully..." << endl;
    return true;
}

int Queue::Dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty, cannot dequeue." << endl;
        return -1;
    }

    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->Cap;
    queue->size = queue->size - 1;
    cout << item << " has been removed from the queue." << endl;
    return item;
}

int Queue::getFront(Queue *queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty, no front element." << endl;
        return -1;
    }
    return queue->arr[queue->front];
}

int Queue::getRear(Queue *queue) {
    if (isEmpty(queue)) {
        cout << "Queue is empty, no rear element." << endl;
        return -1;
    }
    return queue->arr[queue->rear];
}

int main() {
    Queue *queue = createQueue(5);

    // Enqueue elements into the queue
    queue->Enqueue(queue, 10);
    queue->Enqueue(queue, 20);
    queue->Enqueue(queue, 30);
    queue->Enqueue(queue, 40);
    queue->Enqueue(queue, 50);

    // Display front and rear elements
    cout << "Front element is: " << queue->getFront(queue) << endl;
    cout << "Rear element is: " << queue->getRear(queue) << endl;

    // Dequeue elements from the queue
    queue->Dequeue(queue);
    queue->Dequeue(queue);

    // Display front and rear elements after dequeue
    cout << "After dequeuing, front element is: " << queue->getFront(queue) << endl;
    cout << "After dequeuing, rear element is: " << queue->getRear(queue) << endl;

    // Attempt to enqueue another element to check circular nature
    queue->Enqueue(queue, 60);

    cout << "After enqueuing 60, rear element is: " << queue->getRear(queue) << endl;

    // Clean up dynamic memory
    delete[] queue->arr;
    delete queue;

    return 0;
}
