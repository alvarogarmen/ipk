#include "temperature.cc"
#include <iostream>

int main() {
    int temp;
    char type;

    std::cout << "Enter temperature type (C for Celsius, K for Kelvin and F for Fahrenheit)" << std::endl;
    std::cin >> type;
    std::cout << "Enter temperature value" << std::endl;
    std::cin >> temp;

    Temperature temperature = Temperature();
    temperature.setTemp(temp, type);

    std::cout << "Kelvin: " << temperature.getKelvin() << " K" << std::endl;
    std::cout << "Celsius: " << temperature.getCelsius() << " °C" << std::endl;
    std::cout << "Fahrenheit: " << temperature.getFahrenheit() << " °F" << std::endl;
}