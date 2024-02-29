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

class LinkedList
{
    Node *head, *temp, *curr;

public:
    int input;
    LinkedList()
    {
        head = NULL;
    }
    void add()
    {
        if (head == NULL)
        { // if list empty
            head = new Node;
            cout << "Enter value: ";
            cin >> input;
            head->val = input;
            head->next = NULL;
        }
        else
        {
            curr = head;
            cout << "Enter value for searching: ";
            cin >> input;
            while(curr!=NULL)
            {
                if(curr->val==input)
                {
                    temp=new Node;
                    cout<<"Enter value for new node:";
                    cin>>temp->val;
                    temp->next=curr->next;
                    curr->next=temp;
                    break;
                }
                curr=curr->next;
            }
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
            cout << "List is empty." << endl;
        }
        else
        {
            cout << "Enter value for searching: ";
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
            cout << "Value not found." << endl;
        }
        else
        {
            cout << "Value found." << endl;
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
            cout << "Enter value for updating: ";
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
            cout << "Value failed to update." << endl;
        }
        else
        {
            cout << "Value updated." << endl;
        }
    }
    void remove()
    {
        curr = head;
        if (head == NULL)
        {
            cout << "\nList is empty." << endl;
        }
        else
        {
            cout << "Enter value for removing: ";
            cin >> input;
            if (head->val == input) // if there is only one node
            {
                head = head->next;
                delete temp;
            }
            else
            {
                while (curr != NULL)
                {
                    if (curr->next->val == input)
                    {
                        temp = curr->next;
                        curr->next = curr->next->next;
                        delete temp;
                        cout << "Value deleted." << endl;
                        break;
                    }
                    curr = curr->next;
                }
            }
        }
    }
};

int main()
{
    return 0;
}