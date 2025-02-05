#include <iostream>
#include <vector>
using namespace std;

int calculateFunctionPoints()
{
    vector<pair<string, pair<int, int>>> complexities = {
        {"EI", {3, 4}},   // External Inputs: Low x 3, Average x 4, High x 6
        {"EO", {4, 5}},   // External Outputs: Low x 4, Average x 5, High x 7
        {"EQ", {3, 4}},   // External Inquiries: Low x 3, Average x 4, High x 6
        {"ILF", {7, 10}}, // Internal Logical Files: Low x 7, Average x 10, High x 15
        {"EIF", {5, 7}}   // External Interface Files: Low x 5, Average x 7, High x 10
    };

    int ufp = 0;
    int count, complexity;

    // g++ -std=c++17 q6functionPoint.cpp -o q6functionPoint
    for (auto &[unit, weights] : complexities)
    {
        cout << "Enter count for " << unit << ": ";
        cin >> count;
        cout << "Enter complexity (1 for Low, 2 for Average, 3 for High): ";
        cin >> complexity;

        if (complexity == 1)
            ufp += count * weights.first;
        else if (complexity == 2)
            ufp += count * weights.second;
        else if (complexity == 3)
            ufp += count * (weights.second + 2); // High complexity calculation
        else
            cout << "Invalid complexity level!" << endl;
    }

    return ufp;
}

int main()
{
    int ufp = calculateFunctionPoints();
    cout << "\n\t[Unadjusted Function Point (UFP): " << ufp << "]" << endl;
    cout << "\n\t[Function Point (FP): " << (int)(ufp * 1.07) << "]" << endl;
    return 0;
}