#include "temperature.hh"
#include <iostream>

Temperature::Temperature() {
    this->tempK = 0;
}

Temperature::Temperature(double temperK) {
    this->tempK = temperK;
}

double Temperature::getKelvin() {
    return this->tempK;
}

double Temperature::getCelsius() {
    return this->tempK - 273.15;
}

double Temperature::getFahrenheit() {
    return (this->tempK - 273.15) * 9.0 / 5.0 + 32;
}

void Temperature::setKelvin(double temp) {
    this->tempK = temp;
}

void Temperature::setCelsius(double temp) {
    this->tempK = temp + 273.15;
}

void Temperature::setFahrenheit(double temp) {
    this->tempK = (temp - 32) * 5.0 / 9.0 + 273.15;
}

void Temperature::add(Temperature &temp) {
    this->tempK += temp.tempK;
}

void Temperature::setTemp(double temp, char type) {
    if (type == 'C') {
        setCelsius(temp);
    } else if (type == 'F') {
        setFahrenheit(temp);
    } else if (type == 'K') {
        setKelvin(temp);
    }
    else {std::cerr<< "Invalid temperature type. 0 K will be used "<<std::endl;}
}
