#include <iostream>
using namespace std;

int main() {
    const int GAS_TANK = 20;
    const double IN_TOWN_MILEAGE = 23.5;
    const double HIGHWAY_MILEAGE = 28.9;
    double userTownMiles, userHighwayMiles;

    // TOWN MILEAGE
    cout << "*** Let's calculate the gas for in-town travel ***\n";

    // Input users total town travel distance
    cout << "Please enter the total miles for the in-town travel (miles): ";
    cin >> userTownMiles;
    cout << "The total miles for the in-town travel: " << userTownMiles
         << " mile(s)\n";

    // Calculate gas required for town trip, and remaining gas after travel
    float gasRequiredTown = userTownMiles / IN_TOWN_MILEAGE;
    float remainingGasTown = GAS_TANK - gasRequiredTown;

    // Display gas required and remaining gas
    cout << "Total gas for the in-town travel: " << gasRequiredTown
         << " gallon(s)\n";
    cout << "Total gas left after the trip: " << remainingGasTown
         << " gallon(s)\n\n";

    // HIGHWAY MILEAGE
    cout << "*** Let's calculate the gas for highway travel ***\n";

    // Input users' total highway travel distance
    cout << "Please enter the total miles for the highway travel (miles): ";
    cin >> userHighwayMiles;
    cout << "The total miles for the highway travel: " << userHighwayMiles
         << " mile(s)\n";

    // Calculate gas required for highway trip, and remaining gas after travel
    float gasRequiredHighway = userHighwayMiles / HIGHWAY_MILEAGE;
    float remainingGasHighway = GAS_TANK - gasRequiredHighway;

    cout << "Total gas for the highway travel: " << gasRequiredHighway
         << " gallon(s)\n";
    cout << "Total gas left after the trip: " << remainingGasHighway
         << " gallon(s)\n";

    return 0;
}
