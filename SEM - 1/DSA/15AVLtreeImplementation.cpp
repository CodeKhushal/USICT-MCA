#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    int height;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->height = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int getHeight(Node *node)
{
    return (node == NULL) ? 0 : node->height;
}

int getBalanceFactor(Node *node)
{
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

bool isTreeEmpty(Node *root)
{
    return (root == NULL);
}

Node *rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node *findMinNode(Node *node)
{
    while (node->left != NULL)
        node = node->left;
    return node;
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && data < node->left->data)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && data > node->right->data)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && data > node->left->data)
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->right->data)
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node with only one child or no child
        if (root->left == NULL || root->right == NULL)
        {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            delete temp;
        }
        else
        {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node *temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    // Left Left Case
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rotateRight(root);

    // Left Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return rotateLeft(root);

    // Right Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

void preorderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";
    }
}

int main()
{
    Node *root = NULL;
    int choice, value;

    while (true)
    {
        cout << "\nMenu\n";
        cout << "0. Exit\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            if (isTreeEmpty(root))
            {
                cout << "\n\t[Tree is empty. Cannot delete a node from an empty tree!]\n";
                break;
            }
            cout << "Enter the value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;
        case 3:
            if (isTreeEmpty(root))
            {
                cout << "\n\t[Tree is empty!]\n";
                break;
            }
            cout << "Inorder Traversal: ";
            inorderTraversal(root);
            cout << endl;
            break;
        case 4:
            if (isTreeEmpty(root))
            {
                cout << "\n\t[Tree is empty!]\n";
                break;
            }
            cout << "Preorder Traversal: ";
            preorderTraversal(root);
            cout << endl;
            break;
        case 5:
            if (isTreeEmpty(root))
            {
                cout << "\n\t[Tree is empty!]\n";
                break;
            }
            cout << "Postorder Traversal: ";
            postorderTraversal(root);
            cout << endl;
            break;
        default:
            cout << "Invalid choice, try again.\n";
        }
    }

    return 0;
}
