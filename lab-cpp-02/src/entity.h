#ifndef ENTITY_H
#define ENTITY_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Bird {
private:
        bool is_ringed; // Чи окольцьована птаха (так, ні)
        string type;    // Назва виду
        int age;       // Вік птаха, місяців
        
        int area;     // Площа у кв. см
        int height;   // Висота у см
        int feeders;  // Кількість годівниць
        bool has_nest; // Наявність гнізда (так, ні)
               // Тип домівки птаха
        string gender;
public:

    Bird();

    Bird(bool is_ringed_in, string type_in, int age_in, int area_in, int height_in,
        int feeders_in, bool has_nest_int, string gender);

    Bird(const Bird& copy);

    static Bird createBirdFromInputString(const string& line);

     bool getIsringed() const;
    void setIsringed(bool isringed_);

    string getType() const;
    void setType(string type_);

    int getAge() const;
    void setAge(int age_);

    int getArea() const;
    void setArea(int area_);

    int getHeight() const;
    void setHeight(int height_);

    int getFeeders() const;
    void setFeeders(int feeders_);

    bool getHasnest() const;
    void setHasnest(bool hasnest_);

    string getGender() const;
    void setGender(string gender_);

    /// Функція для виведення масиву птахів на екран
    string toString();

    ~Bird() {};
};
#endif
