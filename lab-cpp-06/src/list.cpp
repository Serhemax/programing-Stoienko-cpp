#include "list.h"
#include <fstream> 
#include <limits>

long unsigned int List::getNum_birds() const {
    return birds.size(); 
}

std::vector<Bird> List::getBirds() const
{
    return birds;
}

const Bird& List::getBird(int idx) const
{
    return birds.at(idx);
}

void List::addBird(const Bird& bird) {
    birds.push_back(bird); 
}

void List::deleteBird(long unsigned int idx) {
    if (idx < birds.size()) {
        birds.erase(birds.begin() + idx); 
    }
}

float List::get_gender_ratio() const {
    int males = 0;
    int females = 0;

    for (const Bird& bird : birds) {
        if (bird.getGender() == "man") {
            males++;
        }
        else if (bird.getGender() == "woman") {
            females++;
        }
    }

    if (males + females > 0) {
        return static_cast<float>(females) / static_cast<float>(males + females) * 100.0f;
    }
    else {
        return 0.0f;
    }
}

float List::getAverageAgeOfNonRingedBirds() const {
    int numNonRingedBirds = 0;
    int totalAge = 0;

    for (const Bird& bird : birds) {
        if (!bird.getIsringed()) {
            numNonRingedBirds++;
            totalAge += bird.getAge();
        }
    }

    if (numNonRingedBirds > 0) {
        return static_cast<float>(totalAge) / static_cast<float>(numNonRingedBirds);
    }
    else {
        return 0.0f;
    }
}

void List::sortBirds() {
    struct BirdComparator {
        bool operator()(const Bird& bird1, const Bird& bird2) {
            return bird1.getAge() < bird2.getAge();
        }
    };

    std::sort(birds.begin(), birds.end(), BirdComparator());
}

// Об'єднання двох класів-списків
void List::mergeLists(const List& otherList) {
    birds.insert(birds.end(), otherList.birds.begin(), otherList.birds.end());
}

void List::clearBirds() {
    birds.clear();
}

std::istream& operator>>(std::istream& is, List& list) {
    list.clearBirds(); // Clear the vector

    int num_birds;
    std::cout << "numBirds:\n";
    is >> num_birds;
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line;
    for (int i = 0; i < num_birds; i++) {
        std::cout << "Bird " << (i + 1) << ":\n";
        std::cout << "print: Is ringed, Type, Age, in Nest: Area, Height, Number of feeders, Has nest; Gender\n";
        if (getline(is, line)) {
            Bird bird = Bird::createBirdFromInputString(line);
            list.addBird(bird);
        }
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    int i = 1;
    for (const Bird& bird : list.getBirds()) {
        os << "Bird " << i++ << ":\n";
        os << bird.toString() << "\n";
    }
    return os;
}

std::ifstream& operator>>(std::ifstream& ifs, List& list) {
    list.clearBirds(); // Clear the vector

    int numBirds;
    ifs >> numBirds;
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string line;
    for (int i = 0; i < numBirds; i++) {
        if (!getline(ifs, line)) {
            break;
        }
        Bird bird = Bird::createBirdFromInputString(line);
        list.addBird(bird);
    }

    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, const List& list) {
    int i = 1;
    for (const Bird& bird : list.getBirds()) {
        ofs << "Bird " << i++ << ":\n";
        ofs << "  Is ringed: " << bird.getIsringed() << "\n";
        ofs << "  Type: " << bird.getType() << "\n";
        ofs << "  Age: " << bird.getAge() << "\n";
        ofs << "  Nest:\n";
        ofs << "    Area: " << bird.getArea() << "\n";
        ofs << "    Height: " << bird.getHeight() << "\n";
        ofs << "    Number of feeders: " << bird.getFeeders() << "\n";
        ofs << "    Has nest: " << bird.getHasnest() << "\n";
        ofs << "  Gender: " << bird.getGender() << "\n";
        ofs << "\n";
    }

    return ofs;
}


