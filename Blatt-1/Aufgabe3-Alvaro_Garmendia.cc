// Blatt 1 : Aufgabe 3
// Alvaro Garmendia Navarro

#include <iostream>

unsigned int fib(unsigned int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

unsigned int fibIter(unsigned int n) {
    if (n <= 1) {
        return n;
    }

    unsigned int a = 0;
    unsigned int b = 1;
    unsigned int result = 0;

    for (unsigned int i = 2; i <= n; ++i) {
        result = a + b;
        a = b;
        b = result;
    }

    return result;
}

int main() {
    unsigned int n;
    std::cout << "Input n: " << std::endl;
    std::cin >> n;
    std::cout << "Die " << n << "te Fibonacci Zahl wird berechnet" << std::endl;
    std::cout << "Rekursiv: " << fib(n) << std::endl;
    std::cout << "Iterativ: " << fibIter(n) << std::endl;
    //As a side note, rekursiv ist deutlich langsamer bei große Eingaben (e.g. ab 40)
    return 0;
}