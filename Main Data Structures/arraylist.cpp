// array based list using indexes
#include <iostream>
using namespace std;

class ArrayList
{
    int size;
    int length;
    char *arr;
    char *curr;
    int found = 0;

public:
    ArrayList(int size)
    {
        this->size = size;
        length = 0;
        arr = new char[size];
        curr = NULL;
    }
    void start()
    {
        curr = arr;
    }
    void tail()
    {
        curr = arr + length - 1;
    }
    void back()
    {
        curr--;
    }
    void next()
    {
        curr++;
    }
    int length()
    {
        return length;
    }
    int get(int pos)
    {
        int reint;
        if (length == 0)
        {
            cout << "\nList is Empty!" << endl;
        }
        else if (pos < 0 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
        }
        else
        {
            start();
            for (int i = 0; i <= pos; i++)
            {
                if (pos == i)
                {
                    reint = *curr;
                }
                next();
            }
        }
        return reint;
    }
    void update(int val1, int val2)
    {
        int found = 0;
        if (length == 0)
        {
            cout << "\nList is Empty!" << endl;
        }
        else
        {
            start();
            for (int i = 0; i <= length; i++)
            {
                if (*curr == val1)
                {
                    found++;
                    *curr = val2;
                }
                next();
            }
        }
        if (found == 0)
        {
            cout << "The value to be updated not found in list!" << endl;
        }
    }
    void insert(char val, int pos)
    {
        if (size == length)
        {
            cout << "\nList is full!" << endl;
        }
        else if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
        }
        else
        {
            tail();
            for (int i = length; i >= pos; i--)
            {
                *(curr + 1) = *curr;
                back();
            }
            *(curr + 1) = val;
            length++;
        }
    }
    void remove(int pos)
    {
        if (length == 0)
        {
            cout << "\nList is Empty!" << endl;
        }
        else if (pos < 0 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
        }
        else
        {
            start();
            for (int i = 0; i <= pos; i++)
            {
                if (i == pos)
                {
                    found++;
                    for (int j = i; j < (length - 1); j++)
                    {
                        *curr = *(curr + 1);
                        next();
                    }
                }
                else
                {

                    next();
                }
            }
            length--;
        }
        if (found == 0)
            cout << "\nElement not found in the Array!";
        else
            cout << "\nElement Deleted Successfully!";
        cout << endl;
    }
    void printList()
    {
        start();
        for (int i = 1; i <= length; i++)
        {
            cout << *curr << " ";
            next();
        }
        cout << endl;
    }
};
int main()
{
    ArrayList list(6);
    int option;

    cout << "Menu:"
         << "\n1. Add to list"
         << "\n2. Remove from list"
         << "\n3. Update list element"
         << "\n4. Search list"
         << "\n5. Display list" << endl;
    cin >> option;
    if (option == 1)
    {
    }
    else if (option == 2)
    {
    }
    else if (option == 3)
    {
    }
    else if (option == 4)
    {
    }
    else if (option == 5)
    {
    }
    else
    {
        cout << "Wrong option." << endl;
        exit(0);
    }
    return 0;
}