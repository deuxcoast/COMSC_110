#include <iostream>
using namespace std;

int main() {
    float price, taxRate, total;

    // Get the retail price
    cout << "Please enter the retail price of the item being purchased: ";
    cin >> price;

    // Get the tax rate
    cout << "Please enter sale tax rate in percentage (%): ";
    cin >> taxRate;

    // Turn tax rate into a percentage
    taxRate = taxRate / 100.0;

    // Calculate total price including tax
    total = price + (price * taxRate);

    // Display the price, tax rate, and total price
    cout << "The retail price of the item being purchased is: $" << price
         << endl;
    cout << "The sale tax rate is: " << taxRate * 100 << "%" << endl;
    cout << "The total of the sale is: $" << total << endl;
    return 0;
}
