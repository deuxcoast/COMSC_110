#include <iomanip>
#include <ios>
#include <iostream>
struct AdRevenue {
    int view_count;
    double engagement_prcnt;
    double avg_earning_per_ad;
};

void PrintValues(AdRevenue ar) {
    using namespace std;

    double total{ar.avg_earning_per_ad * ar.engagement_prcnt * ar.view_count};

    cout << setprecision(2) << fixed;

    cout << setw(20) << left << "View count: " << setw(10) << ar.view_count
         << endl;
    cout << setw(20) << left << "Engagement (%): " << setw(10)
         << ar.engagement_prcnt << endl;
    cout << setw(20) << left << "Earning Per Ad: " << setw(1) << "$" << setw(9)
         << ar.avg_earning_per_ad << endl;
    cout << setw(20) << left << "Total Earnings: " << setw(1) << "$" << setw(9)
         << total << endl;
}

int main() {
    AdRevenue ad_rev{500, 0.35, 12.77};
    PrintValues(ad_rev);
}
