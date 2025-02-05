#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insertNode(root->left, data);

    else if (data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}

bool searchNode(Node *root, int key)
{
    if (root == NULL)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return searchNode(root->left, key);
    else
        return searchNode(root->right, key);
}

Node *findMinNode(Node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int key, bool &isDeleted)
{
    if (root == NULL)
    {
        isDeleted = false;
        return root;
    }

    if (key < root->data)
        root->left = deleteNode(root->left, key, isDeleted);

    else if (key > root->data)
        root->right = deleteNode(root->right, key, isDeleted);

    else
    {
        isDeleted = true;
        // Node with only one child or no child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node *temp = findMinNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data, isDeleted);
    }
    return root;
}

// (Left, Root, Right)
void inorderTraversal(Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// (Root, Left, Right)
void preorderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// (Left, Right, Root)
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
    bool isDeleted = false;

    do
    {
        cout << "\n--- Binary Search Tree Menu ---\n";
        cout << "0. Exit\n";
        cout << "1. Insert Node(Integer Values only)\n";
        cout << "2. Delete Node\n";
        cout << "3. Search Node\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "\nExiting program.\n\n";
            break;

        case 1:
            cout << "\nEnter the value to insert: ";
            cin >> value;
            root = insertNode(root, value);
            cout << "\n\t[Node inserted!]\n";
            break;

        case 2:
            cout << "\nEnter the value to delete: ";
            cin >> value;
            root = deleteNode(root, value, isDeleted);
            if (isDeleted)
                cout << "\n\t[Node deleted!]\n";
            else
                cout << "\n\t[Value not found!]\n";
            break;

        case 3:
            cout << "\nEnter the value to search: ";
            cin >> value;
            if (searchNode(root, value))
            {
                cout << "\n\t[" << value << " is found in the tree!]\n";
            }
            else
            {
                cout << "\n\t[" << value << " is not found in the tree!]\n";
            }
            break;

        case 4:
            cout << "\n\tInorder Traversal: ";
            inorderTraversal(root);
            cout << endl;
            break;

        case 5:
            cout << "\n\tPreorder Traversal: ";
            preorderTraversal(root);
            cout << endl;
            break;

        case 6:
            cout << "\n\tPostorder Traversal: ";
            postorderTraversal(root);
            cout << endl;
            break;

        default:
            cout << "\n\t[Invalid choice! Please try again]\n";
        }
    } while (choice != 0);

    return 0;
}