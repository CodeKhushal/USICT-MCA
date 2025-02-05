// CircularQueueArray.h
#ifndef CIRCULARQUEUEARRAY_H
#define CIRCULARQUEUEARRAY_H

#include <iostream>
using namespace std;

struct CircularQueueArray
{
    int front, rear, size;
    int *queue;
};

void initArrayQueue(CircularQueueArray &q, int s)
{
    q.size = s;
    q.front = q.rear = -1;
    q.queue = new int[s];
}

bool isFull(CircularQueueArray &q)
{
    return (q.rear + 1) % q.size == q.front;
}

bool isEmpty(CircularQueueArray &q)
{
    return q.front == -1;
}

void displayQueue(CircularQueueArray &q)
{
    if (isEmpty(q))
    {
        cout << "\n\t[Queue is empty!]\n";
        return;
    }
    cout << "\n\tQueue elements: ";
    
    for (int i = q.front; i != q.rear; i = (i + 1) % q.size)
    {
        cout << q.queue[i] << " ";
    }
    cout << q.queue[q.rear] << endl;
}

void enqueue(CircularQueueArray &q, int value)
{
    if (isFull(q))
    {
        cout << "\n\t[Queue is full!]\n";
        return;
    }
    if (q.front == -1)
        q.front = 0;
    q.rear = (q.rear + 1) % q.size;
    q.queue[q.rear] = value;
    cout << "\n\t[Enqueued: " << value << "]" << endl;
}

void dequeue(CircularQueueArray &q)
{
    if (isEmpty(q))
    {
        cout << "\n\t[Queue is empty!]\n";
        return;
    }
    cout << "\n\tDequeued: " << q.queue[q.front] << "]" << endl;
    if (q.front == q.rear)
    {
        q.front = q.rear = -1; // Reset when queue becomes empty
    }
    else
    {
        q.front = (q.front + 1) % q.size;
    }
}

#endif
