
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

  
    void CreateNode(int value) {
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
};

int main() {
    SinglyLinkedList list;

    list.CreateNode(10);
    list.CreateNode(20);
    list.CreateNode(30);
    list.CreateNode(40);
    list.CreateNode(50);

    list.Display();

    return 0;
}
