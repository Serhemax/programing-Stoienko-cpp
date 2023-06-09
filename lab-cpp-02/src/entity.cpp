#include "entity.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Bird::Bird(bool is_ringed_in, string type_in, int age_in, int area_in, int height_in,
    int feeders_in, bool has_nest_int, string gender_in) {
    this->is_ringed = is_ringed_in; // Чи окольцьована птаха (так, ні)
    this->type = type_in;    // Назва виду
    this->age = age_in;       // Вік птаха, місяців
    this->area = area_in;  // Площа у кв. см
    this->height = height_in;   // Висота у см
    this->feeders = feeders_in;  // Кількість годівниць
    this->has_nest = has_nest_int; // Наявність гнізда (так, ні)
    this->gender = gender_in;    // Тип домівки птаха
}

Bird::Bird() {
    this->is_ringed = true; // Чи окольцьована птаха (так, ні)
    this->type = "soroka";    // Назва виду
    this->age = 8;       // Вік птаха, місяців
    this->area = 10;  // Площа у кв. см
    this->height = 12;   // Висота у см
    this->feeders = 2;  // Кількість годівниць
    this->has_nest = true; // Наявність гнізда (так, ні)
    this->gender = "woman";    // Тип домівки птаха
}

Bird::Bird(const Bird& copy) {
    this->is_ringed = copy.is_ringed; // Чи окольцьована птаха (так, ні)
    this->type = copy.type;    // Назва виду
    this->age = copy.age;       // Вік птаха, місяців
    this->area = copy.area;  // Площа у кв. см
    this->height = copy.height;   // Висота у см
    this->feeders = copy.feeders;  // Кількість годівниць
    this->has_nest = copy.has_nest; // Наявність гнізда (так, ні)
    this->gender = copy.gender;    // Тип домівки птаха
}

Bird Bird::createBirdFromInputString(const string& line) {
    Bird bird;
    istringstream iss(line);
    string token;

    getline(iss, token, ',');
    bird.setIsringed(stoi(token));

    getline(iss, token, ',');
    bird.setType(token);

    getline(iss, token, ',');
    bird.setAge(stoi(token));

    getline(iss, token, ',');
    bird.setArea(stoi(token));

    getline(iss, token, ',');
    bird.setHeight(stoi(token));

    getline(iss, token, ',');
    bird.setFeeders(stoi(token));

    getline(iss, token, ',');
    bird.setHasnest(stoi(token));

    getline(iss, token, '\n');
    bird.setGender(token);

    return bird;
}

string Bird::toString() {
    stringstream ss;
    ss << " Is ringed: " << is_ringed << endl;
    ss << " Type: " << type << endl;
    ss << " Age: " << age << " months" << endl;
    ss << " Nest:" << endl;
    ss << "  Area: " << area << " sq.cm" << endl;  
    ss << "  Height: " << height << " cm" << endl;  
    ss << "  Number of feeders: " << feeders << endl;
    ss << "  Has nest: " << has_nest << endl;
    ss << "  Gender: " << gender << "\n" << endl;

    return ss.str();  
}

bool Bird::getIsringed() const
{
    return is_ringed;
}

void Bird::setIsringed(bool isringed_)
{
    is_ringed = isringed_;
}

string Bird::getType() const
{
    return type;
}

void Bird::setType(string type_)
{
    this->type = type_;
}

int Bird::getAge() const
{
    return age;
}

void Bird::setAge(int age_)
{
    this->age = age_;
}

int Bird::getArea() const
{
    return area;
}

void Bird::setArea(int area_)
{
    this->area = area_;
}

int Bird::getHeight() const
{
    return height;
}

void Bird::setHeight(int height_)
{
    this->height = height_;
}

int Bird::getFeeders() const
{
    return feeders;
}

void Bird::setFeeders(int feeders_)
{
    this->feeders = feeders_;
}

bool Bird::getHasnest() const
{
    return has_nest;
}

void Bird::setHasnest(bool hasnest_)
{
    has_nest = hasnest_;
}

string Bird::getGender() const
{
    return gender;
}

void Bird::setGender(string gender_)
{
    this->gender = gender_;
}
