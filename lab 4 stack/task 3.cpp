
#include <iostream>
using namespace std;

class myCarStack {
private:
    string* cars;
    int maxSize;
    int stackTop;

public:
    myCarStack(int size) {
        maxSize = size;
        stackTop = -1;
        cars = new string[maxSize];
    }

    void push(string carNumber) {
        if (isFull()) {
            cout << "Parking lot is full!" << endl;
            return;
        }

        stackTop++;
        cars[stackTop] = carNumber;

        cout << "Car " << carNumber
            << " parked successfully." << endl;
    }

    string pop() {
        if (isEmpty()) {
            cout << "Parking lot is empty!" << endl;
            return "";
        }

        string carNumber = cars[stackTop];
        stackTop--;

        return carNumber;
    }

    string top() const {
        if (isEmpty()) {
            return "";
        }

        return cars[stackTop];
    }

    bool isEmpty() const {
        return stackTop == -1;
    }

    bool isFull() const {
        return stackTop == maxSize - 1;
    }

    int totalCars() const {
        return stackTop + 1;
    }

    bool search(string carNumber) const {
        for (int i = 0; i <= stackTop; i++) {
            if (cars[i] == carNumber) {
                return true;
            }
        }

        return false;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Parking lot is empty!" << endl;
            return;
        }

        cout << "\nParked Cars (Top to Bottom):" << endl;

        for (int i = stackTop; i >= 0; i--) {
            cout << cars[i] << endl;
        }
    }

    void removeCar(string carNumber) {
        if (isEmpty()) {
            cout << "Parking lot is empty!" << endl;
            return;
        }

        if (!search(carNumber)) {
            cout << "Car " << carNumber
                << " is not present in parking lot." << endl;
            return;
        }

        myCarStack temp(maxSize);

        while (top() != carNumber) {
            temp.push(pop());
        }

        pop();

        while (!temp.isEmpty()) {
            push(temp.pop());
        }

        cout << "Car " << carNumber
            << " removed successfully." << endl;
    }

    ~myCarStack() {
        delete[] cars;
    }
};

int main() {
    myCarStack parking(8);

    int choice;
    string carNumber;

    do {
        cout << "\n===== PARKING LOT MENU =====" << endl;
        cout << "1. Park a new car" << endl;
        cout << "2. Remove a car by car number" << endl;
        cout << "3. View parked cars" << endl;
        cout << "4. Total cars parked" << endl;
        cout << "5. Search for a car" << endl;
        cout << "6. Show top car" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (!parking.isFull()) {
                cout << "Enter car number: ";
                cin >> carNumber;

                if (parking.search(carNumber)) {
                    cout << "This car is already parked!" << endl;
                }
                else {
                    parking.push(carNumber);
                }
            }
            else {
                cout << "Parking lot is full!" << endl;
            }
            break;

        case 2:
            cout << "Enter car number to remove: ";
            cin >> carNumber;
            parking.removeCar(carNumber);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "Total cars parked: "
                << parking.totalCars() << endl;
            break;

        case 5:
            cout << "Enter car number to search: ";
            cin >> carNumber;

            if (parking.search(carNumber)) {
                cout << "Car " << carNumber
                    << " is present." << endl;
            }
            else {
                cout << "Car " << carNumber
                    << " is not present." << endl;
            }
            break;

        case 6:
            if (!parking.isEmpty()) {
                cout << "Top car: "
                    << parking.top() << endl;
            }
            else {
                cout << "Parking lot is empty!" << endl;
            }
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
