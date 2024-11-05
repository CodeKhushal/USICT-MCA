// CircularQueueLinkedList.h
#ifndef CIRCULARQUEUELINKEDLIST_H
#define CIRCULARQUEUELINKEDLIST_H

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct CircularQueueLinkedList
{
    Node *front;
    Node *rear;
};

void initLLQueue(CircularQueueLinkedList &q)
{
    q.front = q.rear = NULL;
}

bool isEmpty(CircularQueueLinkedList &q)
{
    return q.front == NULL;
}

void displayQueue(CircularQueueLinkedList &q)
{
    if (isEmpty(q))
    {
        cout << "\n\t[Queue is empty]\n";
        return;
    }
    Node *temp = q.front;
    cout << "\n\tQueue elements: ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != q.front);
    cout << endl;
}

void enqueue(CircularQueueLinkedList &q, int value)
{
    Node *temp = new Node();
    temp->data = value;
    if (isEmpty(q))
    {
        q.front = q.rear = temp;
        q.rear->next = q.front;
    }
    else
    {
        q.rear->next = temp;
        q.rear = temp;
        q.rear->next = q.front;
    }
    cout << "\n\t[Enqueued: " << value << "]" << endl;
}

void dequeue(CircularQueueLinkedList &q)
{
    if (isEmpty(q))
    {
        cout << "\n\t[Queue is empty!]\n";
        return;
    }
    Node *temp = q.front;
    if (q.front == q.rear)
    {
        q.front = q.rear = NULL;
    }
    else
    {
        q.front = q.front->next;
        q.rear->next = q.front;
    }
    cout << "\n\t[Dequeued: " << temp->data << "]" << endl;
    delete temp;
}

#endif
