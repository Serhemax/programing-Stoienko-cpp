#include <iostream>
#include <cmath>
#include "entity.h"
#include "list.h"
#include <string>
#include <sstream>

using namespace std;

Bird stringBird() {
    int is_ringed;
    string type;
    int age;
    int area;
    int height;
    int feeders;
    int has_nest;
    string gender;

    cout << "\n";
    cout << " Is ringed (0 - no, 1 - yes): ";
    cin >> is_ringed;
    cout << "\n";
    cin.ignore();

    cout << " Type: ";
    getline(cin, type);
    cout << "\n";
    cout << " Age: ";
    cin >> age;
    cout << "\n";
    cin.ignore();

    cout << " Nest:\n";
    cout << "  Area: ";
    cin >> area;
    cout << "\n";
    cout << "  Height: ";
    cin >> height;
    cout << "\n";
    cout << "  Number of feeders: ";
    cin >> feeders;
    cout << "\n";
    cout << "  Has nest (0 - no, 1 - yes): ";
    cin >> has_nest;
    cout << "\n";
    cin.ignore();

    cout << "  Gender: ";
    getline(cin, gender);
    cout << "\n";

    return Bird(is_ringed, type, age, area, height, feeders, has_nest, gender);
}

int main()
{
    Bird a;
    Bird b (false, "vorobej", 5, 20, 10, 3, false, "man");

    string line = "1, Sparrow, 3, 50, 10, 2, 1, man";
    
    Bird c = Bird::createBirdFromInputString(line);

    List birds;
    
    birds.addBird(a);
    birds.addBird(b);
    birds.addBird(c);
    birds.addBird(Bird());
    birds.addBird(Bird());

    cout << birds.toString();

    return 0;
}
