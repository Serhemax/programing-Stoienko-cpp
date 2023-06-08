#include <iostream>
#include <cmath>
#include "entity.h"
#include "list.h"
using namespace std;

int main()
{
    Bird a;
    a.print_bird();
    Bird b (false, "vorobej", 5, 20, 10, 3, false, "man");

    List birds;
    birds.addBird(a);
    birds.addBird(b);
    birds.addBird(Bird());
    birds.addBird(Bird());

    printf("Ratio of Women: %f ", birds.get_gender_ratio());


    return 0;
}
