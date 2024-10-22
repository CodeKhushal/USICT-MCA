// Implement operations (push, pop) on a stack using arrays. Check the 
// status of the stack whether there is underflow or overflow. 

#include <iostream>
using namespace std;

struct Stack
{
    int *arr;
    int top;
    int max_size;
};

void initialize(Stack &s, int size)
{
    s.max_size = size;
    s.arr = (int *)malloc(sizeof(int));
    s.top = -1;
}

bool isFull(Stack &s)
{
    return s.top == s.max_size - 1;
}

bool isEmpty(Stack &s)
{
    return s.top == -1;
}

void display(Stack &s)
{
    if (isEmpty(s))
    {
        cout << "\n\t[Stack is empty!]\n"
             << endl;
    }
    else
    {
        cout << "\n\tStack: ";

        cout << s.arr[s.top];
    }
}

void push(Stack &s, int value)
{
    if (isFull(s))
    {
        cout << "\n\t[Stack Overflow! Cannot push " << value << "]" << endl;
    }
    else
    {
        s.arr[++s.top] = value;
        cout << "\n\t[" << value << " pushed onto the stack!]" << endl;
        display(s);
    }
}

void pop(Stack &s)
{
    if (isEmpty(s))
    {
        cout << "\n\t[Stack Underflow! Cannot pop]" << endl;
    }
    else
    {
        cout << "\n\t[" << s.arr[s.top--] << " popped from the stack!]" << endl; // Pop the top element and decrement top
        display(s);
    }
}

void stackMenu(Stack &s)
{
    int choice = -1, value;
    do
    {
        cout << "\nMenu:\n";
        cout << "0. Exit\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "\n\t[Exiting...]\n";
            break;
        case 1:
            cout << "Enter the value to push: ";
            cin >> value;
            push(s, value);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            display(s);
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);
}

int main()
{
    Stack s;
    int size;

    cout << "Enter the size of the stack: ";
    cin >> size;

    initialize(s, size);
    stackMenu(s);

    delete[] s.arr;

    return 0;
}
