#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
};

struct Queue
{
    QueueNode *front;
    QueueNode *rear;
};

bool isEmptyQueue(Queue *q)
{
    return q->front == nullptr;
}

void displayQueue(Queue *q)
{
    if (q->front == nullptr)
    {
        cout << "\n\t[Queue is empty!]" << endl;
        return;
    }
    cout << "\n\tQueue elements: ";
    QueueNode *temp = q->front;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void initQueue(Queue *q)
{
    q->front = q->rear = nullptr;
}

void enqueue(Queue *q, int value)
{
    QueueNode *newNode = new QueueNode();
    newNode->data = value;
    newNode->next = nullptr;
    if (q->rear == nullptr)
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    cout << "\n\tEnqueued " << value << " to the queue!" << endl;
}

void dequeue(Queue *q)
{
    if (q->front == nullptr)
    {
        cout << "\n\t[Queue underflow. Nothing to dequeue!]" << endl;
        return;
    }
    QueueNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == nullptr)
    {
        q->rear = nullptr;
    }
    cout << "\n\tDequeued " << temp->data << " from the queue!" << endl;
    delete temp;
}

#endif
