#include "list.h"
#include <limits>
 
int List::getNum_birds() const
{
    return num_birds;
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

Bird& List::operator[](int index) const {
    return *birds[index];
}

std::string List::toString() const {
    std::stringstream ss;
     ss << "\n///////////////////\n";
    for (int i = 0; i < num_birds; i++)
    {
        
        ss << "Bird: " << i + 1 << "\n";
        ss << birds[i]->toString();
    }

     ss << "\n///////////////////\n";
    const std::string result = ss.str();

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


std::istream& operator>>(std::istream& is, List& list) {
    // Очистити попередні дані списку
    for (int i = 0; i < list.num_birds; i++) {
        delete list.birds[i];
    }
    delete[] list.birds;
    list.birds = nullptr;
    list.num_birds = 0;

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
            Bird* newBird = new Bird(bird);

            // Розширення масиву
            Bird** temp = new Bird * [list.num_birds + 1];
            for (int j = 0; j < list.num_birds; j++) {
                temp[j] = list.birds[j];
            }
            temp[list.num_birds] = newBird;
            delete[] list.birds;
            list.birds = temp;
            list.num_birds++;
        }
    }

    return is;
}

Bird& List::getBird(int idx) const{
    return *birds[idx];
}


std::ostream& operator<<(std::ostream& os, const List& list) {
    for (int i = 0; i < list.num_birds; i++) {
    	os <<  "Bird " << (i + 1) << ":\n";
        os << list.birds[i]->toString() << "\n";
    }
    return os;
}

std::ifstream& operator>>(std::ifstream& ifs, List& list) {
    // Очищення попередніх даних списку
    for (int i = 0; i < list.num_birds; i++) {
        delete list.birds[i];
    }
    delete[] list.birds;
    list.birds = nullptr;
    list.num_birds = 0;

    // Зчитування кількості птахів
    int numBirds;
    ifs >> numBirds;
    ifs.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Зчитування даних птахів з файлу
    std::string line;
    for (int i = 0; i < numBirds; i++) {
        if (!getline(ifs, line)) {
            break;
        }
        Bird bird = Bird::createBirdFromInputString(line);
        Bird* newBird = new Bird(bird);

        // Розширення масиву
        Bird** temp = new Bird * [list.num_birds + 1];
        for (int j = 0; j < list.num_birds; j++) {
            temp[j] = list.birds[j];
        }
        temp[list.num_birds] = newBird;
        delete[] list.birds;
        list.birds = temp;
        list.num_birds++;
    }

    return ifs;
}

std::ofstream& operator<<(std::ofstream& ofs, const List& list) {
    // Виведення даних птахів у файл
    for (int i = 0; i < list.num_birds; i++) {
        ofs << "Bird " << (i + 1) << ":\n";
        ofs << "  Is ringed: " << list.birds[i]->getIsringed() << "\n";
        ofs << "  Type: " << list.birds[i]->getType() << "\n";
        ofs << "  Age: " << list.birds[i]->getAge() << "\n";
        ofs << "  Nest:\n";
        ofs << "    Area: " << list.birds[i]->getArea() << "\n";
        ofs << "    Height: " << list.birds[i]->getHeight() << "\n";
        ofs << "    Number of feeders: " << list.birds[i]->getFeeders() << "\n";
        ofs << "    Has nest: " << list.birds[i]->getHasnest() << "\n";
        ofs << "  Gender: " << list.birds[i]->getGender() << "\n";
        ofs << "\n";
    }

    return ofs;
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
