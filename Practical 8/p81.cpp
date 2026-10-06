#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
private:
    Node *root;

    void inorder(Node *node)
    {
        if (node == nullptr)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void preorder(Node *node)
    {
        if (node == nullptr)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void postorder(Node *node)
    {
        if (node == nullptr)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void createTree()
    {
        int value;
        cout << "Enter root value (-1 for empty): ";
        cin >> value;

        if (value == -1)
            return;

        root = new Node(value);
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            cout << "Enter left child of " << current->data << " (-1 for none): ";
            cin >> value;

            if (value != -1)
            {
                current->left = new Node(value);
                q.push(current->left);
            }

            cout << "Enter right child of " << current->data << " (-1 for none): ";
            cin >> value;

            if (value != -1)
            {
                current->right = new Node(value);
                q.push(current->right);
            }
        }
    }

    void displayTraversals()
    {
        cout << "\nInorder: ";
        inorder(root);

        cout << "\nPreorder: ";
        preorder(root);

        cout << "\nPostorder: ";
        postorder(root);

        cout << "\nLevel Order: ";
        levelOrder();

        cout << endl;
    }

    void levelOrder()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty";
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);

            if (current->right != nullptr)
                q.push(current->right);
        }
    }
};

int main()
{
    BinaryTree tree;

    tree.createTree();
    tree.displayTraversals();

    return 0;
}
