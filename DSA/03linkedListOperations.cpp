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

bool isListEmpty()
{
    return head == NULL;
}

void displayList()
{
    if (isListEmpty())
    {
        cout << "Nothing to print!\n";
        return;
    }
    else
    {
        cout << "\nList: ";
        NODE *p = head;
        while (p != NULL)
        {
            cout << p->data;
            p = p->next;
            if (p != NULL)
                cout << " -> ";
        }
        p = head;
    }
    cout << endl
         << endl;
}

int countList()
{
    int count = 0;
    NODE *p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void insertAtBeginning(int d)
{
    NODE *temp = createNode(d);
    temp->data = d;
    temp->next = head;
    head = temp;
    displayList();
}

void insertAtPos(int d, int pos){

}

void insertAtEnd(int d)
{
    if (isListEmpty())
    {
        insertAtBeginning(d);
        return;
    }
    else
    {
        NODE *temp = createNode(d);
        temp->data = d;
        NODE *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = NULL;
        displayList();
    }
}

// insert(beg, index, end), delete(beg, index, end), traverse, count the number of nodes, reverse the list
int main()
{
    bool flag = true;
    int option = 0;
    int subOption = 0;

    while (flag)
    {
        option = -1;
        subOption = -1;

        cout << "Enter the operation you want to do on the list: \n\n";
        cout << "0. Exit\n";
        cout << "1. Create List\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Traverse\n";
        cout << "5. Count\n";
        cout << "6. Reverse\n";
        cout << "\nOption: ";
        cin >> option;
        cout << endl;
        if (option == 2)
        {
            cout << "1. Insert element at the beginning of the list.\n";
            cout << "2. Insert element at after an index of the list.\n";
            cout << "3. Insert element at the end of the list.\n";
            cout << "\nOption: ";
            cin >> subOption;
            cout << endl;
        }
        if (option == 3)
        {
            if (isListEmpty())
            {
                cout << "List size is 1. Cannot delete an element!\n\n";
                continue;
            }
            cout << "1. Delete element at the beginning of the array.\n";
            cout << "2. Delete element at an index of the array.\n";
            cout << "3. Delete element at the end of the array.\n";
            cout << "\nOption: ";
            cin >> subOption;
            cout << endl;
        }

        switch (option)
        {
        case 0:
            flag = false;
            break;

        case 1:
            if (!isListEmpty())
            {
                cout << "List already created!\n"
                     << endl;
                break;
            }
            int d;
            cout << "Enter the 1st value: ";
            cin >> d;
            head = createNode(d);
            head->next = NULL;
            break;

        case 2:
            if (subOption == 1)
            {
                int d;
                cout << "Enter the value to be inserted at the beginning: ";
                cin >> d;
                insertAtBeginning(d);
            }
            else if (subOption == 2)
            {
                int d, pos;
                cout << "Enter the position at which data to be inserted: ";
                cin >> pos;
                cout << "Enter the value to be inserted: ";
                cin >> d;
                // insertAtPos(d, pos);
            }
            else if (subOption == 3)
            {
                int d;
                cout << "Enter the value to be inserted at the end: ";
                cin >> d;
                insertAtEnd(d);
            }
            break;

        case 3:
            if (subOption == 1)
            {
                // deleteAtBeginning();
            }
            if (subOption == 2)
            {
                int d;
                cout << "Enter the data you want to delete: ";
                cin >> d;
                // deleteAtData(d);
            }
            if (subOption == 3)
            {
                // deleteAtEnd();
            }
            break;

        case 4:
            displayList();
            break;

        case 5:
            int n = countList();
            cout << "Number of elements in the list: " << n << endl;
            break;
        }
    }
}