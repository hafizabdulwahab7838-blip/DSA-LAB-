
#include <iostream>
#include <string>
using namespace std;

template <class T>
int linearSearch(T arr[], int size, T key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
template <class T>
int binarySearch(T arr[], int size, T key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}
class Item {
public:
    virtual void display() = 0;
};

class Book : public Item {
public:
    string title;
    string author;
    int pages;

    Book() {
        title = "";
        author = "";
        pages = 0;
    }

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    void display() override {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};
class Newspaper : public Item {
public:
    string name;
    string date;
    string edition;

    Newspaper() {
        name = "";
        date = "";
        edition = "";
    }

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    void display() override {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};

class Library {
public:
    Book books[100];
    Newspaper newspapers[100];
    int bookCount = 0;
    int newspaperCount = 0;

    void addBook(Book b) {
        if (bookCount < 100)
            books[bookCount++] = b;
    }

    void addNewspaper(Newspaper n) {
        if (newspaperCount < 100)
            newspapers[newspaperCount++] = n;
    }

    void displayCollection() {
        cout << "\nBooks:\n";

        for (int i = 0; i < bookCount; i++) {
            books[i].display();
            cout << endl;
        }

        cout << "Newspapers:\n";

        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
            cout << endl;
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (books[j].pages > books[j + 1].pages) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = 0; j < newspaperCount - i - 1; j++) {
                if (newspapers[j].edition >
                    newspapers[j + 1].edition) {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(string title) {
        string titles[100];

        for (int i = 0; i < bookCount; i++)
            titles[i] = books[i].title;

        int index = linearSearch(titles, bookCount, title);

        if (index != -1)
            return &books[index];

        return nullptr;
    }

    Newspaper* searchNewspaperByName(string name) {
        string names[100];

        for (int i = 0; i < newspaperCount; i++)
            names[i] = newspapers[i].name;

        int index = linearSearch(names, newspaperCount, name);

        if (index != -1)
            return &newspapers[index];

        return nullptr;
    }
};

int main() {
    Book book1("The Catcher in the Rye",
        "J.D. Salinger", 277);

    Book book2("To Kill a Mockingbird",
        "Harper Lee", 324);

    Newspaper newspaper1("Washington Post",
        "2024-10-13", "Morning Edition");

    Newspaper newspaper2("The Times",
        "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook =
        library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook != nullptr) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    Newspaper* foundNewspaper =
        library.searchNewspaperByName("The Times");

    if (foundNewspaper != nullptr) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}
