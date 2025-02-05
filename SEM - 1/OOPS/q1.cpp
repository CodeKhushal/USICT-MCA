#include <iostream>
using namespace std;

void callByValue(int a)
{
    a = a + 10;
    cout << "Inside callByValue, a = " << a << endl;
}

void callByReference(int &a)
{
    a = a + 10;
    cout << "Inside callByReference, a = " << a << endl;
}

// Swap function using Call by Reference
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
    cout << "Inside swap function, x = " << x << ", y = " << y << endl;
}

int main()
{
    int num1, num2;
    cout<<"Enter a: ";
    cin>>num1;
    cout<<"Enter b: ";
    cin>>num2;
    cout << "\nBefore callByValue, adding 10 to a = " << num1 << endl;
    callByValue(num1);
    cout << "After callByValue, adding 10 to a = " << num1 << endl;

    cout << "\nBefore callByReference, adding 10 to b = " << num2 << endl;
    callByReference(num2);
    cout << "After callByReference, adding 10 to b = " << num2 << endl;

    cout << "\nBefore swap, a = " << num1 << ", b = " << num2 << endl;
    swap(num1, num2);
    cout << "After swap, a = " << num1 << ", b = " << num2 << endl;

    return 0;
}
