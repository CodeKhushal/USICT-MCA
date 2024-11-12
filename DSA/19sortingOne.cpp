#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "]" << endl;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void countingSort(int arr[], int n)
{
    int max_val = arr[0];
    for (int i = 1; i < n; i++) // finding maximum value in the array
        if (arr[i] > max_val)
            max_val = arr[i];

    int count[max_val + 1] = {0};

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= max_val; i++)
        while (count[i]-- > 0)
            arr[index++] = i;
}

int getMax(int arr[], int n)
{
    int max_val = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max_val)
            max_val = arr[i];
    return max_val;
}

void countingSortForRadix(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int max_val = getMax(arr, n);
    for (int exp = 1; max_val / exp > 0; exp *= 10)
        countingSortForRadix(arr, n, exp);
}

void bucketSort(int arr[], int n)
{
    int buckets[10][n];
    int bucketCount[10] = {0};
    int max_val = arr[0];
    int min_val = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_val)
            max_val = arr[i];
        if (arr[i] < min_val)
            min_val = arr[i];
    }

    int range = (max_val - min_val + 1) / 10 + 1;

    for (int i = 0; i < n; i++)
    {
        int bucketIndex = (arr[i] - min_val) / range;
        buckets[bucketIndex][bucketCount[bucketIndex]++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < bucketCount[i] - 1; j++)
        {
            for (int k = j + 1; k < bucketCount[i]; k++)
            {
                if (buckets[i][j] > buckets[i][k])
                {
                    int temp = buckets[i][j];
                    buckets[i][j] = buckets[i][k];
                    buckets[i][k] = temp;
                }
            }
        }
        for (int j = 0; j < bucketCount[i]; j++)
            arr[index++] = buckets[i][j];
    }
}

int main()
{
    int choice = -1, n;

    while (choice != 0)
    {
        cout << "\n--- Sorting Menu ---\n";
        cout << "0. Exit\n";
        cout << "1. Heap Sort\n";
        cout << "2. Counting Sort\n";
        cout << "3. Radix Sort\n";
        cout << "4. Bucket Sort\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting program.\n";
            break;
        }

        cout << "Enter the size of the array: ";
        cin >> n;
        int arr[n];

        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        switch (choice)
        {
        case 1:
            heapSort(arr, n);
            cout << "\n\tArray after Heap Sort: ";
            break;
        case 2:
            countingSort(arr, n);
            cout << "\n\tArray after Counting Sort: ";
            break;
        case 3:
            radixSort(arr, n);
            cout << "\n\tArray after Radix Sort: ";
            break;
        case 4:
            bucketSort(arr, n);
            cout << "\n\tArray after Bucket Sort: ";
            break;
        default:
            cout << "\n\t[Invalid choice! Please try again.]\n";
            continue;
        }

        printArray(arr, n);
    }

    return 0;
}
