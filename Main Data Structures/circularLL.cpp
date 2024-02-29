#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node()
    {
        next = NULL;
    }
};

class RingedLinkedList
{
    Node *head, *temp, *curr;

public:
    int input;
    RingedLinkedList()
    {
        head = NULL;
        temp = NULL;
        curr = NULL;
    }
    void add()
    {
        curr = head;
        if (head == NULL)
        {
            temp = new Node;
            cout << "\nEnter a value: ";
            cin >> temp->val;
            head = temp;
            temp->next = head;
        }
        else
        {
            cout << "\nWant to enter at \n1. Before head or \n2. After head: ";
            cin >> input;
            if (input == 1)
            {
                temp = new Node;
                cout << "\nEnter a value: ";
                cin >> temp->val;
                temp->next = curr->next;
                curr->next = temp;
            }
            else if (input == 2)
            {
                temp = new Node;
                cout << "\nEnter a value: ";
                cin >> temp->val;
                temp->next = curr->next;
                curr->next = temp;
                head = temp;
            }
            else
            {
                cout << "\nWrong input." << endl;
                return;
            }
        }
    }
    void insert() // search based insertion
    {
        int found = 0;
        curr = head->next;
        if (head == NULL)
        {
            cout << "\nList is empty." << endl;
        }
        else
        {
            cout << "\nEnter value you want to look for: ";
            cin >> input;
            do
            {
                if (curr->val == input)
                {
                    found++;
                    temp = new Node;
                    cout << "\nEnter a value: ";
                    cin >> temp->val;
                    temp->next = curr->next;
                    curr->next = temp;
                    if (curr == head)
                    {
                        head = temp;
                    }
                    break;
                }
                curr = curr->next;
            } while (curr != head->next);
        }
        if (found == 0)
        {
            cout << "\nValue not found." << endl;
        }
        else
        {
            cout << "\nValue found." << endl;
        }
    }
    void remove()
    {
        curr = head;
        if (head == NULL)
        {
            cout << "\nList is empty." << endl;
            return;
        }
        cout << "\nEnter value you want to remove: ";
        cin >> input;
        if (head->val == input)
        {
            do
            {
                if (curr->next == head)
                {
                    temp = head;
                    head = head->next;
                    curr->next = temp->next;
                    delete temp;
                }
                curr = curr->next;
            } while (curr->next != head);
        }
        else
        {
            do
            {
                if (curr->next->val == input)
                {
                    temp = curr->next;
                    curr->next = temp->next;
                    delete temp;
                    break;
                }
                curr = curr->next;
            } while (curr->next != head);
        }
    }
    void search()
    {
        curr = head;
        int found = 0;
        cout << "\nEnter value you want to look for: ";
        cin >> input;
        if (head == NULL)
        {
            cout << "\nList is empty." << endl;
        }
        else
        {
            do
            {
                if (curr->val == input)
                {
                    found++;
                    break;
                }
                curr = curr->next;
            } while (curr->next != head);
        }
        if (found == 0)
        {
            cout << "\nValue not found." << endl;
        }
        else
        {
            cout << "\nValue found." << endl;
        }
    }
    void print()
    {
        curr = head->next;
        if (head == NULL)
        {
            cout << "\nList is empty." << endl;
        }
        else
        {
            cout << "\nList: ";
            do
            {
                cout << "  " << curr->val;
                curr = curr->next;
            } while (curr != head->next);
        }
    }
};

int main()
{
    RingedLinkedList circular;

    circular.add(); // 1st node
    circular.print();


    circular.add(); // start addition
    circular.print();

    circular.add(); // end addition
    circular.print(); // printing first 3 additions

    circular.insert(); // add using search
    circular.print();

    circular.remove(); // remove from start
    circular.print();

    circular.remove(); // remove from middle
    circular.print();

    return 0;
}