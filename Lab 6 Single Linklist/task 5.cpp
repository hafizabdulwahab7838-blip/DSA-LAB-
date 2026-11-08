
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int studentID;
    string studentName;
    int priority;
    Node* next;

    Node(int id, string name, int p) {
        studentID = id;
        studentName = name;
        priority = p;
        next = NULL;
    }
};

class ReservationQueue {
private:
    Node* head;
    Node* tail;
    int count;

    string getPriorityName(int p) {
        if (p == 3) return "Research";
        if (p == 2) return "Assignment";
        return "Casual Reading";
    }

public:
    ReservationQueue() {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    void addStudent(int id, string name, int priority) {
        Node* newNode = new Node(id, name, priority);

        if (head == NULL || priority > head->priority) {
            newNode->next = head;
            head = newNode;

            if (tail == NULL)
                tail = newNode;

            count++;
            cout << name << " added successfully.\n";
            return;
        }

        Node* temp = head;

        while (temp->next != NULL &&
            temp->next->priority >= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL)
            tail = newNode;

        count++;
        cout << name << " added successfully.\n";
    }

    void removeStudent(int id) {
        if (head == NULL) {
            cout << "Reservation list is empty.\n";
            return;
        }

        Node* temp = head;
        Node* previous = NULL;

        while (temp != NULL && temp->studentID != id) {
            previous = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Student not found.\n";
            return;
        }

        if (previous == NULL)
            head = temp->next;
        else
            previous->next = temp->next;

        if (temp == tail)
            tail = previous;

        cout << temp->studentName
            << "'s reservation cancelled.\n";

        delete temp;
        count--;
    }

    void updatePriority(int id, int newPriority) {
        if (newPriority < 1 || newPriority > 3) {
            cout << "Invalid priority.\n";
            return;
        }

        Node* temp = head;

        while (temp != NULL && temp->studentID != id)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Student not found.\n";
            return;
        }

        string name = temp->studentName;

        removeStudent(id);
        addStudent(id, name, newPriority);

        cout << "Priority updated to "
            << getPriorityName(newPriority) << ".\n";
    }

    void display() {
        if (head == NULL) {
            cout << "No reservations available.\n";
            return;
        }

        Node* temp = head;

        cout << "\nID\tName\t\tPriority\n";
    

        while (temp != NULL) {
            cout << temp->studentID << "\t"
                << temp->studentName << "\t\t"
                << getPriorityName(temp->priority)
                << endl;

            temp = temp->next;
        }
    }

    void totalReservations() {
        cout << "Total reservations: " << count << endl;
    }

    void serveNextStudent() {
        if (head == NULL) {
            cout << "No student waiting for this book.\n";
            return;
        }

        Node* temp = head;

        cout << "Book issued to: "
            << temp->studentName << endl;

        head = head->next;

        if (head == NULL)
            tail = NULL;

        delete temp;
        count--;
    }

    ~ReservationQueue() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

class Library {
private:
    ReservationQueue book1;
    ReservationQueue book2;

public:
    ReservationQueue* getQueue(int bookID) {
        if (bookID == 1)
            return &book1;
        else if (bookID == 2)
            return &book2;
        else
            return NULL;
    }
};

int main() {
    Library library;


    cout << "\nBOOK 1: Data Structures\n";

    ReservationQueue* q1 = library.getQueue(1);

    q1->addStudent(101, "Ali", 1);
    q1->addStudent(102, "Ahmed", 2);
    q1->addStudent(103, "Sara", 3);
    q1->addStudent(104, "Ayesha", 2);

    cout << "\nCurrent Reservation List:";
    q1->display();

    cout << "\nUpdating Ali's priority:\n";
    q1->updatePriority(101, 3);

    q1->display();

    cout << "\nCancelling Ahmed's reservation:\n";
    q1->removeStudent(102);

    q1->display();

    cout << "\nReservation Count:\n";
    q1->totalReservations();

    cout << "\nBook Returned:\n";
    q1->serveNextStudent();

    q1->display();

    cout << "\n\nBOOK 2: Database Systems\n";

    ReservationQueue* q2 = library.getQueue(2);

    q2->addStudent(201, "Usman", 1);
    q2->addStudent(202, "Fatima", 3);
    q2->addStudent(203, "Hassan", 2);

    cout << "\nCurrent Reservation List:";
    q2->display();

    cout << "\nUpdating Usman's priority:\n";
    q2->updatePriority(201, 3);

    q2->display();

    cout << "\nReservation Count:\n";
    q2->totalReservations();

    cout << "\nBook Returned:\n";
    q2->serveNextStudent();

    q2->display();

    return 0;
}
