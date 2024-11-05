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
    return q->front == NULL;
}

void displayQueue(Queue *q)
{
    if (q->front == NULL)
    {
        cout << "\n\t[Queue is empty!]" << endl;
        return;
    }
    cout << "\n\tQueue elements: ";
    QueueNode *temp = q->front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void initQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

void enqueue(Queue *q, int value)
{
    QueueNode *newNode = new QueueNode();
    newNode->data = value;
    newNode->next = NULL;
    if (q->rear == NULL)
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
    if (q->front == NULL)
    {
        cout << "\n\t[Queue underflow. Nothing to dequeue!]" << endl;
        return;
    }
    QueueNode *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
    {
        q->rear = NULL;
    }
    cout << "\n\tDequeued " << temp->data << " from the queue!" << endl;
    delete temp;
}

#endif
