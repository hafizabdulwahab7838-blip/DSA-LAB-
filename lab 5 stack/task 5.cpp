#include <iostream>
#include <string>
using namespace std;

class PrintQueue {
private:
    string* arr;
    int capacity;
    int count;
    int frontIndex;
    int rearIndex;

public:
    PrintQueue(int size) {
        capacity = size;
        arr = new string[capacity];
        count = 0;
        frontIndex = 0;
        rearIndex = -1;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    void enqueue(string document_name) {
        if (isFull()) {
            cout << "Print queue is full.\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = document_name;
        count++;

        cout << "Print job added.\n";
    }

    string dequeue() {
        if (isEmpty()) {
            cout << "No print jobs pending.\n";
            return "";
        }

        string document = arr[frontIndex];
        frontIndex = (frontIndex + 1) % capacity;
        count--;

        return document;
    }

    string front() const {
        if (isEmpty())
            return "";

        return arr[frontIndex];
    }

    void display() const {
        if (isEmpty()) {
            cout << "No print jobs pending.\n";
            return;
        }

        cout << "Pending print jobs:\n";

        for (int i = 0; i < count; i++)
            cout << arr[(frontIndex + i) % capacity] << endl;
    }

    ~PrintQueue() {
        delete[] arr;
    }
};

int main() {
    int capacity;
    cout << "Enter maximum print jobs: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Invalid capacity.\n";
        return 0;
    }

    PrintQueue q(capacity);
    int choice;
    string document;

    do {
        cout << "\n1. Add Print Job\n2. Print Front Document\n";
        cout << "3. Check Front Document\n4. Display Queue\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter document name: ";
            getline(cin >> ws, document);
            q.enqueue(document);
            break;

        case 2:
            document = q.dequeue();
            if (document != "")
                cout << "Printing: " << document << endl;
            break;

        case 3:
            document = q.front();
            if (document != "")
                cout << "Next document: " << document << endl;
            else
                cout << "No print jobs pending.\n";
            break;

        case 4:
            q.display();
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}