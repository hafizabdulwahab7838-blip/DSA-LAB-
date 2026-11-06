
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
    int maxSize;
    int stackTop;

public:
    myStack(int size) {
        maxSize = size;
        stackTop = -1;
        arr = new T[maxSize];
    }

    void push(T value) override {
        if (isFull()) {
            cout << "Stack is full!" << endl;
        }
        else {
            stackTop++;
            arr[stackTop] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    T pop() override {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return T();
        }

        T value = arr[stackTop];
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
    }
};

int main() {
    int size;
    cout << "Enter the maximum size of stack: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid stack size!" << endl;
        return 0;
    }

    myStack<int> s(size);

    int choice;
    int value;

    do {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Top" << endl;
        cout << "4. Check Empty" << endl;
        cout << "5. Check Full" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
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
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}
