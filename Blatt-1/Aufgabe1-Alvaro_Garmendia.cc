// Blatt 1 : Aufgabe 1
// Alvaro Garmendia Navarro
#include <iostream>

bool isEven(unsigned int number) {
    if (number % 2 == 0) {
        return true;
    }
    return false;
}

void collanz(unsigned int number) {
    std::cout << "Collanz starts" << std::endl;
    if (((number != 0) + (number != 1)) == 1) {
        std::cout << number << std::endl;
    }
    while (((number != 0) + (number != 1)) != 1) {
        std::cout << number << std::endl;
        if (isEven(number)) {
            number = number / 2;
        } else {
            number = number * 3 + 1;
        }
    }

}

int main() {
    std::cout << "Give number" << std::endl;
    unsigned int number;
    std::cin >> number;
    collanz(number);
    return 0;
}
