// array based list using pointers
#include <iostream>
using namespace std;

class ArrayList
{
    int size;
    int *length;
    int *arr;
    int *curr;
    int found = 0;

public:
    ArrayList(int size)
    {
        this->size = size;
        length = NULL;
        arr = new int[size];
        curr = NULL;
    }
    void start()
    {
        curr = arr;
    }
    void tail()
    {
        curr = length;
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
        int x = 0;
        start();
        while (curr != length)
        {
            next();
            x++;
        }
        return x;
    }
    int get(int val)
    {
        int reint = 0;
        if (length == NULL)
        {
            cout << "\nList is Empty!" << endl;
        }
        else
        {
            start();
            while (curr <= length)
            {
                if (*curr == val)
                {
                    reint = *curr;
                    cout << "Value found." << endl;
                }
                next();
            }
        }
        if (reint == 0)
        {
            cout << "Value not found in list." << endl;
        }
        else
        {
            return reint;
        }
    }
    void update(int val1, int val2)
    {
        int found = 0;
        if (length == NULL)
        {
            cout << "\nList is Empty!" << endl;
        }
        else
        {
            start();
            while (curr <= length)
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
    void add(int val)
    {
        int *temp=NULL;
        if (length == arr + size - 1)
        {
            cout << "\nList is full!" << endl;
        }
        else
        {
            temp = curr;
            tail();
            while (curr >= temp)
            {
                *(curr + 1) = *curr;
                back();
            }
            *(curr + 1) = val;
            length++;
        }
    }
    void remove(int val)
    {
        if (length == NULL)
        {
            cout << "\nList is Empty!" << endl;
        }
        else
        {
            start();
            while (found==0)
            {
                if (*curr == val)
                {
                    found++;
                    while (curr<length)
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
        while (curr <= length)
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