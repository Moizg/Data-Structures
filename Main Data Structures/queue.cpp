#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

class Queue
{
    Node *front, *rear, *temp;
    int size, length;

public:
    Queue(int size)
    {
        this->size = size; // total size of queue
        length = 0;        // number of elements in queue
        front = NULL;
        rear = NULL;
        temp = NULL;
    }
    void enqueue(int data)
    {
        if (front == NULL) // if queue empty
        {
            front = new Node;
            front->val = data;
            front->next = NULL;
            rear = front;
            length++;
            cout << rear->val << " enqueud." << endl;
        }
        else if (length != size) // if queue isn't full then add from rear
        {
            rear->next = new Node;
            rear = rear->next;
            rear->val = data;
            rear->next = NULL;
            length++;
            cout << rear->val << " enqueud." << endl;
        }
        else
        {
            cout << "Queue is full." << endl;
        }
    }
    void dequeue()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
        }
        else if (front == rear) // if only one element present in queue
        {
            temp = front;
            front = front->next;
            rear = rear->next;
            cout << "Dequeueing " << temp->val << endl;
            delete temp;
            temp = NULL;
            length--;
        }
        else
        {
            temp = front;
            front = front->next;
            cout << "Dequeueing " << temp->val << endl;
            delete temp;
            temp = NULL;
            length--;
        }
    }
};

int main()
{
    Queue queue(5);
    int info;
    
    cout << "Enter values to queue:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cin >> info;
        queue.enqueue(info);
    }
    for (int i = 0; i < 6; i++)
    {
        queue.dequeue();
    }

    return 0;
}