#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next, *prev;
    Node()
    {
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList
{
    Node *head, *temp, *curr;

public:
    int input;
    DoublyLinkedList()
    {
        head = NULL;
        temp = NULL;
        curr = NULL;
    }
    void add()
    {
        if (head == NULL) // if list is empty, add at first node
        {
            head = new Node;
            cout << "Enter a value: ";
            cin >> head->val;
            head->next = NULL;
            head->prev = NULL;
        }
        else
        {
            curr = head;
            cout << "\nEnter value to add after: ";
            cin >> input;
            while (curr != NULL)
            {
                if (curr->val == input)
                {
                    temp = new Node;
                    cout << "\nEnter value to add: ";
                    cin >> temp->val;
                    temp->next = curr->next;
                    temp->prev = curr;
                    if (curr->next != NULL)
                    {
                        curr->next->prev = temp;
                    }
                    curr->next = temp;
                }
                curr = curr->next;
            }
        }
    }
    void remove()
    {
        curr = head;
        int found = 0;
        cout << "Enter value you want to delete: ";
        cin >> input;
        if (head == NULL)
        {
            cout << "\nList is empty." << endl;
        }
        else
        {
            while (curr != NULL)
            {
                if (curr->val == input)
                {
                    found++;
                    temp = curr;
                    if (curr->prev != NULL)
                    {
                        curr->prev->next = curr->next;
                    }
                    if (curr->next != NULL)
                    {
                        curr->next->prev = curr->prev;
                    }
                    break;
                }
                curr = curr->next;
            }
        }
        if (head->val == input)
        {
            head = head->next;
        }
        delete temp;
        if (found == 0)
        {
            cout << "Value not found." << endl;
        }
        else
        {
            cout << "Value deleted." << endl;
        }
    }
    void printlist()
    {
        curr = head;
        if (head == NULL)
        {
            cout << "List is empty." << endl;
        }
        else
        {
            cout << "\nList: " << endl;
            while (curr != NULL)
            {
                cout << "  " << curr->val;
                curr = curr->next;
            }
        }
    }
    void searchlist()
    {
        curr = head;
        int found = 0;
        if (head == NULL)
        {
            cout << "\nList is empty." << endl;
        }
        else
        {
            cout << "\nEnter value for searching: ";
            cin >> input;
            while (curr != NULL)
            {
                if (curr->val == input)
                {
                    found++;
                    break;
                }
                curr = curr->next;
            }
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
    void update()
    {
        curr = head;
        int update = 0;
        if (head == NULL)
        {
            cout << "\nList is empty." << endl;
        }
        else
        {
            cout << "\nEnter value for updating: ";
            cin >> input;
            while (curr != NULL)
            {
                if (curr->val == input)
                {
                    cout << "\nEnter new value: ";
                    cin >> input;
                    curr->val = input;
                    update++;
                    break;
                }
                curr = curr->next;
            }
        }
        if (update == 0)
        {
            cout << "\nValue failed to update." << endl;
        }
        else
        {
            cout << "\nValue updated." << endl;
        }
    }
};

int main()
{
    DoublyLinkedList list;

    list.add(); // add first
    list.printlist();
    list.add(); // add second
    list.printlist();
    list.add(); // add third
    list.printlist();
    list.searchlist();
    list.update();
    list.add();    // add fourth
    list.remove(); // remove from middle
    list.printlist();
    list.remove(); // remove from end
    list.printlist();

    return 0;
}