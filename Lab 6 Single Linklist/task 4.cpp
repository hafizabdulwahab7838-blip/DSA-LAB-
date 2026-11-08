
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string patientName) {
        name = patientName;
        next = nullptr;
    }
};

class HospitalQueue {
private:
    Node* head;

public:
    HospitalQueue() {
        head = nullptr;
    }

    void AddPatient(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << name << " added to the queue." << endl;
    }

    void RemovePatient(string name) {
        if (head == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << name << " cancelled the appointment." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr &&
            temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << name << " not found in the queue!" << endl;
        }
        else {
            Node* deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode;

            cout << name << " cancelled the appointment." << endl;
        }
    }

    void DisplayPatients() {
        if (head == nullptr) {
            cout << "No patients waiting." << endl;
            return;
        }

        Node* temp = head;

        cout << "\nPatients Waiting for Consultation:" << endl;

        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void CountPatients() {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total patients in queue: " << count << endl;
    }

    ~HospitalQueue() {
        Node* temp;

        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    HospitalQueue hospital;
    int choice;
    string name;

    do {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====" << endl;
        cout << "1. Add New Patient" << endl;
        cout << "2. Remove Patient (Cancel Appointment)" << endl;
        cout << "3. Display Patient Queue" << endl;
        cout << "4. Count Total Patients" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patient name: ";
            cin >> name;
            hospital.AddPatient(name);
            break;

        case 2:
            cout << "Enter patient name to cancel: ";
            cin >> name;
            hospital.RemovePatient(name);
            break;

        case 3:
            hospital.DisplayPatients();
            break;

        case 4:
            hospital.CountPatients();
            break;

        case 5:
            cout << "Hospital system closed." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
