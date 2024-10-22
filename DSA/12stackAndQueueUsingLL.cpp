#include <iostream>
#include "12stack.h"
#include "12queue.h"

using namespace std;

int main()
{
    StackNode *tos = NULL;
    Queue queue;
    initQueue(&queue);

    int choice, value;
    bool flag = true;

    while (flag)
    {
        cout << "\nMenu:\n";
        cout << "0. Exit\n";
        cout << "1. Push to Stack\n";
        cout << "2. Pop from Stack\n";
        cout << "3. Peek Stack\n\n";
        cout << "4. Enqueue to Queue\n";
        cout << "5. Dequeue from Queue\n";
        cout << "6. Display Queue\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            flag = false;
            cout << "\nExiting program...\n\n";
            break;
        case 1:
            cout << "\nEnter value to push: ";
            cin >> value;
            push(&tos, value);
            break;

        case 2:
            pop(&tos);
            break;

        case 3:
            if (tos == NULL)
            {
                cout << "\n\t[Stack is empty!]" << endl;
                break;
            }
            cout << "\n\tValue at TOS: " << peekStack(&tos);
            break;

        case 4:
            cout << "\nEnter value to enqueue: ";
            cin >> value;
            enqueue(&queue, value);
            break;

        case 5:
            dequeue(&queue);
            break;

        case 6:
            displayQueue(&queue);
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
