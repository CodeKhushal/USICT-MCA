#ifndef STACK_QUEUE_FOR_GRAPH_TRAVERSAL_H
#define STACK_QUEUE_FOR_GRAPH_TRAVERSAL_H

#include <iostream>
using namespace std;

int queue[20], front = -1, rear = -1; // for BFS
int stack[20], top = -1;              // for DFS

void enqueue(int value)
{
    if (rear == 20 - 1)
    {
        cout << "queue overflow" << endl;
    }
    else
    {
        if (front == -1)
            front = 0;
        queue[++rear] = value;
    }
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "queue underflow" << endl;
        return -1;
    }
    else
    {
        return queue[front++];
    }
}

bool isqueueEmpty()
{
    return front == -1 || front > rear;
}

void push(int value)
{
    if (top >= 20 - 1)
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        stack[++top] = value;
    }
}

int pop()
{
    if (top == -1)
    {
        cout << "stack underflow" << endl;
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

bool isstackEmpty()
{
    return top == -1;
}

#endif
