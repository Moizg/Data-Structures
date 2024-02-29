#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node *next;
    Node()
    {
        next = NULL;
    }
};

class CircularLL
{
    Node *head, *temp, *curr;

public:
    string input;
    CircularLL()
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
            cout << "\nEnter a name: ";
            cin >> temp->name;
            head = temp;
            temp->next = head;
        }
        else
        {
            temp = new Node;
            cout << "\nEnter a name: ";
            cin >> temp->name;
            temp->next = curr->next;
            curr->next = temp;
            head = temp;
        }
    }
    void remove(int x)
    {
        int count = 1;
        curr = head;
        temp = head->next; // temp will always be one node ahead of curr to make deleting nodes easier
        if (head == NULL)
        {
            cout << "\nList is empty." << endl;
        }
        else
        {
            do
            {
                if (count == x)
                {
                    // if node being deleted is head then move head one back then delete
                    if (temp == head)
                    {
                        head = curr;
                    }
                    curr->next = temp->next;
                    delete temp;
                    temp = curr->next;
                    count = 1;
                }
                curr = curr->next;
                temp = temp->next;
                count++;
            } while (curr->next != curr); // loop will terminate when only one node is left
        }
        cout << "\nThe winnner and safe person is:  " << curr->name << endl;
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
            do
            {
                cout << "  " << curr->name;
                curr = curr->next;
            } while (curr != head->next);
        }
    }
};

int main()
{
    CircularLL circular;
    int input, index;
    index = 0;

    cout << "\nHow many children are playing?\nNumber of children: ";
    cin >> input;

    while (index != input)
    {
        circular.add();
        index++;
    }
    cout << "\nPlayers in the game: " << endl;
    circular.print();

    cout << "\nEnter the number that is killed every time: ";
    cin >> input;

    circular.remove(input);

    return 0;
}