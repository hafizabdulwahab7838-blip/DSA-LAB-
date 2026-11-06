
#include <iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int maxSize;
    int frontIndex;
    int rearIndex;
    int count;

public:
    myQueue(int size) {
        maxSize = size;
        frontIndex = 0;
        rearIndex = -1;
        count = 0;

        arr = new T[maxSize];
    }

    void enQueue(T value) override {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        rearIndex = (rearIndex + 1) % maxSize;
        arr[rearIndex] = value;
        count++;

        cout << value << " added to queue." << endl;
    }

    T deQueue() override {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return T();
        }

        T value = arr[frontIndex];

        frontIndex = (frontIndex + 1) % maxSize;
        count--;

        cout << value << " removed from queue." << endl;
        return value;
    }

    T front() const override {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return T();
        }

        return arr[frontIndex];
    }

    bool isEmpty() const override {
        return count == 0;
    }

    bool isFull() const override {
        return count == maxSize;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements (front to rear): ";

        for (int i = 0; i < count; i++) {
            int index = (frontIndex + i) % maxSize;
            cout << arr[index] << " ";
        }

        cout << endl;
    }

    ~myQueue() {
        delete[] arr;
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

    myQueue<int> q(size);

    int choice;
    int value;

    do {
       
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Show front element" << endl;
        cout << "4. Check if queue is empty" << endl;
        cout << "5. Check if queue is full" << endl;
        cout << "6. Display queue" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            q.deQueue();
            break;

        case 3:
            if (!q.isEmpty()) {
                cout << "Front element: "
                    << q.front() << endl;
            }
            else {
                cout << "Queue is empty!" << endl;
            }
            break;

        case 4:
            if (q.isEmpty()) {
                cout << "Queue is empty." << endl;
            }
            else {
                cout << "Queue is not empty." << endl;
            }
            break;

        case 5:
            if (q.isFull()) {
                cout << "Queue is full." << endl;
            }
            else {
                cout << "Queue is not full." << endl;
            }
            break;

        case 6:
            q.display();
            break;

        case 7:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
