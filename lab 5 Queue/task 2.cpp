
#include <iostream>
using namespace std;

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
        if (isFull()) {
            return;
        }

        stackTop++;
        arr[stackTop] = value;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        int value = arr[stackTop];
        stackTop--;

        return value;
    }

    int top() const {
        if (isEmpty()) {
            return -1;
        }

        return arr[stackTop];
    }

    bool isEmpty() const {
        return stackTop == -1;
    }

    bool isFull() const {
        return stackTop == maxSize - 1;
    }

    int size() const {
        return stackTop + 1;
    }

    ~Stack() {
        delete[] arr;
    }
};

class Queue {
private:
    Stack stack1;
    Stack stack2;
    int maxSize;

    void transfer() {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
    }

public:
    Queue(int size) : stack1(size), stack2(size) {
        maxSize = size;
    }

    void enQueue(int value) {
        if (stack1.size() + stack2.size() == maxSize) {
            cout << "Queue is full!" << endl;
            return;
        }

        stack1.push(value);

        cout << value << " enqueued successfully." << endl;
    }

    int deQueue() {
        if (stack2.isEmpty()) {
            transfer();
        }

        if (stack2.isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        int value = stack2.pop();

        cout << value << " dequeued successfully." << endl;

        return value;
    }

    int front() {
        if (stack2.isEmpty()) {
            transfer();
        }

        if (stack2.isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return stack2.top();
    }

    bool isEmpty() const {
        return stack1.isEmpty() && stack2.isEmpty();
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements (front to rear): ";

        for (int i = stack2.size() - 1; i >= 0; i--) {
            cout << stack2.pop() << " ";
        }

        Stack temp(maxSize);

        while (!stack2.isEmpty()) {
            temp.push(stack2.pop());
        }

        while (!temp.isEmpty()) {
            stack2.push(temp.pop());
        }

        Stack temp2(maxSize);

        while (!stack1.isEmpty()) {
            temp2.push(stack1.pop());
        }

        while (!temp2.isEmpty()) {
            int value = temp2.pop();
            cout << value << " ";
            stack1.push(value);
        }

        cout << endl;
    }
};

int main() {
    int size;

    cout << "Enter maximum queue size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }

    Queue q(size);

    int choice;
    int value;

    do {
        cout << "\n===== QUEUE USING TWO STACKS =====" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Display Elements" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            q.deQueue();
            break;

        case 3:
            if (!q.isEmpty()) {
                cout << "Front element: " << q.front() << endl;
            }
            else {
                cout << "Queue is empty!" << endl;
            }
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
