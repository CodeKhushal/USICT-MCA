#include <iostream>
#include <cmath>
using namespace std;

// Part A: Find roots of a quadratic equation
void findRoots(double a, double b, double c)
{
    double discriminant = b * b - 4 * a * c;
    if (a==0)
    {
        cout << "It is not a quadratic quation"<< endl;
    }
    else if (discriminant > 0)
    {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and different: " << root1 << " , " << root2 << endl;
    }
    else if (discriminant == 0)
    {
        double root = -b / (2 * a);
        cout << "Roots are real and same: " << root << endl;
    }
    else
    {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Roots are complex: " << realPart << " + " << imaginaryPart << "i and "
             << realPart << " - " << imaginaryPart << "i" << endl;
    }
}

// Part B: Determine type of triangle
string triangleType(double side1, double side2, double side3)
{
    if (side1 == side2 && side2 == side3)
    {
        return "Equilateral";
    }
    else if (side1 == side2 || side2 == side3 || side1 == side3)
    {
        return "Isosceles";
    }
    else
    {
        return "Scalene";
    }
}

int main()
{
    double a, b, c;
    cout << "Enter coefficients a, b, and c for the quadratic equation:\n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    findRoots(a, b, c);

    double side1, side2, side3;
    cout << "\nEnter the three sides of a triangle:\n";
    cout << "Side 1: ";
    cin >> side1;
    cout << "Side 2: ";
    cin >> side2;
    cout << "Side 3: ";
    cin >> side3;

    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
    {
        cout << "The triangle is " << triangleType(side1, side2, side3) << endl;
    }
    else
    {
        cout << "The values do not form a valid triangle." << endl;
    }

    return 0;
}
