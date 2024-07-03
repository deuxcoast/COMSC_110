#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

int main() {
    std::string file_name;

    std::cout << "Please provide the name of the text file to be read: ";
    std::cin >> file_name;

    std::ifstream input_file;
    input_file.open(file_name);

    if (input_file) {
        std::cout << "Start processing the text file - " << file_name
                  << std::endl;
        // Process file and calculate statistics
        int current, count, min, max;
        int sum = 0;
        for (int i = 1; input_file >> current; i++) {
            // initialize min and max on the first iteration
            if (i == 1) {
                min = max = current;
            }
            std::cout << std::setw(6) << current;

            count++;
            sum += current;

            // compare against min
            min = (current <= min) ? current : min;

            // compare against max
            max = (current >= max) ? current : max;

            // 20 numbers per line
            if (i % 20 == 0) {
                std::cout << std::endl;
            }
        }
        // decrement count by one, for correct total.
        // we intialized to 1 in the for loop to avoid
        // the messiness of dealing with 0 mod 20
        count--;

        // calculate average
        double avg = static_cast<double>(sum) / count;

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Finished processing the text file - " << file_name
                  << std::endl;
        std::cout << std::endl;

        // REPORT SUMMARY
        const std::string REPORT_TITLE = "*** Report Summary ***";
        const int TABLE_LEN = 10;

        // overly complicated attempt to center title
        int title_offset = (TABLE_LEN * 2) - ((REPORT_TITLE.length()) / 2);

        for (int i = 0; i < title_offset; i++) {
            std::cout << " ";
        }
        std::cout << REPORT_TITLE;
        std::cout << std::endl;
        for (int i = 0; i < TABLE_LEN; i++) {
            std::cout << std::setw(4) << "====";
        }
        std::cout << std::endl;

        // formatting for floating point numbers
        std::cout << std::setprecision(2) << std::showpoint << std::fixed;

        // widths for table columns
        const int L_COL_WIDTH = 34;
        const int R_COL_WIDTH = 6;

        // Print count
        std::cout << std::left << std::setw(L_COL_WIDTH)
                  << "The total count of numbers found:";
        std::cout << std::right << std::setw(R_COL_WIDTH) << count << std::endl;
        // Print sum
        std::cout << std::left << std::setw(L_COL_WIDTH)
                  << "The sum of the numbers:";
        std::cout << std::right << std::setw(R_COL_WIDTH) << sum << std::endl;
        // Print average
        std::cout << std::left << std::setw(L_COL_WIDTH)
                  << "The sum of the numbers:";
        std::cout << std::right << std::setw(R_COL_WIDTH) << avg << std::endl;
        // Print max
        std::cout << std::left << std::setw(L_COL_WIDTH)
                  << "The greatest number:";
        std::cout << std::right << std::setw(R_COL_WIDTH) << max << std::endl;
        // Print min
        std::cout << std::left << std::setw(L_COL_WIDTH)
                  << "The smallest number:";
        std::cout << std::right << std::setw(R_COL_WIDTH) << min << std::endl;
    } else {
        std::cout << "Error opening the file - " << file_name << std::endl;
    }

    return 0;
}
