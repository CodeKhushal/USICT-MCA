#include <iostream>
#include "11cirQUsingArray.h"
#include "11cirQUsingLinkedList.h"

using namespace std;

int main()
{
    int mainChoice, queueChoice, value, size;

    CircularQueueArray arrayQueue;
    CircularQueueLinkedList linkedListQueue;

    cout << "\nChoose the type of circular queue:\n";
    cout << "1. Array-based Circular Queue\n";
    cout << "2. Linked List-based Circular Queue\n";
    cout << "\nEnter your choice: ";
    cin >> mainChoice;

    if (mainChoice == 1)
    {
        cout << "\nEnter the size for the array-based queue: ";
        cin >> size;
        initArrayQueue(arrayQueue, size);
    }
    else if (mainChoice == 2)
    {
        initLLQueue(linkedListQueue);
    }
    else
    {
        cout << "\n\t[Invalid choice. Exiting...]\n";
        return 0;
    }

    do
    {
        cout << "\nQueue Operations Menu:\n";
        cout << "0. Exit\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "\nEnter your choice: ";
        cin >> queueChoice;

        switch (queueChoice)
        {
        case 0:
            cout << "Exiting...\n\n";
            break;
        case 1:
            if(isFull(arrayQueue)){
                cout << "\n\t[Queue is full!]\n";
                break;
            }
            cout << "\nEnter the value to enqueue: ";
            cin >> value;
            if (mainChoice == 1)
            {
                enqueue(arrayQueue, value);
                displayQueue(arrayQueue);
            }
            else
            {
                enqueue(linkedListQueue, value);
                displayQueue(linkedListQueue);
            }
            break;
        case 2:
            if (mainChoice == 1)
            {
                dequeue(arrayQueue);
                if (!isEmpty(arrayQueue))
                    displayQueue(arrayQueue);
            }
            else
            {
                dequeue(linkedListQueue);
                if (!isEmpty(linkedListQueue))
                    displayQueue(linkedListQueue);
            }
            break;
        case 3:
            if (mainChoice == 1)
            {
                displayQueue(arrayQueue);
            }
            else
            {
                displayQueue(linkedListQueue);
            }
            break;
        default:
            cout << "\n\t[Invalid choice, please try again!]\n";
        }
    } while (queueChoice != 0);

    return 0;
}
