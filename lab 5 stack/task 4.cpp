
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

    void enqueue(int ticket_id) {
        if (isFull()) {
            cout << "Ticket queue is full!" << endl;
            return;
        }

        if (ticket_id < 1000 || ticket_id > 9999) {
            cout << "Ticket ID must be 4 digits!" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            int index = (frontIndex + i) % maxSize;

            if (arr[index] == ticket_id) {
                cout << "Ticket ID already exists!" << endl;
                return;
            }
        }

        rearIndex = (rearIndex + 1) % maxSize;
        arr[rearIndex] = ticket_id;
        count++;

        cout << "Ticket " << ticket_id
            << " added successfully." << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "No pending tickets!" << endl;
            return -1;
        }

        int ticket = arr[frontIndex];

        frontIndex = (frontIndex + 1) % maxSize;
        count--;

        cout << "Ticket " << ticket
            << " resolved successfully." << endl;

        return ticket;
    }

    int front() const {
        if (isEmpty()) {
            cout << "No pending tickets!" << endl;
            return -1;
        }

        return arr[frontIndex];
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == maxSize;
    }

    void display() const {
        if (isEmpty()) {
            cout << "No pending tickets!" << endl;
            return;
        }

        cout << "Pending Tickets (Front to Rear): ";

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

int main() {
    int size;

    cout << "Enter maximum number of tickets: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }

    Queue q(size);

    int choice;
    int ticket_id;

    do {
        cout << "\n===== CUSTOMER SUPPORT TICKET SYSTEM =====" << endl;
        cout << "1. Add new ticket" << endl;
        cout << "2. Resolve ticket" << endl;
        cout << "3. Show next ticket" << endl;
        cout << "4. Display pending tickets" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter 4-digit ticket ID: ";
            cin >> ticket_id;
            q.enqueue(ticket_id);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            if (!q.isEmpty()) {
                cout << "Next ticket to resolve: "
                    << q.front() << endl;
            }
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting system..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
