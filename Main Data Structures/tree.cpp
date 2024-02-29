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

public:
    Tree()
    {
        temp = NULL;
        curr = NULL;
    }
    Node *newNode(int data)
    {
        temp = new Node;
        temp->left = NULL;
        temp->right = NULL;
        temp->info = data;
        return temp;
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
        if (temp != NULL)
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
    // finding successor
    Node *findSuccessor(Node *temp)
    {
        curr = temp;
        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }
    // deletion
    Node *removeNode(Node *temp, int data)
    {
        if (temp == NULL)
        {
            cout << "Tree empty." << endl;
            return temp;
        }
        if (data < temp->info)
        {
            temp->left = removeNode(temp->left, data);
            return temp;
        }
        else if (data > temp->info)
        {
            temp->right = removeNode(temp->right, data);
            return temp;
        }

        if (temp->left == NULL)
        {
            curr = temp->right;
            delete temp;
            return curr;
        }
        else if (temp->right == NULL)
        {
            curr = temp->left;
            delete temp;
            return curr;
        }
        else
        {
            Node *successor = findSuccessor(temp->right);
            temp->info = successor->info;
            temp->right = removeNode(temp->right, successor->info);
            /* Node *Parent = temp;
            // Find successor of the node
            Node *succ = temp->right;
            while (succ->left != NULL)
            {
                Parent = succ;
                succ = succ->left;
            }
            if (Parent != temp)
            {
                Parent->left = succ->right;
            }
            else
            {
                Parent->right = succ->right;
            }
            temp->info = succ->info;
            delete succ;
            return temp; */
        }
    }
};

int main()
{
    Tree tree;
    Node *root = NULL;
    root = tree.insertNode(root, 50);
    root = tree.insertNode(root, 30);
    root = tree.insertNode(root, 20);
    root = tree.insertNode(root, 40);
    root = tree.insertNode(root, 70);
    root = tree.insertNode(root, 60);
    tree.inOrder(root);
    cout << "\n";
    root = tree.removeNode(root, 30);
    tree.inOrder(root);
    return 0;
}