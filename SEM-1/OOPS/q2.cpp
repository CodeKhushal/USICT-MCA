#include <iostream>
using namespace std;

double calculateSimpleInterest(double principal, double time, double rate = 5.0)
{
    return (principal * time * rate) / 100;
}

int main()
{
    double principal, time, rate;
    string rateInput;
    double interest;

    cout << "Enter principal amount: ";
    cin >> principal;

    cout << "Enter time (in years): ";
    cin >> time;

    cin.ignore();
    cout << "Enter rate of interest (leave blank for default 5%): ";
    getline(cin, rateInput);
    if (rateInput.empty())
    {
        interest = calculateSimpleInterest(principal, time);
        cout << "\n\t[Simple Interest using default rate of 5% = " << interest << "]\n"
             << endl;
    }
    else
    {
        rate = stod(rateInput); // convertingg string to double
        interest = calculateSimpleInterest(principal, time, rate);
        cout << "\n\t[Simple Interest with rate " << rate << "% = " << interest << "]\n"
             << endl;
    }

    return 0;
}
