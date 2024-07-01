#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

const int IN_PATIENT_CHOICE = 1, OUT_PATIENT_CHOICE = 2, QUIT_CHOICE = 3;

const int DAYS_DEFAULT = 1;
const double RATE_DEFAULT = 50, MED_CHARGE_DEFAULT = 0,
             SERVICE_CHARGE_DEFAULT = 0;

void show_menu();
void in_patient();
void out_patient();
int get_input(std::string, int);
double get_input(std::string, double);
int parse_line(int);
double parse_line(double);
int validate_non_negative(std::string, int, int);
double validate_non_negative(std::string, double, double);
double get_charge(int = DAYS_DEFAULT,
                  double = RATE_DEFAULT,
                  double = MED_CHARGE_DEFAULT,
                  double = SERVICE_CHARGE_DEFAULT);
double get_charge(double = MED_CHARGE_DEFAULT, double = SERVICE_CHARGE_DEFAULT);

int main() {
    int user_choice;
    std::cout << "Assignment 8 by Conor Ney\n\n";

    do {
        show_menu();
        std::cin >> user_choice;
        std::cin.ignore(10000, '\n');

        while (user_choice < IN_PATIENT_CHOICE || user_choice > QUIT_CHOICE ||
               std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Please enter a valid menu option: ";
            std::cin >> user_choice;
        }

        if (user_choice != QUIT_CHOICE) {
            switch (user_choice) {
                case IN_PATIENT_CHOICE: {
                    in_patient();
                    break;
                }
                case OUT_PATIENT_CHOICE: {
                    out_patient();
                    break;
                }
            }
        }
    } while (user_choice != QUIT_CHOICE);

    std::cout << "Quit the program.\n";

    return 0;
}

void show_menu() {
    std::cout << "**** Hospital Charge Calculator ****\n";
    std::cout << "1. Calculate In-Patient Charge.\n";
    std::cout << "2. Calculate Out-Patient Charge.\n";
    std::cout << "3. Quit\n";
    std::cout << "Enter your choice: ";
}

void in_patient() {
    int days;
    double rate, med_charge, service_charge, cost;

    std::string days_str = "the number of days spent in the hospital";
    std::string rate_str = "the daily rate";
    std::string med_str = "hospital medication charges";
    std::string service_str = "charges for hospital service";

    std::cout << std::setprecision(2) << std::fixed;

    days = get_input(days_str, DAYS_DEFAULT);
    rate = get_input(rate_str, RATE_DEFAULT);
    med_charge = get_input(med_str, MED_CHARGE_DEFAULT);
    service_charge = get_input(service_str, SERVICE_CHARGE_DEFAULT);

    cost = get_charge(days, rate, med_charge, service_charge);

    std::cout << "The total in-patient charge is $" << cost << "\n\n";
}

void out_patient() {
    double med_charge, service_charge, cost;

    std::string med_str = "hospital medication charges";
    std::string service_str = "charges for hospital service";

    std::cout << std::setprecision(2) << std::fixed;

    med_charge = get_input(med_str, MED_CHARGE_DEFAULT);
    service_charge = get_input(service_str, SERVICE_CHARGE_DEFAULT);

    cost = get_charge(med_charge, service_charge);

    std::cout << "The total out-patient charge is $" << cost << "\n\n";
}

int get_input(std::string field, int def) {
    std::string days = (def > 1) ? "days" : "day";

    std::cout << "Please enter " << field << " (default: " << def << " " << days
              << "): ";
    int val = parse_line(def);
    val = validate_non_negative(field, val, def);
    return val;
}

double get_input(std::string field, double def) {
    std::cout << "Please enter " << field << " (default: $" << def << "): ";
    double val = parse_line(def);
    val = validate_non_negative(field, val, def);
    return val;
}

double parse_line(double def) {
    std::string input;
    double val = 0;

    std::getline(std::cin, input);

    if (input.empty()) {
        val = def;
    } else {
        // TODO: should have error handling when input is not a number
        val = std::stod(input);
    }
    return val;
}

int parse_line(int def) {
    std::string input;
    int val = 0;

    std::getline(std::cin, input);

    if (input.empty()) {
        val = def;
    } else {
        // TODO: should have error handling when input is not a number
        val = std::stoi(input);
    }
    return val;
}

int validate_non_negative(std::string field, int val, int def) {
    while (val < 0) {
        std::string days = (def > 1) ? "days" : "day";

        std::cout << "Please enter a non-negative number for " << field
                  << " (default: " << def << " " << days << "): ";
        val = parse_line(def);
    }
    return val;
}

double validate_non_negative(std::string field, double val, double def) {
    while (val < 0) {
        std::cout << "Please enter a non-negative number for " << field
                  << " (default: $" << def << "): ";

        val = parse_line(def);
    }
    return val;
}

double get_charge(int days, double rate, double med_cost, double service_cost) {
    double stay_cost, total;
    stay_cost = days * rate;
    total = stay_cost + med_cost + service_cost;
    return total;
}

double get_charge(double med_cost, double service_cost) {
    return med_cost + service_cost;
}
