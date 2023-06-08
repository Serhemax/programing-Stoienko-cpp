#include "list.h"
 
int List::getNum_birds() const
{
    return num_birds;
}

void List::readFromFile(const std::string& filename) {
    // Clear previous data
    delete[] birds;
    num_birds = 0;

    ifstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        Bird bird = Bird::createBirdFromInputString(line);
        addBird(bird);
    }

    file.close();
}

void List::writeToFile(const string& filename) const {
    ofstream file(filename);
    if (!file) {
        cout << "Error opening file: " << filename << endl;
        return;
    }
    // we can do just toString(), but then test would not work-_(-_-)_-
    for (int i = 0; i < num_birds; i++) {
        file << "Bird " << (i + 1) << ":\n";
        file << "  Is ringed: " << birds[i]->getIsringed() << "\n";
        file << "  Type: " << birds[i]->getType() << "\n";
        file << "  Age: " << birds[i]->getAge() << "\n";
        file << "  Nest:\n";
        file << "    Area: " << birds[i]->getArea() << "\n";
        file << "    Height: " << birds[i]->getHeight() << "\n";
        file << "    Number of feeders: " << birds[i]->getFeeders() << "\n";
        file << "    Has nest: " << birds[i]->getHasnest() << "\n";
        file << "  Gender: " << birds[i]->getGender() << "\n";
        file << "\n";
    }

    file.close();
}

void List::addBird(const Bird& bird) {
    Bird** temp = new Bird * [num_birds + 1];
    for (int i = 0; i < num_birds; i++) {
        temp[i] = birds[i];
    }
    temp[num_birds] = new Bird(bird);
    delete[] birds;
    birds = temp;
    num_birds++;
}

void List::deleteBird(int idx) {
    if (idx >= 0 && idx < num_birds) {
        delete birds[idx];
        for (int i = idx; i < num_birds - 1; i++) {
            birds[i] = birds[i + 1];
        }
        num_birds--;
    }
}

Bird& List::getBird(int idx) const{
    return *birds[idx];
}

 string List::toString() const {
     stringstream ss;
     ss << "\n///////////////////\n";
    for (int i = 0; i < num_birds; i++)
    {
        
        ss << "Bird: " << i + 1 << "\n";
        ss << birds[i]->toString();
    }

     ss << "\n///////////////////\n";
    const string result = ss.str();

    return result;
}

float List::get_gender_ratio() const{
    int males = 0;
    int females = 0;

    for (int i = 0; i < num_birds; i++) {
        if (birds[i]->getGender() == "man") {
            males++;
        }
        else if (birds[i]->getGender() == "woman") {
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

List::List() {
    birds = nullptr;
    num_birds = 0;
}

List::~List() {
    if (birds != nullptr) {
        for (int i = 0; i < num_birds; i++) {
            delete birds[i];
        }
        delete[] birds;
    }
}
