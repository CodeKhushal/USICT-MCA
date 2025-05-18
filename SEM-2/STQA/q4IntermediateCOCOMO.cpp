#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

float getWeight(vector<pair<string, float>> &weights, string rating)
{
    for (const auto &w : weights)
    {
        if (w.first == rating)
        {
            cout << w.second << endl;
            return w.second;
        }
    }
    cout << "Invalid rating!" << endl;
    return 1.0;
}

// Function to calculate EAF based on user input for all cost drivers
float calculateEAF()
{
    vector<pair<string, vector<pair<string, float>>>> costDrivers = {
        {"RELY", {{"VeryLow", 0.75}, {"Low", 0.88}, {"Nominal", 1.00}, {"High", 1.15}, {"VeryHigh", 1.40}}},
        {"DATA", {{"Low", 0.94}, {"Nominal", 1.00}, {"High", 1.08}, {"VeryHigh", 1.16}}},
        {"CPLX", {{"VeryLow", 0.70}, {"Low", 0.85}, {"Nominal", 1.00}, {"High", 1.15}, {"VeryHigh", 1.30}, {"ExtraHigh", 1.65}}},
        {"TIME", {{"Nominal", 1.00}, {"High", 1.11}, {"VeryHigh", 1.30}, {"ExtraHigh", 1.66}}},
        {"STOR", {{"Nominal", 1.00}, {"High", 1.06}, {"VeryHigh", 1.21}, {"ExtraHigh", 1.56}}},
        {"VIRT", {{"Low", 0.87}, {"Nominal", 1.00}, {"High", 1.15}, {"VeryHigh", 1.30}}},
        {"TURN", {{"Low", 0.87}, {"Nominal", 1.00}, {"High", 1.07}, {"VeryHigh", 1.15}}},
        {"ACAP", {{"VeryLow", 1.46}, {"Low", 1.19}, {"Nominal", 1.00}, {"High", 0.86}, {"VeryHigh", 0.71}}},
        {"AEXP", {{"VeryLow", 1.29}, {"Low", 1.13}, {"Nominal", 1.00}, {"High", 0.91}, {"VeryHigh", 0.82}}},
        {"PCAP", {{"VeryLow", 1.42}, {"Low", 1.17}, {"Nominal", 1.00}, {"High", 0.86}, {"VeryHigh", 0.70}}},
        {"VEXP", {{"VeryLow", 1.21}, {"Low", 1.10}, {"Nominal", 1.00}, {"High", 0.90}}},
        {"LEXP", {{"VeryLow", 1.14}, {"Low", 1.07}, {"Nominal", 1.00}, {"High", 0.95}}},
        {"MODP", {{"VeryLow", 1.24}, {"Low", 1.10}, {"Nominal", 1.00}, {"High", 0.91}, {"VeryHigh", 0.82}}},
        {"TOOL", {{"VeryLow", 1.24}, {"Low", 1.10}, {"Nominal", 1.00}, {"High", 0.91}, {"VeryHigh", 0.83}}},
        {"SCED", {{"VeryLow", 1.23}, {"Low", 1.08}, {"Nominal", 1.00}, {"High", 1.04}, {"VeryHigh", 1.10}}}};

    float eaf = 1.0;
    string rating;

    for (auto &driver : costDrivers)
    {
        cout << "Enter rating for " << driver.first << " (";
        int index = 0;
        int total = driver.second.size();
        for (auto &r : driver.second)
        {
            cout << r.first;
            if (index < total - 1)
            { // Add comma if not the last element
                cout << ", ";
            }
            index++;
        }
        cout << "): ";
        cin >> rating;
        eaf *= getWeight(driver.second, rating);
    }

    return eaf;
}

pair<float, float> intermediateCOCOMO(int linesOfCode, int mode, float eaf)
{
    float a, b, c, d;
    if (mode == 1)
    { // Organic
        a = 3.2;
        b = 1.05;
        c = 2.5;
        d = 0.38;
    }
    else if (mode == 2)
    { // Semi-detached
        a = 3.0;
        b = 1.12;
        c = 2.5;
        d = 0.35;
    }
    else if (mode == 3)
    { // Embedded
        a = 2.8;
        b = 1.20;
        c = 2.5;
        d = 0.32;
    }
    else
    {
        cout << "Invalid mode!" << endl;
        return {0, 0};
    }
    float effort = eaf * a * pow(linesOfCode, b);
    return {effort, c * pow(effort, d)};
}

int main()
{
    int linesOfCode, mode;
    cout << "Enter the estimated lines of code (LOC): ";
    cin >> linesOfCode;
    cout << "Select the mode\n\t1 Organic\n\t2 Semi-detached\n\t3 Embedded\nMode: ";
    cin >> mode;

    float eaf = calculateEAF();
    cout << "\n\t[Effective Adjustment Factor (EAF): " << eaf << "]" << endl;

    float effort = intermediateCOCOMO(linesOfCode, mode, eaf).first;
    float time = intermediateCOCOMO(linesOfCode, mode, eaf).second;
    cout << "\t[Intermediate COCOMO Effort (person-months): " << effort << "]" << endl;
    cout << "\t[Intermediate COCOMO Development Time (months): " << time << "]" << endl;

    return 0;
}