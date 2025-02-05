// Implement insertion (at the beginning, at specified location, at the end)
// and deletion (at the beginning, at specified location, at the end) on double
// linked list.
#include <iostream>
#include <malloc.h>
using namespace std;

struct NODE
{
    int data;
    NODE *prev;
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
        cout << "\n\t[Nothing to print!]\n\n";
        return;
    }
    else
    {
        cout << "\n\tList: ";
        NODE *p = head;
        while (p != NULL)
        {
            cout << p->data;
            p = p->next;
            if (p != NULL)
                cout << " <-> ";
        }
    }
    cout << endl
         << endl;
}

void displayReverse()
{
    if (isListEmpty())
    {
        cout << "\n\t[Nothing to print!]\n\n";
        return;
    }
    else
    {
        cout << "\n\tList: ";
        NODE *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        while (p != NULL)
        {
            cout << p->data;
            p = p->prev;
            if (p != NULL)
                cout << " <-> ";
        }
    }
    cout << endl
         << endl;
}

int takeSubInput(string x)
{
    int subOption = 0;
    cout << "1. " << x << " element at the beginning of the list.\n";
    cout << "2. " << x << " element at a location of the list.\n";
    cout << "3. " << x << " element at the end of the list.\n";
    cout << "\nOption: ";
    cin >> subOption;
    if (subOption != 1 && subOption != 2 && subOption != 3)
    {
        cout << "\n\t[Invalid option!]\n\n";
    }
    return subOption;
}

void insertAtBeginning(int d)
{
    NODE *temp = createNode(d);
    temp->data = d;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    cout << "\n\t[Element Inserted!]\n";
    displayList();
}

void insertAtPos(int d, int pos)
{
    NODE *dataNode = createNode(d);
    NODE *temp = head;
    while (temp != NULL && pos != temp->data)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "\n\t[Location not found!]\n\n";
        return;
    }
    if (temp->next == NULL)
    {
        dataNode->next = NULL;
        temp->next = dataNode;
        dataNode->prev = temp;
        cout << "\n\t[Element Inserted!]\n";
        displayList();
        return;
    }
    dataNode->next = temp->next;
    temp->next->prev = dataNode;
    dataNode->prev = temp;
    temp->next = dataNode;
    cout << "\n\t[Element Inserted!]\n";
    displayList();
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
        NODE *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = NULL;
        temp->prev = p;
        displayList();
    }
}

void deleteAtBeg()
{
    NODE *temp = head;
    head = head->next;
    delete (temp);
    head->prev = NULL;
    cout << "\n\t[Element at the beginning deleted!]\n";
    displayList();
}

void deleteAtLoc(int loc)
{
    NODE *temp1 = head;

    // If the node to delete is the head node
    if (head->data == loc)
    {
        head = head->next;
        delete temp1;
        head->prev = NULL;
        cout << "\n\t[Element Deleted!]\n";
        displayList();
        return;
    }

    // Traverse the list to find the node with 'loc'
    while (temp1 != NULL && temp1->data != loc)
    {
        temp1 = temp1->next;
    }

    // If location not found
    if (temp1 == NULL)
    {
        cout << "\n\t[Location not found!]\n\n";
        return;
    }

    // Unlink the node to be deleted
    temp1->prev->next = temp1->next;
    if (temp1->next != NULL)
        temp1->next->prev = temp1->prev;
    delete temp1;

    cout << "\n\t[Element Deleted!]\n";
    displayList();
}

void deleteAtEnd()
{
    NODE *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete (temp);
    cout << "\t[Element at the end deleted!]\n\n";
    displayList();
}

int main()
{
    cout << "\n\t[Doubly Linked List]\n\n";
    bool flag = true;
    int option = 0;
    int subOption = 0;

    while (flag)
    {
        option = -1;
        subOption = -1;

        cout << "Enter the operation you want to do on the list: \n\n";
        cout << "0. Exit\n";
        cout << "1. Create Doubly Linked List\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Traverse\n";
        cout << "5. Reverse Traverse\n";
        cout << "\nOption: ";
        cin >> option;
        cout << endl;
        if (option == 2)
        {
            if (isListEmpty())
            {
                cout << "\t[List is not created yet, first create the list by pressing '1'\n\n";
                continue;
            }
            subOption = takeSubInput("Insert");
            cout << endl;
        }
        if (option == 3)
        {
            if (isListEmpty())
            {
                cout << "\t[List size is 0. Cannot delete an element!]\n\n";
                continue;
            }
            if (head->next == NULL)
            {
                delete head;
                head = NULL;
                cout << "\n\t[Element Deleted!]\n";
                displayList();
                continue;
            }
            subOption = takeSubInput("Delete");
            cout << endl;
        }

        switch (option)
        {
        case 0:
            flag = false;
            break;

        case 1:
        {
            if (!isListEmpty())
            {
                cout << "\t[List already created!]\n"
                     << endl;
                break;
            }
            int d;
            cout << "Enter the 1st value: ";
            cin >> d;
            head = createNode(d);
            head->prev = NULL;
            head->next = NULL;
            cout << "\n\t[List Created!]\n\n";
            displayList();
            break;
        }

        case 2:
        {
            bool insertOrNot = true;
            int yesOrNo = -1;
            while (insertOrNot)
            {
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
                    cout << "Enter the location at which data to be inserted: ";
                    cin >> pos;
                    cout << "Enter the value to be inserted: ";
                    cin >> d;
                    insertAtPos(d, pos);
                }
                else if (subOption == 3)
                {
                    int d;
                    cout << "Enter the value to be inserted at the end: ";
                    cin >> d;
                    insertAtEnd(d);
                }
                cout << "Want to add more elements? [Yes = 1 / No = 0]: ";
                cin >> yesOrNo;
                cout << endl;
                if (yesOrNo == 0)
                {
                    insertOrNot = false;
                }
                else
                {
                    subOption = takeSubInput("Insert");
                }
            }
            break;
        }
        case 3:
        {
            if (subOption == 1)
            {
                deleteAtBeg();
            }
            if (subOption == 2)
            {
                int d;
                cout << "Enter the data you want to delete: ";
                cin >> d;
                deleteAtLoc(d);
            }
            if (subOption == 3)
            {
                deleteAtEnd();
            }
            break;
        }

        case 4:
            displayList();
            break;

        case 5:
            displayReverse();
            break;

        default:
        {
            cout << "\t[Invalid option, try again!]\n\n";
            break;
        }
        }
    }
}