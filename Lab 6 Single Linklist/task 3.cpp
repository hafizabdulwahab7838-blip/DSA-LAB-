
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void Insert(int value, int position) {
        Node* newNode = new Node(value);

        if (position < 1) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            cout << "Node inserted successfully." << endl;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Node inserted successfully." << endl;
    }

    void Delete(int position) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (position < 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* temp = head;

        if (position == 1) {
            head = head->next;
            delete temp;
            cout << "Node deleted successfully." << endl;
            return;
        }

        for (int i = 1; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;

        cout << "Node deleted successfully." << endl;
    }

    void Search(int value) {
        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Element found at position "
                    << position << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Element not found!" << endl;
    }

    void Count() {
        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Total number of nodes: " << count << endl;
    }

    void Display() {
        Node* temp = head;

        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "Linked List: ";

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    ~SinglyLinkedList() {
        Node* temp;

        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    SinglyLinkedList list;
    int choice, value, position;

    do {
       
        cout << "1. Insert at Specific Position" << endl;
        cout << "2. Delete at Specific Position" << endl;
        cout << "3. Search an Element" << endl;
        cout << "4. Count Total Nodes" << endl;
        cout << "5. Display List" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            list.Insert(value, position);
            break;

        case 2:
            cout << "Enter position to delete: ";
            cin >> position;
            list.Delete(position);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            list.Search(value);
            break;

        case 4:
            list.Count();
            break;

        case 5:
            list.Display();
            break;

        case 6:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
