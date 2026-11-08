
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

    void InsertBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        cout << value << " inserted at beginning." << endl;
    }

    void InsertEnd(int value) {
        Node* newNode = new Node(value);

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

        cout << value << " inserted at end." << endl;
    }

    void DeleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << value << " deleted successfully." << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr &&
            temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << value << " not found!" << endl;
        }
        else {
            Node* deleteNode = temp->next;
            temp->next = deleteNode->next;
            delete deleteNode;

            cout << value << " deleted successfully." << endl;
        }
    }

    void Display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

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
    int choice, value;

    do {
       
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete by Value" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.InsertBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.InsertEnd(value);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            list.DeleteNode(value);
            break;

        case 4:
            list.Display();
            break;

        case 5:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
