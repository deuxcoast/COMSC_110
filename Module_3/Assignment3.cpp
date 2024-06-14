// Conor Ney
// Professor Lo
// COMSC-110-5023
// 13 June 2024
// Assignment 3

#include <cmath>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

int main() {
  double principal, rate, interest, amount;
  int accountNumber, tPeriod;
  std::string name;

  std::cout << "*** This program will calculate and display the interest "
               "earned ***\n";

  // Read account number
  std::cout << "Please enter the account number: ";
  std::cin >> accountNumber;
  // Discard '\n' from keyboard buffer before next read
  std::cin.ignore();

  // Read name
  std::cout << "Please enter the full name of the account holder: ";
  std::getline(std::cin, name);

  // Read principal
  std::cout << "Please enter the principal ($): ";
  std::cin >> principal;

  // Read annual interest rate
  std::cout << "Please enter the annual interest rate (%): ";
  std::cin >> rate;

  // Convert interest rate percentage to decimal
  rate = rate / 100;

  // Read number of annual compounding periods
  std::cout
      << "Please enter the times compounded (4 - quarterly, 12 - monthly): ";
  std::cin >> tPeriod;

  // Calculate total amount
  amount = principal * std::pow((1 + (rate / tPeriod)), tPeriod);

  // Calculate interest
  interest = amount - principal;

  // ACCOUNT SUMMARY
  std::cout << std::setprecision(2) << std::fixed;

  std::cout << "\n        Account Summary\n";
  std::cout << "===============================\n";

  // Print account number
  std::cout << std::left << std::setw(20) << "Account Number: " << accountNumber
            << std::endl;

  // Print account holder name
  std::cout << std::left << std::setw(20) << "Account Holder: " << name
            << std::endl;
  // Print principal
  std::cout << std::left << std::setw(20) << "Principal: ";
  std::cout << "$" << std::right << std::setw(10) << principal << std::endl;

  // Print interest rate
  std::cout << std::left << std::setw(20) << "Interest Rate: ";
  std::cout << std::right << std::setw(11) << rate;
  std::cout << std::setw(1) << "%" << std::endl;

  // Print times compounded
  std::cout << std::left << std::setw(20) << "Times Compounded: ";
  std::cout << std::right << std::setw(11) << tPeriod << std::endl;

  // Print interest
  std::cout << std::left << std::setw(20) << "Interest: ";
  std::cout << "$" << std::right << std::setw(10) << interest << std::endl;

  // Print total amount
  std::cout << std::left << std::setw(20) << "Amount in savings: ";
  std::cout << "$" << std::right << std::setw(10) << amount << std::endl;

  return 0;
}
