//#include <iostream>
//using namespace std;
//
//template <class T>
//class List
//{
//protected:
//    T* arr;
//    int maxSize;
//    int currentSize;
//public:
//    List(int size = 10)
//    {
//        maxSize = size;
//        currentSize = 0;
//        arr = new T[maxSize];
//    }
//    List(const List<T>& other)
//    {
//        maxSize = other.maxSize;
//        currentSize = other.currentSize;
//
//        arr = new T[maxSize];
//
//        for (int i = 0; i < currentSize; i++)
//            arr[i] = other.arr[i];
//    }
//    virtual void addElementAtFirstIndex(T) = 0;
//    virtual void addElementAtLastIndex(T) = 0;
//    virtual T removeElementFromEnd() = 0;
//    virtual void removeElementFromStart() = 0;
//
//    virtual ~List()
//    {
//        delete[] arr;
//    }
//};
//template <class T>
//class MyList : public List<T>
//{
//public:
//    MyList(int size = 10) : List<T>(size) {}
//
//    MyList(const MyList<T>& other) : List<T>(other) {}
//    bool empty()
//    {
//        return this->currentSize == 0;
//    }
//    bool full()
//    {
//        return this->currentSize == this->maxSize;
//    }
//    int size()
//    {
//        return this->currentSize;
//    }
//    void addElementAtFirstIndex(T value) override
//    {
//        if (full())
//        {
//            cout << "List is full!\n";
//            return;
//        }
//
//        for (int i = this->currentSize; i > 0; i--)
//            this->arr[i] = this->arr[i - 1];
//
//        this->arr[0] = value;
//        this->currentSize++;
//    }
//    void addElementAtLastIndex(T value) override
//    {
//        if (full())
//        {
//            cout << "List is full!\n";
//            return;
//        }
//
//        this->arr[this->currentSize] = value;
//        this->currentSize++;
//    }
//    T removeElementFromEnd() override
//    {
//        if (empty())
//        {
//            cout << "List is empty:" << emdl;
//            return T();
//        }
//
//        T value = this->arr[this->currentSize - 1];
//        this->currentSize--;
//
//        return value;
//    }
//    void removeElementFromStart() override
//    {
//        if (empty())
//        {
//            cout << "List is empty!\n";
//            return;
//        }
//
//        for (int i = 0; i < this->currentSize - 1; i++)
//            this->arr[i] = this->arr[i + 1];
//
//        this->currentSize--;
//    }
//    bool insertAt(int index, T value)
//    {
//        if (full() || index < 0 ||
//            index > this->currentSize)
//            return false;
//
//        for (int i = this->currentSize; i > index; i--)
//            this->arr[i] = this->arr[i - 1];
//
//        this->arr[index] = value;
//        this->currentSize++;
//
//        return true;
//    }
//    T last()
//    {
//        if (empty())
//        {
//            cout << "List is empty!\n";
//            return T();
//        }
//
//        return this->arr[this->currentSize - 1];
//    }
//    bool search(T value)
//    {
//        for (int i = 0; i < this->currentSize; i++)
//        {
//            if (this->arr[i] == value)
//                return true;
//        }
//
//        return false;
//    }
//    void display()
//    {
//        if (empty())
//        {
//            cout << "List is empty.\n";
//            return;
//        }
//
//        cout << "List: ";
//
//        for (int i = 0; i < this->currentSize; i++)
//            cout << this->arr[i] << " ";
//
//        cout << endl;
//    }
//
//    ~MyList() override = default;
//};
//int main()
//{
//    int capacity;
//
//    cout << "Enter maximum capacity: ";
//    cin >> capacity;
//
//    if (capacity <= 0)
//    {
//        cout << "Capacity must be positive.\n";
//        return 0;
//    }
//
//    MyList<int> list(capacity);
//
//    int choice, value, index;
//
//    do
//    {
//        cout << "\n--- MYLIST MENU ---\n";
//        cout << "1. Add at first\n";
//        cout << "2. Add at last\n";
//        cout << "3. Remove from start\n";
//        cout << "4. Remove from end\n";
//        cout << "5. Insert at index\n";
//        cout << "6. Get last element\n";
//        cout << "7. Search value\n";
//        cout << "8. Check empty\n";
//        cout << "9. Check full\n";
//        cout << "10. Get size\n";
//        cout << "11. Display list\n";
//        cout << "0. Exit\n";
//        cout << "Enter choice: ";
//        cin >> choice;
//
//        switch (choice)
//        {
//        case 1:
//            cout << "Enter value: ";
//            cin >> value;
//            list.addElementAtFirstIndex(value);
//            break;
//
//        case 2:
//            cout << "Enter value: ";
//            cin >> value;
//            list.addElementAtLastIndex(value);
//            break;
//
//        case 3:
//            list.removeElementFromStart();
//            break;
//
//        case 4:
//            if (!list.empty())
//                cout << "Removed: "
//                << list.removeElementFromEnd() << endl;
//            else
//                cout << "List is empty!\n";
//            break;
//
//        case 5:
//            cout << "Enter index (0-based): ";
//            cin >> index;
//            cout << "Enter value: ";
//            cin >> value;
//
//            if (list.insertAt(index, value))
//                cout << "Value inserted successfully.\n";
//            else
//                cout << "Invalid index or list is full.\n";
//            break;
//
//        case 6:
//            if (!list.empty())
//                cout << "Last element: " << list.last() << endl;
//            else
//                cout << "List is empty!\n";
//            break;
//
//        case 7:
//            cout << "Enter value to search: ";
//            cin >> value;
//
//            if (list.search(value))
//                cout << "Value found.\n";
//            else
//                cout << "Value not found.\n";
//            break;
//
//        case 8:
//            cout << (list.empty() ? "List is empty.\n"
//                : "List is not empty.\n");
//            break;
//
//        case 9:
//            cout << (list.full() ? "List is full.\n"
//                : "List is not full.\n");
//            break;
//
//        case 10:
//            cout << "Current size: " << list.size() << endl;
//            break;
//
//        case 11:
//            list.display();
//            break;
//        case 0:
//            cout << "Program ended.\n";
//            break;
//        default:
//            cout << "Invalid choice!\n";
//        }
//    } while (choice != 0);
//
//    return 0;
//}
