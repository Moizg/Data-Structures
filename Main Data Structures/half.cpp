#include <iostream>
using namespace std;

struct Node
{
    Node *left, *right;
    int info;
};

class Tree
{
    Node *temp, *curr;
    int totalcount, count;

public:
    Tree()
    {
        temp = NULL;
        curr = NULL;
        totalcount = count = 0;
    }
    Node *newNode(int data)
    {
        temp = new Node;
        temp->left = NULL;
        temp->right = NULL;
        temp->info = data;
        return temp;
    }
    void totalNode(Node *temp)
    {
        if (temp == NULL)
        {
            cout << " Tree is empty." << endl;
            return;
        }
        totalcount++;
        if (temp->left != NULL)
        {
            totalNode(temp->left);
        }
        if (temp->right != NULL)
        {
            totalNode(temp->right);
        }
        return;
    }
    void displayMidNode(Node *temp)
    {
        if (temp == NULL)
        {
            cout << " Tree is empty." << endl;
            return;
        }
        count++;
        if (count == (totalcount / 2) + 1)
        {
            cout << "The middle value is: " << temp->info;
        }
        if (temp->left != NULL)
        {
            displayMidNode(temp->left);
        }
        if (temp->right != NULL)
        {
            displayMidNode(temp->right);
        }
        return;
    }
    Node *insertNode(Node *temp, int data)
    {
        // root condition
        if (temp == NULL)
        {
            temp = newNode(data);
        }
        else
        {
            if (data == temp->info)
            {
                cout << "Value already in tree!" << endl;
                return temp;
            }
            else if (data < temp->info)
            {
                temp->left = insertNode(temp->left, data);
            }
            else
            {
                temp->right = insertNode(temp->right, data);
            }
        }
        return temp;
    }
};

int main()
{
    Tree tree;
    Node *root = NULL;
    root = tree.insertNode(root, 60);
    root = tree.insertNode(root, 50);
    root = tree.insertNode(root, 40);
    root = tree.insertNode(root, 30);
    root = tree.insertNode(root, 20);
    root = tree.insertNode(root, 10);
    root = tree.insertNode(root, 5);
    tree.totalNode(root);
    tree.displayMidNode(root);
    return 0;
}