#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

class binaryTree
{
    Node *temp;

public:
    binaryTree()
    {
        temp = NULL;
    }
    Node *createNode(int key)
    {
        temp = new Node;
        temp->data = key;
        temp->left = temp->right = NULL;
        return temp;
    }
    Node *Insert(Node *temp, int value, bool isLeft)
    {
        if (temp == NULL)
        {
            temp = createNode(value);
        }
        else
        {
            if (isLeft)
            {
                temp->right = Insert(temp->right, value, !isLeft);
            }
            else
            {
                temp->left = Insert(temp->left, value, !isLeft);
            }
        }
        return temp;
    }
    void printTree(Node *temp)
    {
        if (temp == NULL)
        {
            cout << " Tree is empty." << endl;
            return;
        }
        cout << temp->data << " ";
        if (temp->right != NULL)
        {
            cout << "\n|----";
            printTree(temp->right);
        }
        if (temp->left != NULL)
        {
            printTree(temp->left);
        }
        return;
    }
};

int main()
{
    Node *root = NULL;
    binaryTree tree;

    root = tree.Insert(root, 14, false);
    root = tree.Insert(root, 12, true);
    root = tree.Insert(root, 3, false);
    root = tree.Insert(root, 9, true);

    cout << "Zig-Zag Binary Tree:" << endl;
    tree.printTree(root);

    return 0;
}
