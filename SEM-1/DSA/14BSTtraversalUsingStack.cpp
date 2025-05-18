#include <iostream>
#include <cstdlib>
#define MAX 100

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

struct Stack
{
    int top;
    int *elements[MAX];
};

void initializeStack(Stack &s)
{
    s.top = -1;
}

bool isEmpty(Stack &s)
{
    return s.top == -1;
}

void push(Stack &s, int element)
{
    if (s.top == MAX - 1)
    {
        cout << "\n\t[Stack Overflow!]\n";
        return;
    }
    s.elements[++s.top] = (int *)malloc(sizeof(int));
    *s.elements[s.top] = element;
}

int pop(Stack &s)
{
    if (isEmpty(s))
    {
        cout << "\n\t[Stack Underflow!]\n";
        return -1;
    }
    int element = *s.elements[s.top];
    free(s.elements[s.top--]);
    return element;
}

int peek(Stack &s)
{
    if (isEmpty(s))
    {
        return -1;
    }
    return *s.elements[s.top];
}

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool isTreeEmpty(Node *root)
{
    return (root == NULL);
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// (Left, Root, Right)
void inorderTraversal(Node *root)
{
    Stack s;
    initializeStack(s);
    Node *current = root;

    while (current != NULL || !isEmpty(s))
    {
        while (current != NULL)
        {
            push(s, current->data);
            current = current->left;
        }

        int data = pop(s);
        cout << data << " ";

        current = root; // Reset root pointer to traverse right subtree
        while (current != NULL && current->data != data)
        {
            if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }
        current = current->right;
    }
}

// (Root, Left, Right)
void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    Stack s;
    initializeStack(s);
    push(s, root->data);

    while (!isEmpty(s))
    {
        int data = pop(s);
        cout << data << " ";

        Node *current = root;
        while (current != NULL && current->data != data)
        {
            if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (current->right)
            push(s, current->right->data);
        if (current->left)
            push(s, current->left->data);
    }
}

// (Left, Right, Root)
void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;

    Stack s1, s2;
    initializeStack(s1);
    initializeStack(s2);

    push(s1, root->data);

    while (!isEmpty(s1))
    {
        int data = pop(s1);
        push(s2, data);

        Node *current = root;
        while (current != NULL && current->data != data)
        {
            if (data < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (current->left)
            push(s1, current->left->data);
        if (current->right)
            push(s1, current->right->data);
    }

    while (!isEmpty(s2))
    {
        cout << pop(s2) << " ";
    }
}

int main()
{
    Node *root = NULL;
    int choice = -1, value;

    while (choice != 0)
    {
        cout << "\n--- Binary Search Tree Using Stack Menu ---\n";
        cout << "0. Exit\n";
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            if (isTreeEmpty(root))
            {
                cout << "\n\t[Tree is empty!]\n";
                break;
            }
            cout << "\n\tInorder Traversal: ";
            inorderTraversal(root);
            cout << endl;
            break;
        case 3:
            if (isTreeEmpty(root))
            {
                cout << "\n\t[Tree is empty!]\n";
                break;
            }
            cout << "\n\tPreorder Traversal: ";
            preorderTraversal(root);
            cout << endl;
            break;
        case 4:
            if (isTreeEmpty(root))
            {
                cout << "\n\t[Tree is empty!]\n";
                break;
            }
            cout << "\n\tPostorder Traversal: ";
            postorderTraversal(root);
            cout << endl;
            break;
        default:
            cout << "\n\t[Invalid choice, try again!]\n";
        }
    }

    return 0;
}
