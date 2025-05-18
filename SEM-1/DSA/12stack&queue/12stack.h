#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;
};

bool isEmpty(StackNode *tos)
{
    return tos == NULL;
}

int peekStack(StackNode **tos)
{
    return (*tos)->data;
}

void push(StackNode **tos, int value)
{
    StackNode *newNode = new StackNode();
    newNode->data = value;
    newNode->next = *tos;
    *tos = newNode;
    cout << "\n\tPushed " << value << " to the stack!" << endl;
}

void pop(StackNode **tos)
{
    if (*tos == NULL)
    {
        cout << "\n\t[Stack underflow. Nothing to pop!]" << endl;
        return;
    }
    StackNode *temp = *tos;
    *tos = (*tos)->next;
    cout << "\n\tPopped " << temp->data << " from the stack!" << endl;
    delete temp;
}

#endif
