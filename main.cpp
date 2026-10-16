#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const double PLAN_A_COST = 39.99;
    const double PLAN_B_COST = 59.99;
    const double PLAN_C_COST = 79.99;
    const int PLAN_A_DATA = 2;
    const int PLAN_B_DATA = 8;
    const double EXTRA_DATA_COST = 8.00;

    string name;
    char plan;
    double gigabytes, bill;

    cout << "Enter customer name: ";
    getline(cin, name);

    cout << "Enter plan purchased (A, B, or C): ";
    cin >> plan;

    if (plan == 'A' || plan == 'a' ||
        plan == 'B' || plan == 'b') {
        cout << "Enter gigabytes used: ";
        cin >> gigabytes;
    } else {
        gigabytes = 0;
    }

    cout << fixed << setprecision(2);

    if (plan == 'A' || plan == 'a') {
        bill = PLAN_A_COST;

        if (gigabytes > PLAN_A_DATA)
            bill += (gigabytes - PLAN_A_DATA) * EXTRA_DATA_COST;

    } else if (plan == 'B' || plan == 'b') {
        bill = PLAN_B_COST;

        if (gigabytes > PLAN_B_DATA)
            bill += (gigabytes - PLAN_B_DATA) * EXTRA_DATA_COST;

    } else if (plan == 'C' || plan == 'c') {
        bill = PLAN_C_COST;

    } else {
        cout << "Invalid plan selected." << endl;
        return 1;
    }

    cout << "\nCustomer Name: " << name << endl;
    cout << "Plan Purchased: " << char(toupper(plan)) << endl;
    cout << "Total Monthly Bill: $" << bill << endl;

    double planABill = PLAN_A_COST;
    if (gigabytes > PLAN_A_DATA && (plan == 'A' || plan == 'a'))
        planABill += (gigabytes - PLAN_A_DATA) * EXTRA_DATA_COST;

    if (plan == 'A' || plan == 'a') {
        if (gigabytes > PLAN_B_DATA) {
            double planBBill = PLAN_B_COST +
                (gigabytes - PLAN_B_DATA) * EXTRA_DATA_COST;
            double savings = bill - planBBill;
            if (savings > 0)
                cout << "Savings with Plan B: $" << savings << endl;
        }

        double savingsC = bill - PLAN_C_COST;
        if (savingsC > 0)
            cout << "Savings with Plan C: $" << savingsC << endl;

    } else if (plan == 'B' || plan == 'b') {
        double savingsC = bill - PLAN_C_COST;
        if (savingsC > 0)
            cout << "Savings with Plan C: $" << savingsC << endl;
    }

    return 0;
}