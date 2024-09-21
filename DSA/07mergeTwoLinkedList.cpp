#include <iostream>
#include <malloc.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
} *head = NULL;

NODE *createNode(int d)
{
    struct NODE *temp;
    temp = (struct NODE *)malloc(sizeof(struct NODE));
    temp->data = d;
    return temp;
}

bool isListEmpty(struct NODE *head)
{
    return head == NULL;
}

void displayList(struct NODE *head, string n)
{
    if (isListEmpty(head))
    {
        cout << "\n\t[Nothing to print!]\n\n";
        return;
    }
    else
    {
        cout << "\n\tList " << n << ": ";
        struct NODE *p = head;
        while (p != NULL)
        {
            cout << p->data;
            p = p->next;
            if (p != NULL)
                cout << " -> ";
        }
    }
    cout << endl
         << endl;
}

void insertAtEnd(struct NODE *&head, struct NODE *temp)
{
    if (isListEmpty(head))
    {
        head = temp;
        return;
    }

    NODE *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    temp->next = NULL;
}

void createList(NODE *&head)
{
    bool flag = true;
    int data, option, dataBackup;

    if (isListEmpty(head))
    {
        cout << "Data: ";
        cin >> data;
        head = createNode(data);
        head->next = NULL;
        cout << "Want to add more? [Yes = 1 / No = 0]: ";
        cin >> option;
        if (option == 0)
        {
            flag = false;
        }
        dataBackup = data;
    }

    while (flag)
    {
        do
        {
            cout << "Data: ";
            cin >> data;
            if (data < dataBackup)
            {
                cout << "Data should be greater than the previous data. Please enter again!\n";
            }
        } while (data < dataBackup);

        NODE *temp = createNode(data);
        insertAtEnd(head, temp);
        cout << "Want to add more? [Yes = 1 / No = 0]: ";
        cin >> option;
        if (option == 0)
        {
            flag = false;
        }
        dataBackup = data;
    }
}

void freeList(NODE *&head) // Function to free the allocated memory
{
    NODE *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

NODE *mergeSortedLists(NODE *head1, NODE *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    NODE *mergedHead = NULL;
    if (head1->data <= head2->data)
    {
        mergedHead = head1;
        head1 = head1->next;
    }
    else
    {
        mergedHead = head2;
        head2 = head2->next;
    }

    NODE *current = mergedHead;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            current->next = head1;
            head1 = head1->next;
        }
        else
        {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    // Append the remaining nodes
    if (head1 != NULL)
    {
        current->next = head1;
    }
    else
    {
        current->next = head2;
    }

    return mergedHead;
}

int main()
{
    struct NODE *head1 = NULL;
    struct NODE *head2 = NULL;

    cout << "Enter data for the first linked list: \n\n";
    createList(head1);

    cout << "\n\nEnter data for the second linked list: \n\n";
    createList(head2);

    displayList(head1, "1");
    displayList(head2, "2");

    NODE *mergedHead = mergeSortedLists(head1, head2);
    displayList(mergedHead, "after Merging");

    freeList(head1);
    freeList(head2);
    freeList(mergedHead);

    return 0;
}
