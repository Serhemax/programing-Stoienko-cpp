#include "entity.h"
using namespace std;

Bird::Bird(bool is_ringed_in, string type_in, int age_in, int area_in, int height_in,
    int feeders_in, bool has_nest_int, string gender_in) {
    this->is_ringed = is_ringed_in; // �� ������������ ����� (���, �)
    this->type = type_in;    // ����� ����
    this->age = age_in;       // ³� �����, ������
    this->area = area_in;  // ����� � ��. ��
    this->height = height_in;   // ������ � ��
    this->feeders = feeders_in;  // ʳ������ ��������
    this->has_nest = has_nest_int; // �������� ����� (���, �)
    this->gender = gender_in;    // ��� ������ �����
}

Bird::Bird() {
    this->is_ringed = true; // �� ������������ ����� (���, �)
    this->type = "soroka";    // ����� ����
    this->age = 8;       // ³� �����, ������
    this->area = 10;  // ����� � ��. ��
    this->height = 12;   // ������ � ��
    this->feeders = 2;  // ʳ������ ��������
    this->has_nest = true; // �������� ����� (���, �)
    this->gender = "woman";    // ��� ������ �����
}

Bird::Bird(const Bird& copy) {
    this->is_ringed = copy.is_ringed; // �� ������������ ����� (���, �)
    this->type = copy.type;    // ����� ����
    this->age = copy.age;       // ³� �����, ������
    this->area = copy.area;  // ����� � ��. ��
    this->height = copy.height;   // ������ � ��
    this->feeders = copy.feeders;  // ʳ������ ��������
    this->has_nest = copy.has_nest; // �������� ����� (���, �)
    this->gender = copy.gender;    // ��� ������ �����
}

// ������� ��� ��������� ������ ������ �� �����
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

