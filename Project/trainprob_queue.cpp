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
    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
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
        }
        else if (length != size) // if queue isn't full then add from rear
        {
            rear->next = new Node;
            rear = rear->next;
            rear->val = data;
            rear->next = NULL;
            length++;
        }
        else
        {
            cout << "Queue is full." << endl;
        }
    }
    int dequeue()
    {
        int data;
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
        }
        else if (front == rear) // if only one element present in queue
        {
            temp = front;
            data = front->val;
            front = front->next;
            rear = rear->next;
            delete temp;
            temp = NULL;
            length--;
        }
        else
        {
            temp = front;
            data = front->val;
            front = front->next;
            delete temp;
            temp = NULL;
            length--;
        }
        return data;
    }
    int peek()
    {
        if (front != NULL)
        {
            return front->val;
        }
    }
};

int main()
{
    Queue inputT(9), H1(5), H2(5), H3(5), outputT(9);
    int info;

    cout << "Enter values for input track:" << endl;
    for (int i = 0; i < 9; i++)
    {
        cin >> info;
        inputT.enqueue(info);
    }

    int min = 1;
    for (int i = 0; i < 9; i++)
    {
        info = inputT.dequeue();
        if (info == min)
        {
            outputT.enqueue(info);
            cout << "Moves " << info << " to output track." << endl;
            min++;
        }
        for (int j = 0; j < 1; j++)
        {
            if (H1.peek() == min)
            {
                cout << "Moves " << H1.peek() << " to output track." << endl;
                outputT.enqueue(H1.dequeue());
                min++;
                j = -1;
            }
            else if (H2.peek() == min)
            {
                cout << "Moves " << H2.peek() << " to output track." << endl;
                outputT.enqueue(H2.dequeue());
                min++;
                j = -1;
            }
            else if (H3.peek() == min)
            {
                cout << "Moves " << H3.peek() << " to output track." << endl;
                outputT.enqueue(H3.dequeue());
                min++;
                j = -1;
            }
        }
        int count = 2;
        for (int z = 0; z < 1; z++)
        {
            if (info != min && info > min)
            {
                bool push = false;
                if (H1.isEmpty() || (!H1.isEmpty() && H1.peek() < info))
                {
                    cout << "Moves " << info << " to H1 track." << endl;
                    H1.enqueue(info);
                    push = true;
                }
                else if (H2.isEmpty() || (!H2.isEmpty() && H2.peek() < info))
                {
                    cout << "Moves " << info << " to H2 track." << endl;
                    H2.enqueue(info);
                    push = true;
                }
                else if (H3.isEmpty() || (!H3.isEmpty() && H3.peek() < info))
                {
                    cout << "Moves " << info << " to H3 track." << endl;
                    H3.enqueue(info);
                    push = true;
                }
                else if (push == false) // inter-track shuffling only allowed twice
                {
                    cout << "Trying inter track suffling" << endl;
                    if (H1.peek() > H2.peek() && (H1.peek() - H2.peek()) <= 2 && count != 0)
                    {
                        cout << "Moves " << H1.peek() << " from H1 to H2 track." << endl;
                        H2.enqueue(H1.dequeue());
                        z = -1;
                        count--;
                    }
                    else if (H1.peek() > H3.peek() && (H1.peek() - H3.peek()) <= 2 && count != 0)
                    {
                        cout << "Moves " << H1.peek() << " from H1 to H3 track." << endl;
                        H3.enqueue(H1.dequeue());
                        z = -1;
                        count--;
                    }
                    else if (H2.peek() > H1.peek() && (H2.peek() - H1.peek()) <= 2 && count != 0)
                    {
                        cout << "Moves " << H2.peek() << " from H2 to H1 track." << endl;
                        H1.enqueue(H2.dequeue());
                        z = -1;
                        count--;
                    }
                    else if (H2.peek() > H3.peek() && (H2.peek() - H3.peek()) <= 2 && count != 0)
                    {
                        cout << "Moves " << H2.peek() << " from H2 to H1 track." << endl;
                        H3.enqueue(H2.dequeue());
                        z = -1;
                        count--;
                    }
                    else if (H3.peek() > H1.peek() && (H3.peek() - H1.peek()) <= 2 && count != 0)
                    {
                        cout << "Moves " << H3.peek() << " from H3 to H1 track." << endl;
                        H1.enqueue(H3.dequeue());
                        z = -1;
                        count--;
                    }
                    else if (H3.peek() > H2.peek() && (H3.peek() - H2.peek()) <= 2 && count != 0)
                    {
                        cout << "Moves " << H3.peek() << " from H3 to H2 track." << endl;
                        H2.enqueue(H3.dequeue());
                        z = -1;
                        count--;
                    }
                    else
                    {
                        cout << "This combination of railcars cannot be arranged." << endl;
                        exit(0);
                    }
                }
            }
        }
    }
    // displaying the arranged railcars
    for (int c = 0; c < 9; c++)
    {
        info = outputT.dequeue();
        cout << info << " ";
    }
    return 0;
}