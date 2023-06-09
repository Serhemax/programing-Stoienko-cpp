#ifndef ENTITY_H
#define ENTITY_H
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <sstream>
using std::endl;

class Bird {
private:
        bool is_ringed; // Чи окольцьована птаха (так, ні)
        std::string type;    // Назва виду
        int age;       // Вік птаха, місяців
        
        int area;     // Площа у кв. см
        int height;   // Висота у см
        int feeders;  // Кількість годівниць
        bool has_nest; // Наявність гнізда (так, ні)
               // Тип домівки птаха
        std::string gender;
public:

    Bird();

    Bird(bool is_ringed_in, std::string type_in, int age_in, int area_in, int height_in,
        int feeders_in, bool has_nest_int, std::string gender);

    Bird(const Bird& copy);

    static Bird createBirdFromInputString(const std::string& line);

     bool getIsringed() const;
    void setIsringed(bool isringed_);

    std::string getType() const;
    void setType(std::string type_);

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

    std::string getGender() const;
    void setGender(std::string gender_);

    /// Функція для виведення масиву птахів на екран
    std::string toString() const;

    Bird& operator=(const Bird& other);
    bool operator==(const Bird& other) const;
    bool operator!=(const Bird& other) const;

    friend std::istream& operator>>(std::istream& is, Bird& bird);
    friend std::ostream& operator<<(std::ostream& os, const Bird& bird);

    ~Bird() {};
};
#endif
