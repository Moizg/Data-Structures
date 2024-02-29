#include <iostream>
using namespace std;

class Track
{
    int top;
    int size;
    int *arr;

public:
    Track(int size)
    {
        top = -1;
        this->size = size;
        arr = new int[size];
    }
    ~Track()
    {
        delete[] arr;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (top == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int val)
    {
        if (!isFull())
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {
        int val;
        if (!isEmpty())
        {
            val = arr[top];
            top--;
        }
        return val;
    }
    int peek()
    {
        if (!isEmpty())
        {
            return arr[top];
        }
        return -1;
    }
};
int main()
{
    Track inputT(9);
    Track H1(4), H2(4), H3(4), outputT(9);
    int info;

    cout << "Enter input track values: ";
    for (int i = 0; i < 9; i++)
    {
        cin >> info;
        inputT.push(info);
    }

    int min = 1;
    for (int i = 0; i < 9; i++) // outer loop runs 9 time for 9 data values
    {
        info = inputT.pop();
        if (info == min)
        {
            outputT.push(info);
            cout << "Moves " << info << " to output track." << endl;
            min++;
        }
        for (int j = 0; j < 1; j++)
        {
            if (H1.peek() == min)
            {
                cout << "Moves " << H1.peek() << " to output track." << endl;
                outputT.push(H1.pop());
                min++;
                j = -1;
            }
            else if (H2.peek() == min)
            {
                cout << "Moves " << H2.peek() << " to output track." << endl;
                outputT.push(H2.pop());
                min++;
                j = -1;
            }
            else if (H3.peek() == min)
            {
                cout << "Moves " << H3.peek() << " to output track." << endl;
                outputT.push(H3.pop());
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
                if (H1.isEmpty() || (!H1.isEmpty() && H1.peek() > info))
                {
                    cout << "Moves " << info << " to H1 track." << endl;
                    H1.push(info);
                    push = true;
                }
                else if (H2.isEmpty() || (!H2.isEmpty() && H2.peek() > info))
                {
                    cout << "Moves " << info << " to H2 track." << endl;
                    H2.push(info);
                    push = true;
                }
                else if (H3.isEmpty() || (!H3.isEmpty() && H3.peek() > info))
                {
                    cout << "Moves " << info << " to H3 track." << endl;
                    H3.push(info);
                    push = true;
                }
                else if (push == false) // inter-track shuffling only allowed twice
                {
                    cout << "Trying inter track suffling" << endl;
                    if (H1.peek() < H2.peek() && (H2.peek() - H1.peek()) <= 2 && count != 0)
                    {
                        cout << "Moves " << H1.peek() << " from H1 to H2 track." << endl;
                        H2.push(H1.pop());
                        z = -1;
                        count--;
                    }
                    else if (H1.peek() < H3.peek() && (H3.peek() - H1.peek()) <= 2 && count != 0)
                    {
                        cout << "Moves " << H1.peek() << " from H1 to H3 track." << endl;
                        H3.push(H1.pop());
                        z = -1;
                        count--;
                    }
                    else if (H2.peek() < H1.peek() && (H1.peek() - H2.peek()) <= 2 && count != 0)
                    {
                        cout << "Moves " << H2.peek() << " from H2 to H1 track." << endl;
                        H1.push(H2.pop());
                        z = -1;
                        count--;
                    }
                    else if (H2.peek() < H3.peek() && (H3.peek() - H2.peek()) <= 2 && count != 0)
                    {
                        cout << "Moves " << H2.peek() << " from H2 to H1 track." << endl;
                        H3.push(H2.pop());
                        z = -1;
                        count--;
                    }
                    else if (H3.peek() < H1.peek() && (H1.peek() - H3.peek()) <= 2 && count != 0)
                    {
                        cout << "Moves " << H3.peek() << " from H3 to H1 track." << endl;
                        H1.push(H3.pop());
                        z = -1;
                        count--;
                    }
                    else if (H3.peek() < H2.peek() && (H2.peek() - H3.peek()) <= 2 && count != 0)
                    {
                        cout << "Moves " << H3.peek() << " from H3 to H2 track." << endl;
                        H2.push(H3.pop());
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
        info = outputT.pop();
        cout << info << " ";
    }

    return 0;
}