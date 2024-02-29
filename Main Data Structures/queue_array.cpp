#include <iostream>
using namespace std;

class Queue
{
    int front, rear, size, length, *arr;

public:
    Queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        length = 0;
        arr = new int[size];
    }
    void enqueue(int data)
    {
        if (length != size)
        {
            if (rear == -1) // if empty
            {
                front++;
                rear++;
                arr[rear] = data;
                cout << arr[rear] << " has been queued." << endl;
                length++;
            }
            else if (rear == size - 1) // rear is at end but queue isn't full
            {
                rear = 0;
                arr[rear] = data;
                cout << arr[rear] << " has been queued." << endl;
                length++;
            }
            else
            {
                rear++;
                arr[rear] = data;
                cout << arr[rear] << " has been queued." << endl;
                length++;
            }
        }
        else
        {
            cout << "Queue is full." << endl;
        }
    }
    void dequeue()
    {
        if (front != -1)
        {
            if (front == rear) // if only one element
            {
                cout << arr[front] << " has been dequeued." << endl;
                front = -1;
                rear = -1;
                length--;
            }
            else if (front == size - 1)
            {
                cout << arr[front] << " has been dequeued." << endl;
                front = 0;
                length--;
            }
            else
            {
                cout << arr[front] << " has been dequeued." << endl;
                front++;
                length--;
            }
        }
        else
        {
            cout << "Queue empty." << endl;
        }
    }
};

int main()
{
    Queue queue(6);
    int info;
    
    cout << "Enter values to queue:" << endl;
    for (int i = 0; i < 6; i++)
    {
        cin >> info;
        queue.enqueue(info);
    }
    queue.dequeue();
    cin >> info;
    queue.enqueue(info);
    for (int i = 0; i < 5; i++)
    {
        queue.dequeue();
    }
    
    return 0;
}
