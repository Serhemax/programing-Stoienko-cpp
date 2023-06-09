#include <iostream>
#include <cmath>
#include "entity.h"
#include "list.h"
#include <string>
#include <sstream>

int main()  
{
    Bird a;
    Bird b (false, "vorobej", 5, 20, 10, 3, false, "man");

    std::string line = "1, Sparrow, 3, 50, 10, 2, 1, man";
    
    Bird c = Bird::createBirdFromInputString(line);

    List birds;
    
    birds.addBird(a);
    birds.addBird(b);
    birds.addBird(c);
    birds.addBird(Bird());
    birds.addBird(Bird());
    
    std::cout << birds;
    
    Bird d = b;
    if(d == b){
    	std::cout << d;
    }

    std::ifstream inputFile("input.txt");
    if (inputFile) {
        inputFile >> birds;
        inputFile.close();
    }
    else {
        std::cout << "Error opening input file\n";
    }

    // Виведення у файл
    std::ofstream outputFile("output.txt");
    if (outputFile) {
        outputFile << birds;
        outputFile.close();
    }
    else {
        std::cout << "Error opening output file\n";
    }

    std::cout << birds;

    return 0;
}
