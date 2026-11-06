
#include <iostream>
#include <string>
using namespace std;

template <class T>
class List
{
protected:
    T* arr;
    int maxSize;
    int currentSize;

public:
    List(int size = 10)
    {
        maxSize = size;
        currentSize = 0;
        arr = new T[maxSize];
    }

    List(const List<T>& other)
    {
        maxSize = other.maxSize;
        currentSize = other.currentSize;

        arr = new T[maxSize];

        for (int i = 0; i < currentSize; i++)
            arr[i] = other.arr[i];
    }

    virtual void addElementAtFirstIndex(T) = 0;
    virtual void addElementAtLastIndex(T) = 0;
    virtual T removeElementFromEnd() = 0;
    virtual void removeElementFromStart() = 0;

    virtual ~List()
    {
        delete[] arr;
    }
};

template <class T>
class MyList : public List<T>
{
public:
    MyList(int size = 10) : List<T>(size) {}

    MyList(const MyList<T>& other) : List<T>(other) {}

    bool empty()
    {
        return this->currentSize == 0;
    }

    bool full()
    {
        return this->currentSize == this->maxSize;
    }

    int size()
    {
        return this->currentSize;
    }

    void addElementAtFirstIndex(T value) override
    {
        if (full())
        {
            cout << "List is full!\n";
            return;
        }

        for (int i = this->currentSize; i > 0; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[0] = value;
        this->currentSize++;
    }

    void addElementAtLastIndex(T value) override
    {
        if (full())
        {
            cout << "List is full!\n";
            return;
        }

        this->arr[this->currentSize++] = value;
    }

    T removeElementFromEnd() override
    {
        if (empty())
        {
            cout << "List is empty!\n";
            return T();
        }

        return this->arr[--this->currentSize];
    }

    void removeElementFromStart() override
    {
        if (empty())
        {
            cout << "List is empty!\n";
            return;
        }

        for (int i = 0; i < this->currentSize - 1; i++)
            this->arr[i] = this->arr[i + 1];

        this->currentSize--;
    }

    bool insertAt(int index, T value)
    {
        if (full() || index < 0 ||
            index > this->currentSize)
            return false;

        for (int i = this->currentSize; i > index; i--)
            this->arr[i] = this->arr[i - 1];

        this->arr[index] = value;
        this->currentSize++;

        return true;
    }

    T last()
    {
        if (empty())
            return T();

        return this->arr[this->currentSize - 1];
    }

    bool search(T value)
    {
        for (int i = 0; i < this->currentSize; i++)
            if (this->arr[i] == value)
                return true;

        return false;
    }

    void display()
    {
        cout << "List: ";

        for (int i = 0; i < this->currentSize; i++)
            cout << this->arr[i] << " ";

        cout << endl;
    }

    ~MyList() override = default;
};

template <class T>
class CustomList : public MyList<T>
{
    void rotateRight(int start, int len, int r)
    {
        if (len <= 1)
            return;

        r %= len;

        for (int k = 0; k < r; k++)
        {
            T temp = this->arr[start + len - 1];

            for (int i = start + len - 1; i > start; i--)
                this->arr[i] = this->arr[i - 1];

            this->arr[start] = temp;
        }
    }

    void rotateLeft(int start, int len, int r)
    {
        if (len <= 1)
            return;

        r %= len;

        for (int k = 0; k < r; k++)
        {
            T temp = this->arr[start];

            for (int i = start; i < start + len - 1; i++)
                this->arr[i] = this->arr[i + 1];

            this->arr[start + len - 1] = temp;
        }
    }

public:
    CustomList(int size = 10) : MyList<T>(size) {}

    CustomList(const CustomList<T>& other)
        : MyList<T>(other) {}

    // Alphabetically second-largest distinct string
    T secondMaxString()
    {
        T largest = T(), second = T();
        bool hasLargest = false, hasSecond = false;

        for (int i = 0; i < this->currentSize; i++)
        {
            T value = this->arr[i];

            if (!hasLargest || value > largest)
            {
                if (hasLargest && value != largest)
                {
                    second = largest;
                    hasSecond = true;
                }

                largest = value;
                hasLargest = true;
            }
            else if (value < largest &&
                (!hasSecond || value > second))
            {
                second = value;
                hasSecond = true;
            }
        }

        if (!hasSecond)
        {
            cout << "Second largest string not found.\n";
            return T();
        }

        return second;
    }

