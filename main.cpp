#include <iostream>
#include <iomanip>
#include <limits>
#include "DivSales.h"

using namespace std;

int main() {
    cout << fixed << setprecision(2);

    cout << "Initial yearly corporate sales: $"
         << DivSales::getCorporateSales() << "\n\n";

    DivSales divisions[6];

    // Get sales for all four quarters for each of the six divisions.
    for (int division = 0; division < 6; ++division) {
        double sales[4];

        cout << "Enter sales for Division " << division + 1 << ":\n";

        for (int quarter = 0; quarter < 4; ++quarter) {
            while (true) {
                cout << "  Quarter " << quarter + 1 << ": $";

                if (cin >> sales[quarter] && sales[quarter] > 0) {
                    break;
                }

                cout << "  Invalid input. Enter a positive sales amount.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        divisions[division].setSales(
            sales[0], sales[1], sales[2], sales[3]
        );
        cout << endl;
    }

    // Display the sales table.
    cout << "Division Sales by Quarter\n";
    cout << left << setw(12) << "Division"
         << right << setw(14) << "Quarter 1"
         << setw(14) << "Quarter 2"
         << setw(14) << "Quarter 3"
         << setw(14) << "Quarter 4" << endl;

    for (int division = 0; division < 6; ++division) {
        cout << left << setw(12) << division + 1;

        for (int quarter = 0; quarter < 4; ++quarter) {
            cout << right << setw(14)
                 << divisions[division].getQuarterSales(quarter);
        }

        cout << endl;
    }

    cout << "\nTotal corporate sales for the year: $"
         << DivSales::getCorporateSales() << endl;

    return 0;
}
