#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

int aSize = 0;

void arrayTraversal(int a[])
{
    cout << "\tArray: [ ";
    for (int i = 0; i < aSize; i++)
    {
        cout << a[i] << " ";
    }
    cout << "]\n\n";
}

void insertAtBeginning(int arr[], int element)
{
    for (int i = aSize - 1; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[0] = element;
    cout << endl;
    arrayTraversal(arr);
}

void insertAtIndex(int arr[], int element, int index)
{
    for (int i = aSize - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    cout << endl;
    arrayTraversal(arr);
}

void insertAtEnd(int arr[], int element)
{
    arr[aSize - 1] = element;
    cout << endl;
    arrayTraversal(arr);
}

void deleteAtBeginning(int arr[])
{
    if (aSize == 0)
    {
        cout << "Array is empty, nothing to delete." << std::endl;
        return;
    }
    for (int i = 0; i < aSize - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    aSize--;
    cout << endl;
    arrayTraversal(arr);
}

void deleteAtIndex(int arr[], int index)
{
    for (int i = index; i < aSize - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    aSize--;
    cout << endl;
    arrayTraversal(arr);
}

void deleteAtEnd(int arr[])
{
    aSize--;
    cout << endl;
    arrayTraversal(arr);
}

int searchAtIndex(int arr[], int index)
{
    return arr[index];
}

int searchByElement(int arr[], int element)
{
    for (int i = 0; i < aSize; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int low, int high, int number)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (number == arr[mid])
    {
        return mid;
    }

    else if (number < arr[mid])
    {
        return binarySearch(arr, low, mid - 1, number);
    }

    else
    {
        return binarySearch(arr, mid + 1, high, number);
    }
}

void sort(int arr[])
{
    for (int i = 1; i < aSize; ++i)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        // arrayTraversal(arr);
    }
}

void sortDescending(int arr[])
{
}

int main()
{
    bool flag = true;

    cout << "Enter size of the array you want to create: ";
    cin >> aSize;
    while (aSize < 0)
    {
        cout << "Invalid size. Please enter a positive integer: ";
        cin >> aSize;
    }

    int arr[aSize];
    for (int i = 0; i < aSize; i++)
    {
        cout << "Enter element " << i + 1 << " of the array: ";
        cin >> arr[i];
    }

    cout << "Array created successfully.\n";
    cout << "Loading.......";

    sleep_for(4ns);
    sleep_until(system_clock::now() + 3s);

    system("cls");
    int option = 0;
    int subOption = 0;

    while (flag)
    {
        // arrayTraversal(arr, aSize);
        option = -1;
        subOption = -1;

        cout << "Enter the operation you want to do on the array: \n\n";
        cout << "0. Exit\n";
        cout << "1. Traverse\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Search\n";
        cout << "5. Sort\n";
        cout << "\nOption: ";
        cin >> option;
        cout << endl;
        if (option == 2)
        {
            cout << "1. Insert element at the beginning of the array.\n";
            cout << "2. Insert element at an index of the array.\n";
            cout << "3. Insert element at the end of the array.\n";
            cout << "\nOption: ";
            cin >> subOption;
            cout << endl;
        }
        if (option == 3)
        {
            if (aSize == 1)
            {
                cout << "Array size is 1. Cannot delete an element!\n\n";
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
            arrayTraversal(arr);
            break;

        case 2:
            if (subOption == 1)
            {
                int element;
                cout << "Enter the element you want to insert at the beginning of the array: ";
                cin >> element;
                insertAtBeginning(arr, element);
            }
            if (subOption == 2)
            {
                int element;
                int index;
                cout << "Enter the index at which you want to insert an element: ";
                cin >> index;
                while (index > aSize - 1)
                {
                    cout << "Index is greater than the size of the array! Re-enter the index: ";
                    cin >> index;
                }
                cout << "Enter the element you want to insert at index " << index << " of the array: ";
                cin >> element;
                insertAtIndex(arr, element, index);
            }
            if (subOption == 3)
            {
                int element;
                cout << "Enter the element you want to insert at the end of the array: ";
                cin >> element;
                insertAtEnd(arr, element);
            }
            break;

        case 3:
            if (subOption == 1)
            {
                deleteAtBeginning(arr);
            }
            if (subOption == 2)
            {
                int index;
                cout << "Enter the index at which you want to delete an element: ";
                cin >> index;
                while (index > aSize - 1)
                {
                    cout << "Index is greater than the size of the array! Re-enter the index: ";
                    cin >> index;
                }
                deleteAtIndex(arr, index);
            }
            if (subOption == 3)
            {
                deleteAtEnd(arr);
            }
            break;

        case 4:
            cout << "Want to search by\n1. Index\n2. Element\n3. Binary Search\n";
            cout << "\nOption: ";
            cin >> subOption;
            cout << endl;
            if (subOption == 1)
            {
                int index;
                cout << "Enter the index at which you want to search an element: ";
                cin >> index;
                while (index > aSize - 1)
                {
                    cout << "Index is greater than the size of the array! Re-enter the index: ";
                    cin >> index;
                }
                cout << "\nElement at index " << index << " is: " << searchAtIndex(arr, index) << endl
                     << endl;
            }
            if (subOption == 2)
            {
                int element;
                cout << "Enter the element you want to search in the array: ";
                cin >> element;
                if (searchByElement(arr, element) == -1)
                {
                    cout << "\nElement not found!\n\n";
                    break;
                }
                cout << "\nElement found at index: " << searchByElement(arr, element) << "\n\n";
            }
            if (subOption == 3)
            {
                int element;
                cout << "Enter the element you want to search in the array using binary search: ";
                cin >> element;
                if (binarySearch(arr, 0, aSize, element) == -1)
                {
                    cout << "\nElement not found!\n\n";
                    break;
                }
                cout << "\nElement found at index: " << binarySearch(arr, 0, aSize, element) << "\n\n";
            }
            break;

        case 5:
            cout << "1. Ascending\n2. Descending\n";
            cout << "\nOption: ";
            cin >> subOption;
            cout << endl;
            if (subOption == 1)
            {
                cout << "Sorting the array....\n";
                sort(arr);
                cout << "Array in now sorted!\n";
                arrayTraversal(arr);
            }
            if (subOption == 2)
            {
                sortDescending(arr);
            }
            break;

        default:
            cout << "Choose from the given options!\n";
            break;
        }
    }
}