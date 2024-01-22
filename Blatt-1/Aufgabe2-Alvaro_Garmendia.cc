// Blatt 1 : Aufgabe 2
// Alvaro Garmendia Navarro
#include <iostream>
#include <cmath>

int main() {
    double p;
    double q;
    std::cout << "Beim Eingeben, verwende '.' statt ',' um Nachkommastellen einzugeben. '-' für negative Zahlen."
              << std::endl;
    std::cout << "Input p: " << std::endl;
    std::cin >> p;
    std::cout << "Input q: " << std::endl;
    std::cin >> q;
    double discriminate = pow(p / 2, 2) - q;
    if (discriminate < 0) {
        std::cerr << "Diskriminant negativ" << std::endl;
    } else if (discriminate == 0) {
        double solution = -p / 2;
        std::cout << solution << std::endl;
        return 0;
    } else {
        double x1 = -p / 2 + std::sqrt(discriminate);
        double x2 = -p / 2 - std::sqrt(discriminate);
        std::cout << "x1: " << x1 << std::endl;
        std::cout << "x2: " << x2 << std::endl;
        return 0;
    }

}