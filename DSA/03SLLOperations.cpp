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

void insertAtPos(int d, int pos)
{
    NODE *dataNode = createNode(d);
    NODE *temp = head;
    while (temp != NULL && pos != temp->data)
    {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        cout << "\n\t[Location not found!]\n\n";
        return;
    }
    dataNode->next = temp->next;
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

void deleteAtBeg()
{
    if (isListEmpty())
    {
        cout << "\t[List is empty!]" << endl;
        return;
    }
    NODE *temp = head;
    head = head->next;
    delete (temp);
    cout << "\n\t[Element at the beginning deleted!]\n";
    displayList();
}

void deleteAtLoc(int loc)
{
    if (isListEmpty())
    {
        cout << "\t[List is empty!]" << endl;
        return;
    }

    NODE *temp1 = head;

    // If the node to delete is the head node
    if (head->data == loc)
    {
        head = head->next;
        delete temp1;
        cout << "\n\t[Element Deleted!]\n";
        displayList();
        return;
    }
    NODE *temp = nullptr;

    // Traverse the list to find the node with 'loc'
    while (temp1 != NULL && temp1->data != loc)
    {
        temp = temp1;
        temp1 = temp1->next;
    }

    // If location not found
    if (temp1 == NULL)
    {
        cout << "\n\t[Location not found!]\n\n";
        return;
    }

    // Unlink the node to be deleted
    temp->next = temp1->next;
    delete temp1;

    cout << "\n\t[Element Deleted!]\n";
    displayList();
}

void deleteAtEnd()
{
    if (isListEmpty())
    {
        cout << "\t[List is empty!]" << endl;
    }
    NODE *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    NODE *temp2 = temp->next;
    temp->next = NULL;
    delete (temp2);
    cout << "\t[Element at the end deleted!]\n\n";
    displayList();
}

int takeSubInput(string x)
{
    int subOption = 0;
    cout << "1. " << x << " element at the beginning of the list.\n";
    cout << "2. " << x << " element at an index of the list.\n";
    cout << "3. " << x << " element at the end of the list.\n";
    cout << "\nOption: ";
    cin >> subOption;
    if (subOption != 1 && subOption != 2 && subOption != 3)
    {
        cout << "\n\t[Invalid option!]\n\n";
    }
    return subOption;
}

void reverseList()
{
    NODE *prev = NULL;
    NODE *current = head;
    NODE *save = NULL;
    while (current != NULL)
    {
        save = current->next;
        current->next = prev;
        prev = current;
        current = save;
    }
    head = prev;
    cout << "\t[List is reversed!]\n\n";
    displayList();
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
                cout << "\t[List size is 0/1. Cannot delete an element!]\n\n";
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
        {
            int n = countList();
            cout << "\t[Number of elements in the list: " << n << "]\n"
                 << endl;
            break;
        }

        case 6:
        {
            reverseList();
            break;
        }

        default:
        {
            cout << "\t[Invalid option, try again!]\n\n";
            break;
        }
        }
    }
}