    // Alphabetically second-smallest distinct string
    T secondMinString()
    {
        T smallest = T(), second = T();
        bool hasSmallest = false, hasSecond = false;

        for (int i = 0; i < this->currentSize; i++)
        {
            T value = this->arr[i];

            if (!hasSmallest || value < smallest)
            {
                if (hasSmallest && value != smallest)
                {
                    second = smallest;
                    hasSecond = true;
                }

                smallest = value;
                hasSmallest = true;
            }
            else if (value > smallest &&
                (!hasSecond || value < second))
            {
                second = value;
                hasSecond = true;
            }
        }

        if (!hasSecond)
        {
            cout << "Second smallest string not found.\n";
            return T();
        }

        return second;
    }

    void printDuplicates()
    {
        bool found = false;

        cout << "Duplicate strings: ";

        for (int i = 0; i < this->currentSize; i++)
        {
            bool alreadySeen = false;

            for (int k = 0; k < i; k++)
            {
                if (this->arr[k] == this->arr[i])
                {
                    alreadySeen = true;
                    break;
                }
            }

            if (alreadySeen)
                continue;

            int count = 0;

            for (int j = 0; j < this->currentSize; j++)
                if (this->arr[i] == this->arr[j])
                    count++;

            if (count > 1)
            {
                cout << this->arr[i] << " ";
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << endl;
    }

    void rotateClockwaise(int r)
    {
        if (r < 0)
            r = 0;

        int n = this->currentSize;
        int half1 = (n + 1) / 2;
        int half2 = n - half1;

        rotateRight(0, half1, r);
        rotateRight(half1, half2, r);
    }

    void rotateanitclockwaise(int rt)
    {
        if (rt < 0)
            rt = 0;

        int n = this->currentSize;
        int half1 = (n + 1) / 2;
        int half2 = n - half1;

        rotateLeft(0, half1, rt);
        rotateLeft(half1, half2, rt);
    }

    ~CustomList() override = default;
};

int main()
{
    int capacity;

    cout << "Enter capacity: ";
    cin >> capacity;
    if (capacity <= 0)
    {
        cout << "Capacity must be positive.\n";
        return 0;
    }
    CustomList<string> list(capacity);
    int choice, r, index;
    string value;

    do
    {
        cout << "\n--- STRING CUSTOM LIST MENU ---\n";
        cout << "1. Add at first\n";
        cout << "2. Add at last\n";
        cout << "3. Insert at index\n";
        cout << "4. Remove from start\n";
        cout << "5. Remove from end\n";
        cout << "6. Display list\n";
        cout << "7. Second alphabetically largest string\n";
        cout << "8. Second alphabetically smallest string\n";
        cout << "9. Print duplicates\n";
        cout << "10. Rotate clockwise\n";
        cout << "11. Rotate anti-clockwise\n";
        cout << "12. Search string\n";
        cout << "13. Get last string\n";
        cout << "14. List size\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter string: ";
            cin >> value;
            list.addElementAtFirstIndex(value);
            break;

        case 2:
            cout << "Enter string: ";
            cin >> value;
            list.addElementAtLastIndex(value);
            break;

        case 3:
            cout << "Enter index: ";
            cin >> index;
            cout << "Enter string: ";
            cin >> value;

            if (list.insertAt(index, value))
                cout << "Inserted successfully.\n";
            else
                cout << "Invalid index or list is full.\n";
            break;

        case 4:
            list.removeElementFromStart();
            break;

        case 5:
            if (!list.empty())
                cout << "Removed: "
                << list.removeElementFromEnd() << endl;
            else
                cout << "List is empty!\n";
            break;

        case 6:
            list.display();
            break;

        case 7:
            if (!list.empty())
                cout << "Second largest: "
                << list.secondMaxString() << endl;
            else
                cout << "List is empty!\n";
            break;

        case 8:
            if (!list.empty())
                cout << "Second smallest: "
                << list.secondMinString() << endl;
            else
                cout << "List is empty!\n";
            break;

        case 9:
            list.printDuplicates();
            break;

        case 10:
            cout << "Enter rotation count: ";
            cin >> r;
            list.rotateClockwaise(r);
            list.display();
            break;

        case 11:
            cout << "Enter rotation count: ";
            cin >> r;
            list.rotateanitclockwaise(r);
            list.display();
            break;

        case 12:
            cout << "Enter string to search: ";
            cin >> value;

            cout << (list.search(value)
                ? "String found.\n"
                : "String not found.\n");
            break;

        case 13:
            if (!list.empty())
                cout << "Last string: " << list.last() << endl;
            else
                cout << "List is empty!\n";
            break;

        case 14:
            cout << "Current size: " << list.size() << endl;
            break;

        case 0:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
