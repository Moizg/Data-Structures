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

class Stack
{
    Node *head, *temp;
    int length, size;

public:
    Stack(int x)
    {
        head = NULL;
        length = 0;
        this->size = x;
    }
    void add()
    {
        if (length == size)
        {
            cout << "\nOverflow, stack is full!" << endl;
            return;
        }
        if (head == NULL)
        {
            head = new Node;
            cout << "\nEnter value: ";
            cin >> head->val;
            head->next = NULL;
            length++;
        }
        else
        {
            temp = new Node;
            cout << "\nEnter value: ";
            cin >> temp->val;
            temp->next = head;
            head = temp;
            length++;
        }
    }
    void del()
    {
        if (head == NULL)
        {
            cout << "\nUnderflow, stack is empty!" << endl;
        }
        else
        {
            temp = head;
            head = head->next;
            delete temp;
            length--;
        }
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "\nStack is empty!" << endl;
        }
        else
        {
            temp = head;
            while (temp != NULL)
            {
                cout << "  " << temp->val << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    Stack stack(5);

    stack.add();
    stack.add();
    stack.add();
    stack.add();
    stack.add();
    stack.add(); // to check if overflow condition works
    stack.display();
    stack.del();
    stack.del();
    stack.del();
    stack.del();
    stack.del();
    stack.del(); // to check underflow condition
    stack.display();

    return 0;
}