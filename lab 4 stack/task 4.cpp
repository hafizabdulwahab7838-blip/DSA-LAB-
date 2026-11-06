
#include <iostream>
using namespace std;

class Stack {
private:
    string* arr;
    int maxSize;
    int stackTop;

public:
    Stack(int size) {
        maxSize = size;
        stackTop = -1;
        arr = new string[maxSize];
    }

    void push(string value) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }

        stackTop++;
        arr[stackTop] = value;
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }

        string value = arr[stackTop];
        stackTop--;

        return value;
    }

    bool isEmpty() const {
        return stackTop == -1;
    }

    bool isFull() const {
        return stackTop == maxSize - 1;
    }

    void clear() {
        stackTop = -1;
    }

    ~Stack() {
        delete[] arr;
    }
};

class TextEditor {
private:
    string text;
    Stack undoStack;
    Stack redoStack;

public:
    TextEditor(int size) : undoStack(size), redoStack(size) {
        text = "";
    }

    void typeCharacter(char ch) {
        if (undoStack.isFull()) {
            cout << "Undo history is full!" << endl;
            return;
        }

        string action = "T";
        action += ch;

        undoStack.push(action);
        redoStack.clear();

        text += ch;

        cout << "Character typed." << endl;
    }

    void deleteCharacter() {
        if (text.empty()) {
            cout << "Text is empty!" << endl;
            return;
        }

        if (undoStack.isFull()) {
            cout << "Undo history is full!" << endl;
            return;
        }

        char ch = text[text.length() - 1];

        string action = "D";
        action += ch;

        undoStack.push(action);
        redoStack.clear();

        text.erase(text.length() - 1, 1);

        cout << "Character deleted." << endl;
    }

    void undo() {
        if (undoStack.isEmpty()) {
            cout << "Nothing to undo!" << endl;
            return;
        }

        string action = undoStack.pop();

        if (action[0] == 'T') {
            text.erase(text.length() - 1, 1);
        }
        else if (action[0] == 'D') {
            text += action[1];
        }

        redoStack.push(action);

        cout << "Undo successful." << endl;
    }

    void redo() {
        if (redoStack.isEmpty()) {
            cout << "Nothing to redo!" << endl;
            return;
        }

        string action = redoStack.pop();

        if (action[0] == 'T') {
            text += action[1];
        }
        else if (action[0] == 'D') {
            text.erase(text.length() - 1, 1);
        }

        undoStack.push(action);

        cout << "Redo successful." << endl;
    }

    void displayText() const {
        cout << "Current Text: " << text << endl;
    }
};

int main() {
    TextEditor editor(100);

    int choice;
    char ch;

    do {
        cout << "\n===== TEXT EDITOR MENU =====" << endl;
        cout << "1. Type a character" << endl;
        cout << "2. Delete a character" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Redo" << endl;
        cout << "5. Display text" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter character: ";
            cin >> ch;
            editor.typeCharacter(ch);
            break;

        case 2:
            editor.deleteCharacter();
            break;

        case 3:
            editor.undo();
            break;

        case 4:
            editor.redo();
            break;

        case 5:
            editor.displayText();
            break;

        case 6:
            cout << "Exiting editor..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}
