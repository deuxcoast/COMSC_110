
#include "course.h"
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  const double PI = 3.14159;
  double volume, radius, height;
  cout << "This program will tell you the volume of\n";
  cout << "a cylinder-shaped fuel tank.\n";
  cout << "How tall is the tank?";
  cin >> height;
  cout << "What is the radius of the tank? ";
  cin >> radius;

  auto num = 120LL;

  int a = sizeof(bool);

  volume = PI * pow(radius, 2.0) * height;
  cout << "The volume of the tank is: " << volume;
}
