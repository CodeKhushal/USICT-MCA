#include <iostream>
#include <cmath>
using namespace std;

pair<float, float> basicCOCOMO(int linesOfCode, int mode)
{
    float a, b, c, d;
    // mode => 1: organic, 2: semi-detached, 3: embedded
    if (mode == 1)
    {
        a = 2.4;
        b = 1.05;
        c = 2.5;
        d = 0.38;
    }
    else if (mode == 2)
    {
        a = 3.0;
        b = 1.12;
        c = 2.5;
        d = 0.35;
    }
    else if (mode == 3)
    {
        a = 3.6;
        b = 1.20;
        c = 2.5;
        d = 0.32;
    }
    else
    {
        cout << "Invalid mode!" << endl;
        return {0, 0};
    }
    float effort = a * pow(linesOfCode, b);
    return {effort, c * pow(effort, d)};
}

int main()
{
    int linesOfCode, mode;
    cout << "Enter the estimated lines of code (KLOC): ";
    cin >> linesOfCode;
    cout << "Select the mode\n\t1 Organic\n\t2 Semi-detached\n\t3 Embedded\nMode: ";
    cin >> mode;

    float effort = basicCOCOMO(linesOfCode, mode).first;
    float time = basicCOCOMO(linesOfCode, mode).second;
    cout << "\n\t[Basic COCOMO Effort (person-months): " << effort << "]" << endl;
    cout << "\t[Basic COCOMO Development Time (months): " << time << "]" << endl;
    cout << "\t[Basic COCOMO Average Staff Size (persons): " << effort/time << "]" << endl;
    cout << "\t[Basic COCOMO Productivity (KLOC/PM): " << linesOfCode/effort << "]" << endl;
    return 0;
}