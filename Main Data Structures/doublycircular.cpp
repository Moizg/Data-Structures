#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node()
    {
        next = NULL;
        prev = NULL;
    }
};

class DoublyCircular
{
    Node *head, *temp, *curr;

public:
    int input;
    DoublyCircular()
    {
        head = NULL;
        temp = NULL;
        curr = NULL;
    }
    void add()
    {
        if (head == NULL)
        {
            head = new Node;
            cout << "\nEnter data: ";
            cin >> head->data;
            head->next = head;
            head->prev = head;
        }
        else
        {
            curr = head;
            temp = new Node;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            // Now curr points to the last node
            cout << "\nEnter data: ";
            cin >> temp->data;
            temp->next = head; // New node's next points to the head
            temp->prev = curr; // New node's prev points to the last node
            curr->next = temp; // Last node's next points to the new node
            head->prev = temp; // Head's prev points to the new node
        }
    }
    void del()
    {
        int found = 0;
        curr = head;
        if (head == NULL)
        {
            cout << "\nList empty!" << endl;
            return;
        }
        cout << "\nEnter value you want to delete: ";
        cin >> input;
        // Handle the case where there's only one node in the list
        if (head->next == head && head->data == input)
        {
            delete head;
            head = NULL;
            cout << "\nValue deleted!" << endl;
            return;
        }

        // Traverse the list and delete the node if found
        do
        {
            if (curr->data == input)
            {
                found++;
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                // If the node being deleted is the head, update the head
                if (curr == head)
                {
                    head = head->next;
                }
                temp = curr; // Store a temporary pointer to the node to be deleted
                curr = curr->next; // Move curr to the next node
                delete temp;       // Delete the node
            }
            else
            {
                curr = curr->next;
            }
        } while (curr != head);

        if (found == 0)
        {
            cout << "\nValue not found!" << endl;
        }
        else
        {
            cout << "\nValue deleted!" << endl;
        }
    }
    void display()
    {
        curr = head;
        if (head == NULL)
        {
            cout << "\nList empty!" << endl;
        }
        else
        {
            do
            {
                cout << "  " << curr->data;
                curr = curr->next;
            } while (curr != head);
        }
    }
};
int main()
{
    DoublyCircular list;

    list.add();
    list.add();
    list.add();
    list.display();

    list.del();
    list.display();
    list.del();
    list.del();
    list.display();

    return 0;
}