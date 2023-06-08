#include <string>
#include <stdio.h>
#include <stdlib.h>

#ifndef ENTITY_H
#define ENTITY_H
using namespace std;

class Bird {
private:
        bool is_ringed;
        string type;  
        int age;    
        
        int area;    
        int height;   
        int feeders;  
        bool has_nest; 

        string gender;
public:

    Bird();

    Bird(bool is_ringed_in, string type_in, int age_in, int area_in, int height_in,
        int feeders_in, bool has_nest_int, string gender);

    Bird(const Bird& copy);

    ~Bird() {};

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

    void print_bird() const;

};
#endif
