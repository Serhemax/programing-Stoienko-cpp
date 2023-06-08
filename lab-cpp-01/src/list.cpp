#include "list.h"
#include "entity.h"
 
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

Bird& List::getBird(int idx) const{
    return *birds[idx];
}

void List::print_birds() const{
    for (int i = 0; i < num_birds; i++)
    {
        printf("Bird %d:\n", i + 1);
        printf(" Is ringed: %d\n", birds[i]->getIsringed());
        printf(" Type: %s\n", birds[i]->getType().c_str());
        printf(" Age: %d months\n", birds[i]->getAge());
        printf(" Nest:\n");
        printf(" Area: %d sq. cm\n", birds[i]->getArea());
        printf(" Height: %d cm\n", birds[i]->getHeight());
        printf(" Number of feeders: %d\n", birds[i]->getFeeders());
        printf(" Has nest: %d\n", birds[i]->getHasnest());
        printf(" Gender: %s\n", birds[i]->getGender().c_str());
        printf("\n");
    }
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
