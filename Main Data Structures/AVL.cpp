#include <iostream>
using namespace std;

struct Node
{
    Node *left, *right;
    int info, height;
};

class Tree
{
    Node *temp, *curr;

public:
    Tree()
    {
        temp = NULL;
        curr = NULL;
    }
    bool isEmpty()
    {
        if (temp == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    Node *newNode(int data)
    {
        temp = new Node;
        temp->left = NULL;
        temp->right = NULL;
        temp->info = data;
        temp->height = 1;
        return temp;
    }
    int height(Node *temp)
    {
        if (temp == NULL)
        {
            return 0;
        }
        return temp->height;
    }
    int max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    // Traversals
    void inOrder(Node *temp)
    {
        if (temp == NULL)
        {
            cout << " Tree is empty." << endl;
            return;
        }
        if (temp->left != NULL)
        {
            inOrder(temp->left);
        }
        cout << temp->info << " ";
        if (temp->right != NULL)
        {
            inOrder(temp->right);
        }
        return;
    }
    void postOrder(Node *temp)
    {
        if (temp == NULL)
        {
            cout << " Tree is empty." << endl;
            return;
        }
        if (temp->left != NULL)
        {
            postOrder(temp->left);
        }
        if (temp->right != NULL)
        {
            postOrder(temp->right);
        }
        cout << temp->info << " ";
        return;
    }
    void preOrder(Node *temp)
    {
        if (temp == NULL)
        {
            cout << " Tree is empty." << endl;
            return;
        }
        cout << temp->info << " ";
        if (temp->left != NULL)
        {
            preOrder(temp->left);
        }
        if (temp->right != NULL)
        {
            preOrder(temp->right);
        }
        return;
    }
    // Searching
    void search(Node *temp, int data)
    {
        if (!isEmpty())
        {
            // compare first node
            if (data == temp->info)
            {
                cout << "Value found!" << endl;
                return;
            }
            else if (data < temp->info)
            {
                return search(temp->left, data);
            }
            else if (data > temp->info)
            {
                return search(temp->right, data);
            }
        }
        else
        {
            cout << "Tree is empty." << endl;
        }
    }
    // Insertion
    Node *insertNode(Node *temp, int data)
    {
        if (temp == NULL)
        {
            temp = newNode(data);
            return temp;
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
        // code for checking balance factor and setting height
        temp->height = 1 + max(height(temp->left), height(temp->right));
        int balancefactor = getBalanceFactor(temp);
        if (balancefactor > 1)
        {
            if (data < temp->left->info)
            {
                return rotateright(temp);
            }
            else if (data > temp->left->info)
            {
                temp->left = rotateleft(temp->left);
                return rotateright(temp);
            }
        }
        if (balancefactor < -1)
        {
            if (data > temp->right->info)
            {
                return rotateleft(temp);
            }
            else if (data < temp->right->info)
            {
                temp->right = rotateright(temp->right);
                return rotateleft(temp);
            }
        }
        return temp;
    }
    // rotating right and left code
    Node *rotateleft(Node *temp)
    {
        Node *parent, *child;
        parent = temp->right;
        child = parent->left;
        parent->left = temp;
        temp->right = child;
        temp->height = 1 + max(height(temp->left), height(temp->right));
        parent->height = 1 + max(height(parent->left), height(parent->right));
        return parent;
    }
    Node *rotateright(Node *temp)
    {
        Node *parent, *child;
        parent = temp->left;
        child = parent->right;
        parent->right = temp;
        temp->left = child;
        temp->height = 1 + max(height(temp->left), height(temp->right));
        parent->height = 1 + max(height(parent->left), height(parent->right));
        return parent;
    }
    // getting balance factor
    int getBalanceFactor(Node *temp)
    {
        return (height(temp->left) - height(temp->right));
    }
    // deletion
    Node *removeNode(Node *temp, int data)
    {
        if (temp == nullptr)
        {
            cout << "Tree is empty." << endl;
            return temp;
        }

        if (data < temp->info)
        {
            temp->left = removeNode(temp->left, data);
        }
        else if (data > temp->info)
        {
            temp->right = removeNode(temp->right, data);
        }
        else
        {
            if (temp->left == nullptr || temp->right == nullptr)
            {
                Node *tempChild = temp->left ? temp->left : temp->right;
                if (tempChild == nullptr)
                {
                    tempChild = temp;
                    temp = nullptr;
                }
                else
                {
                    *temp = *tempChild;
                }
                delete tempChild;
            }
            else
            {
                Node *successor = findMin(temp->right);
                temp->info = successor->info;
                temp->right = removeNode(temp->right, successor->info);
            }
        }

        if (temp == nullptr)
        {
            return temp;
        }

        temp->height = 1 + max(height(temp->left), height(temp->right));
        int balanceFactor = getBalanceFactor(temp);

        // Rebalance the tree
        if (balanceFactor > 1 && getBalanceFactor(temp->left) >= 0)
        {
            return rotateright(temp);
        }
        if (balanceFactor > 1 && getBalanceFactor(temp->left) < 0)
        {
            temp->left = rotateleft(temp->left);
            return rotateright(temp);
        }
        if (balanceFactor < -1 && getBalanceFactor(temp->right) <= 0)
        {
            return rotateleft(temp);
        }
        if (balanceFactor < -1 && getBalanceFactor(temp->right) > 0)
        {
            temp->right = rotateright(temp->right);
            return rotateleft(temp);
        }

        return temp;
    }

    Node *findMin(Node *temp)
    {
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp;
    }

    void printTree(Node *temp, string indent, bool last)
    {
        if (temp != nullptr)
        {
            cout << indent;
            if (last)
            {
                cout << "R----";
                indent += "   ";
            }
            else
            {
                cout << "L----";
                indent += "|  ";
            }
            cout << temp->info << endl;
            printTree(temp->left, indent, false);
            printTree(temp->right, indent, true);
        }
    }
};

int main()
{
    Tree tree;
    Node *root = NULL;
    root = tree.insertNode(root, 33);
    root = tree.insertNode(root, 13);
    root = tree.insertNode(root, 53);
    root = tree.insertNode(root, 9);
    root = tree.insertNode(root, 21);
    root = tree.insertNode(root, 61);
    root = tree.insertNode(root, 8);
    root = tree.insertNode(root, 11);
    tree.printTree(root, "", true);
    cout << "Before deleting" << endl;
    root = tree.removeNode(root, 13);
    cout << "After deleting " << endl;
    tree.printTree(root, "", true);
    return 0;
}