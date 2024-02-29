#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int info;
    Node *left;
    Node *right;
};

class CompleteBinaryTree
{
    Node *root;

public:
    CompleteBinaryTree()
    {
        root = nullptr;
    }

    void insert(int data)
    {
        root = insertRecursive(root, data);
    }

    Node *insertRecursive(Node *node, int data)
    {
        if (node == nullptr)
        {
            return createNode(data);
        }
        else
        {
            if (isComplete(node))
            {
                if (data < node->info)
                {
                    node->left = insertRecursive(node->left, data);
                }
                else
                {
                    node->right = insertRecursive(node->right, data);
                }
            }
            else
            {
                // Find the first available null child node for insertion.
                if (node->left == nullptr)
                {
                    node->left = insertRecursive(node->left, data);
                }
                else
                {
                    node->right = insertRecursive(node->right, data);
                }
            }
            minHeapify(node);
            return node;
        }
    }

    /* The isComplete function is used to determine if a binary tree (in this case, a complete binary tree) is complete.
    A complete binary tree is a binary tree in which all levels are completely filled except possibly for the last level,
    which is filled from left to right.

    In the code I provided earlier, the isComplete function is used to check whether the binary tree still satisfies the
    complete binary tree property after inserting a new node. If the binary tree is complete, new nodes are inserted according to
    the min-heap property. If the tree is not complete (i.e., there is a level with missing nodes on the right), new nodes
    are inserted from left to right on the last level to maintain the complete binary tree property.
    */
    bool isComplete(Node *node)
    {
        if (node == nullptr)
            return true;

        if ((node->left && !isComplete(node->left)) || (node->right && !isComplete(node->right)))
            return false;

        return (node->left == nullptr && node->right == nullptr) || (node->left && node->right);
    }

    Node *createNode(int data)
    {
        Node *newNode = new Node;
        newNode->info = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    void minHeapify(Node *node)
    {
        Node *smallest = node;
        Node *left = node->left;
        Node *right = node->right;

        if (left != nullptr && left->info < smallest->info)
        {
            smallest = left;
        }

        if (right != nullptr && right->info < smallest->info)
        {
            smallest = right;
        }

        if (smallest != node)
        {
            swap(node->info, smallest->info);
            minHeapify(smallest);
        }
    }

    void deleteMin()
    {
        if (root == nullptr)
        {
            cout << "The tree is empty. Nothing to delete." << endl;
            return;
        }

        Node *lastNode = findLastNode(root);
        root->info = lastNode->info;

        deleteLastNode(root);

        // Restore the min-heap property after deletion.
        minHeapify(root);
    }

    Node *findLastNode(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        Node *lastNode = nullptr;

        while (!q.empty())
        {
            lastNode = q.front();
            q.pop();

            if (lastNode->left)
                q.push(lastNode->left);

            if (lastNode->right)
                q.push(lastNode->right);
        }

        return lastNode;
    }

    void deleteLastNode(Node *root)
    {
        if (root == nullptr)
            return;

        queue<Node *> q;
        q.push(root);

        Node *lastNode = nullptr;
        Node *parentOfLastNode = nullptr;

        while (!q.empty())
        {
            lastNode = q.front();
            q.pop();

            if (lastNode->left)
            {
                parentOfLastNode = lastNode;
                q.push(lastNode->left);
            }

            if (lastNode->right)
            {
                parentOfLastNode = lastNode;
                q.push(lastNode->right);
            }
        }

        if (parentOfLastNode)
        {
            if (parentOfLastNode->left == lastNode)
                parentOfLastNode->left = nullptr;
            else
                parentOfLastNode->right = nullptr;

            delete lastNode;
        }
        else
        {
            // If the last node is the root itself.
            delete root;
            root = nullptr;
        }
    }

    void printLevelOrder()
    {
        if (root == nullptr)
        {
            cout << "The tree is empty." << endl;
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            cout << current->info << " ";

            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
    }

    void peek()
    {
        if (root != NULL)
        {
            cout << root->info << endl;
        }
    }
};

int main()
{
    CompleteBinaryTree tree;

    tree.insert(10);
    tree.insert(15);
    tree.insert(20);
    tree.insert(25);
    tree.insert(30);
    tree.insert(35);

    cout << "Complete Binary Tree-based Min-Heap: ";
    tree.printLevelOrder();
    cout << "\n\nPeek: " << endl;
    tree.peek();

    tree.insert(5);

    cout << "Complete Binary Tree-based Min-Heap: ";
    tree.printLevelOrder();
    cout << "\n\nPeek: " << endl;
    tree.peek();

    tree.insert(1);

    cout << "Complete Binary Tree-based Min-Heap: ";
    tree.printLevelOrder();
    cout << "\n\nPeek: " << endl;
    tree.peek();

    tree.deleteMin();
    cout << "Complete Binary Tree-based Min-Heap: ";
    tree.printLevelOrder();
    cout << "\n\nPeek: " << endl;
    tree.peek();

    return 0;
}
