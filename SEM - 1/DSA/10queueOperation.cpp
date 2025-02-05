// Implement operations (enqueue, dequeue) on a queue using arrays. Check 
// the status of the queue whether it is empty or full. 

#include <iostream>
using namespace std;

struct Queue {
    int front, rear, size;
    int* array;

    Queue(int s) {
        front = -1;
        rear = -1;
        size = s;
        array = new int[s];
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (rear == size - 1);
    }

    void enqueue() {
        if (isFull()) {
            cout << "\n\t[Overflow! Queue is full]\n";
            return;
        }

        int value;
        cout << "\nEnter the value to enqueue: ";
        cin >> value;

        if (front == -1) 
            front = 0;

        rear++;
        array[rear] = value;
        cout << "\n\tEnqueued: " << value << endl;
        display();
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "\n\t[Queue is empty]\n";
            return -1;
        }
        int item = array[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        cout << "\n\tDequeued: " << item << endl;
        display();
        return item;
    }

    void display() {
        if (isEmpty()) {
            cout << "\n\t[Queue is empty]\n";
            return;
        }
        cout << "\n\tQueue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice, value;

    cout << "\nEnter the size of the queue: ";
    cin >> size;

    Queue q(size);

    do {
        cout << "\nQueue Menu:\n";
        cout << "0. Exit\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Check if Queue is Full\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "\n\t[Exiting...]\n";
                break;

            case 1:
                q.enqueue();
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                if (q.isEmpty())
                    cout << "\n\t[Queue is empty]\n";
                else
                    cout << "\n\t[Queue is not empty]\n";
                break;

            case 5:
                if (q.isFull())
                    cout << "\n\t[Queue is full]\n";
                else
                    cout << "\n\t[Queue is not full]\n";
                break;

            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}
