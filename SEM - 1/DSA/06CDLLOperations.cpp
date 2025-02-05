// Implement insertion (at the beginning, at specified location, at the end)
// and deletion (at the beginning, at specified location, at the end) on
// circular double linked list.

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

bool isOnlyHeadPresent()
{
    return head->next == head;
}

void displayList()
{
    if (isListEmpty())
    {
        cout << "\n\t[List is Empty, Nothing to print!]\n\n";
        return;
    }
    else
    {
        cout << "\n\tList: ";
        NODE *temp = head;
        do
        {
            cout << temp->data << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << "[Head]";
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
        NODE *p = head->prev;
        do
        {
            cout << p->data << " <-> ";
            p = p->prev;
        } while (p != head->prev);
        cout << head->prev->data << "[Last]";
    }
    cout << endl
         << endl;
}

int takeSubInput(string x)
{
    int subOption = 0;
    cout << "1. " << x << " element at the beginning of the list.\n";
    cout << "2. " << x << " element at an position of the list.\n";
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
    NODE *newNode = createNode(d);
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    cout << "\n\t[Element Inserted!]\n";
    displayList();
}

void insertAtPos(int d, int loc)
{
    NODE *newNode = createNode(d);
    NODE *temp = head->next;

    do
    {
        if (temp->data == loc)
        {
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            if (temp == head->prev)
                head->prev = newNode;
            cout << "\n\t[Element Inserted!]\n";
            displayList();
            return;
        }
        temp = temp->next;
    } while (temp != head->next);
    cout << "\n\t[Location not found!]\n\n";
    return;
}

void insertAtEnd(int d)
{
    NODE *newNode = createNode(d);
    head->prev->next = newNode;
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev = newNode;
    cout << "\n\t[Element Inserted!]\n";
    displayList();
}

void deleteAtBeg()
{
    if (isOnlyHeadPresent())
    {
        head = NULL;
        cout << "\n\t[Element Deleted!]\n";
        displayList();
        return;
    }
    NODE *temp = head;
    head = head->next;
    head->prev = temp->prev;
    temp->prev->next = head;
    delete temp;
    cout << "\n\t[Element Deleted!]\n";
    displayList();
}

void deleteAtLoc(int loc)
{
    NODE *temp1 = head;

    // If the node to delete is the head node
    if (head->data == loc)
    {
        if (isOnlyHeadPresent())
        {
            head = NULL;
            cout << "\n\t[Element Deleted!]\n";
            displayList();
            return;
        }

        deleteAtBeg();
        return;
    }

    // Traverse the list to find the node with 'loc'
    while (temp1->next != head && temp1->data != loc)
    {
        temp1 = temp1->next;
    }

    // If location not found
    if (temp1 == head)
    {
        cout << "\n\t[Location not found!]\n\n";
        return;
    }

    // Unlink the node to be deleted
    temp1->prev->next = temp1->next;
    temp1->next->prev = temp1->prev;
    delete temp1;

    cout << "\n\t[Element Deleted!]\n";
    displayList();
}

void deleteAtEnd()
{
    if (isOnlyHeadPresent())
    {
        head = NULL;
        cout << "\n\t[Element Deleted!]\n";
        displayList();
        return;
    }
    NODE *temp = head->prev;
    temp->prev->next = head;
    head->prev = temp->prev;
    delete temp;
    cout << "\n\t[Element Deleted!]\n";
    displayList();
}

int main()
{
    cout << "\n\t[Circular Doubly Linked List]\n\n";
    bool flag = true;
    int option = 0;
    int subOption = 0;

    while (flag)
    {
        option = -1;
        subOption = -1;

        cout << "Enter the operation you want to do on the list: \n\n";
        cout << "0. Exit\n";
        cout << "1. Create Circular Doubly Linked List\n";
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
            if (isOnlyHeadPresent())
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
            head->next = head;
            head->prev = head;
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
                    cout << "Enter the position at which data to be inserted: ";
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