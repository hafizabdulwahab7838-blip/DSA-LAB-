#include <iostream>
#include <string>
using namespace std;

class Package {
public:
    int id;
    string address;
    int startTime;
    int endTime;

    Package() {
        id = 0;
        address = "";
        startTime = 0;
        endTime = 0;
    }
};

class PackageQueue {
private:
    Package* arr;
    int capacity;
    int count;
    int frontIndex;
    int rearIndex;

public:
    PackageQueue(int size) {
        capacity = size;
        arr = new Package[capacity];
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

    bool exists(int id) const {
        for (int i = 0; i < count; i++) {
            if (arr[(frontIndex + i) % capacity].id == id)
                return true;
        }

        return false;
    }

    void enqueue(int id, string address, int start, int end) {
        if (isFull()) {
            cout << "Package queue is full.\n";
            return;
        }

        if (exists(id)) {
            cout << "Package ID already exists.\n";
            return;
        }

        if (id <= 0 || start < 0 || end > 1439 || start > end) {
            cout << "Invalid package details or time window.\n";
            return;
        }

        rearIndex = (rearIndex + 1) % capacity;

        arr[rearIndex].id = id;
        arr[rearIndex].address = address;
        arr[rearIndex].startTime = start;
        arr[rearIndex].endTime = end;

        count++;

        cout << "Package added.\n";
    }

    Package dequeue() {
        if (isEmpty()) {
            cout << "Package queue is empty.\n";
            return Package();
        }

        Package package = arr[frontIndex];

        frontIndex = (frontIndex + 1) % capacity;
        count--;

        return package;
    }

    Package front() const {
        if (isEmpty())
            return Package();

        return arr[frontIndex];
    }

    void display() const {
        if (isEmpty()) {
            cout << "No pending packages.\n";
            return;
        }

        for (int i = 0; i < count; i++) {
            Package p = arr[(frontIndex + i) % capacity];

            cout << "\nPackage ID: " << p.id;
            cout << "\nAddress: " << p.address;
            cout << "\nDelivery window: "
                << p.startTime << " to " << p.endTime << endl;
        }
    }

    void timeToDeliver(int currentTime) {
        while (!isEmpty()) {
            Package p = front();

            if (currentTime > p.endTime) {
                cout << "Package " << p.id << " expired. Skipping.\n";
                dequeue();
            }
            else if (currentTime < p.startTime) {
                cout << "Package " << p.id
                    << " is not ready for delivery yet.\n";
                return;
            }
            else {
                cout << "Package " << p.id
                    << " can be delivered now.\n";
                return;
            }
        }

        cout << "No packages available for delivery.\n";
    }

    ~PackageQueue() {
        delete[] arr;
    }
};

int main() {
    int capacity;

    cout << "Enter maximum number of packages: ";
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Invalid capacity.\n";
        return 0;
    }

    PackageQueue q(capacity);

    int choice, id, start, end, currentTime;
    string address;

    do {
        cout << "\n1. Add Package\n";
        cout << "2. Deliver Front Package\n";
        cout << "3. Check Front Package\n";
        cout << "4. Display Packages\n";
        cout << "5. Check Delivery Time\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter package ID: ";
            cin >> id;

            cout << "Enter recipient address: ";
            getline(cin >> ws, address);

            cout << "Enter start time in minutes from midnight: ";
            cin >> start;

            cout << "Enter end time in minutes from midnight: ";
            cin >> end;

            q.enqueue(id, address, start, end);
            break;

        case 2: {
            Package p = q.dequeue();

            if (p.id != 0)
                cout << "Delivered package: " << p.id << endl;

            break;
        }

        case 3: {
            Package p = q.front();

            if (p.id != 0) {
                cout << "Front package ID: " << p.id << endl;
                cout << "Address: " << p.address << endl;
            }
            else {
                cout << "Package queue is empty.\n";
            }

            break;
        }

        case 4:
            q.display();
            break;

        case 5:
            cout << "Enter current time in minutes from midnight: ";
            cin >> currentTime;

            q.timeToDeliver(currentTime);
            break;

        case 0:
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}