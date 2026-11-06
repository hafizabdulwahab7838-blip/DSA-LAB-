
#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int maxSize;
    int frontIndex;
    int rearIndex;
    int count;

public:
    Queue(int size) {
        maxSize = size;
        frontIndex = 0;
        rearIndex = -1;
        count = 0;

        arr = new int[maxSize];
    }

    void enqueue(int value) {
        if (count == maxSize) {
            cout << "Queue is full!" << endl;
            return;
        }

        rearIndex = (rearIndex + 1) % maxSize;
        arr[rearIndex] = value;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        int value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % maxSize;
        count--;

        return value;
    }

    int front() const {
        if (isEmpty()) {
            return -1;
        }

        return arr[frontIndex];
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    void display() const {
        for (int i = 0; i < count; i++) {
            int index = (frontIndex + i) % maxSize;
            cout << arr[index] << " ";
        }

        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

class Stack {
private:
    int* arr;
    int maxSize;
    int stackTop;

public:
    Stack(int size) {
        maxSize = size;
        stackTop = -1;
        arr = new int[maxSize];
    }

    void push(int value) {
        if (stackTop < maxSize - 1) {
            stackTop++;
            arr[stackTop] = value;
        }
    }

    int pop() {
        if (stackTop == -1) {
            return -1;
        }

        int value = arr[stackTop];
        stackTop--;

        return value;
    }

    bool isEmpty() const {
        return stackTop == -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

void reverseFirstK(Queue& q, int k) {
    int n = q.size();

    if (k <= 1 || n == 0) {
        return;
    }

    if (k > n) {
        k = n;
    }

    Stack s(k);

    for (int i = 0; i < k; i++) {
        s.push(q.dequeue());
    }

    while (!s.isEmpty()) {
        q.enqueue(s.pop());
    }

    for (int i = 0; i < n - k; i++) {
        q.enqueue(q.dequeue());
    }
}

int main() {
    int n;
    int value;
    int k;

    cout << "Enter number of queue elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }

    Queue q(n);

    cout << "Enter queue elements: ";

    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cout << "Enter K: ";
    cin >> k;

    cout << "Original Queue: ";
    q.display();

    reverseFirstK(q, k);

    cout << "Reversed Queue: ";
    q.display();

    return 0;
}
