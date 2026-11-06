
#include <iostream>
using namespace std;

template <typename T>
class AbstractStack {
public:
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractStack() {}
};

template <typename T>
class myStack : public AbstractStack<T> {
private:
    T* arr;
    T* minStack;
    int maxSize;
    int stackTop;
    int minTop;

public:
    myStack(int size) {
        maxSize = size;
        stackTop = -1;
        minTop = -1;

        arr = new T[maxSize];
        minStack = new T[maxSize];
    }

    void push(T value) override {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }

        stackTop++;
        arr[stackTop] = value;

        if (minTop == -1 || value <= minStack[minTop]) {
            minTop++;
            minStack[minTop] = value;
        }

        cout << value << " pushed into stack." << endl;
    }

    T pop() override {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }

        T value = arr[stackTop];

        if (value == minStack[minTop]) {
            minTop--;
        }

        stackTop--;

        cout << value << " popped from stack." << endl;
        return value;
    }

    T top() const override {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }

        return arr[stackTop];
    }

    T getMin() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }

        return minStack[minTop];
    }

    bool isEmpty() const override {
        return stackTop == -1;
    }

    bool isFull() const override {
        return stackTop == maxSize - 1;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements (top to bottom): ";

        for (int i = stackTop; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    ~myStack() {
        delete[] arr;
        delete[] minStack;
    }
};

int main() {
    int size;

    cout << "Enter maximum stack size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid stack size!" << endl;
        return 0;
    }

    myStack<int> s(size);

    int choice;
    int value;

    do {
        
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Show top element" << endl;
        cout << "4. Check if stack is empty" << endl;
        cout << "5. Check if stack is full" << endl;
        cout << "6. Display stack elements" << endl;
        cout << "7. Show minimum element" << endl;
        cout << "8. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            if (!s.isEmpty()) {
                cout << "Top element: " << s.top() << endl;
            }
            else {
                cout << "Stack is empty!" << endl;
            }
            break;

        case 4:
            if (s.isEmpty()) {
                cout << "Stack is empty." << endl;
            }
            else {
                cout << "Stack is not empty." << endl;
            }
            break;

        case 5:
            if (s.isFull()) {
                cout << "Stack is full." << endl;
            }
            else {
                cout << "Stack is not full." << endl;
            }
            break;

        case 6:
            s.display();
            break;

        case 7:
            if (!s.isEmpty()) {
                cout << "Minimum element: "
                    << s.getMin() << endl;
            }
            else {
                cout << "Stack is empty!" << endl;
            }
            break;

        case 8:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}
