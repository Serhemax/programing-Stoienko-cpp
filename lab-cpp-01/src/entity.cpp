#include "entity.h"
using namespace std;

Bird::Bird(bool is_ringed_in, string type_in, int age_in, int area_in, int height_in,
    int feeders_in, bool has_nest_int, string gender_in) {
    this->is_ringed = is_ringed_in; // ×è îêîëüöüîâàíà ïòàõà (òàê, í³)
    this->type = type_in;    // Íàçâà âèäó
    this->age = age_in;       // Â³ê ïòàõà, ì³ñÿö³â
    this->area = area_in;  // Ïëîùà ó êâ. ñì
    this->height = height_in;   // Âèñîòà ó ñì
    this->feeders = feeders_in;  // Ê³ëüê³ñòü ãîä³âíèöü
    this->has_nest = has_nest_int; // Íàÿâí³ñòü ãí³çäà (òàê, í³)
    this->gender = gender_in;    // Òèï äîì³âêè ïòàõà
}

Bird::Bird() {
    this->is_ringed = true; // ×è îêîëüöüîâàíà ïòàõà (òàê, í³)
    this->type = "soroka";    // Íàçâà âèäó
    this->age = 8;       // Â³ê ïòàõà, ì³ñÿö³â
    this->area = 10;  // Ïëîùà ó êâ. ñì
    this->height = 12;   // Âèñîòà ó ñì
    this->feeders = 2;  // Ê³ëüê³ñòü ãîä³âíèöü
    this->has_nest = true; // Íàÿâí³ñòü ãí³çäà (òàê, í³)
    this->gender = "woman";    // Òèï äîì³âêè ïòàõà
}

Bird::Bird(const Bird& copy) {
    this->is_ringed = copy.is_ringed; // ×è îêîëüöüîâàíà ïòàõà (òàê, í³)
    this->type = copy.type;    // Íàçâà âèäó
    this->age = copy.age;       // Â³ê ïòàõà, ì³ñÿö³â
    this->area = copy.area;  // Ïëîùà ó êâ. ñì
    this->height = copy.height;   // Âèñîòà ó ñì
    this->feeders = copy.feeders;  // Ê³ëüê³ñòü ãîä³âíèöü
    this->has_nest = copy.has_nest; // Íàÿâí³ñòü ãí³çäà (òàê, í³)
    this->gender = copy.gender;    // Òèï äîì³âêè ïòàõà
}

// Ôóíêö³ÿ äëÿ âèâåäåííÿ ìàñèâó ïòàõ³â íà åêğàí
void Bird::print_bird() const{
    printf(" Is ringed: %d\n", is_ringed);
    printf(" Species name: %s\n", type.c_str());
    printf(" Age: %d months\n", age);
    printf(" Nest:\n");
    printf(" Area: %d sq. cm\n", area);
    printf(" Height: %d cm\n", height);
    printf(" Number of feeders: %d\n", feeders);
    printf(" Nest availability: %d\n", has_nest);
    printf(" Gender: %s\n", gender.c_str());
    printf("\n");
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

