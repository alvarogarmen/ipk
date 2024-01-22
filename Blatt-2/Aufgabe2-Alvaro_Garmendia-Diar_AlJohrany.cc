#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

template<typename INT>
void printVector(std::vector<INT> vector) {

    if (vector.size() == 0) {
        std::cout << "[]" << std::endl;
    } else if (vector.size() == 1) {
        std::cout << "[" << vector[0] << "]" << std::endl;
    } else {
        std::cout << "[";
        for (int i = 0; i < vector.size() - 1; i++) {
            std::cout << vector[i] << ",";
        }
        std::cout << vector[vector.size() - 1] << "]" << std::endl;
    }
}

template<typename INT>
double getMedian(std::vector<INT> vector) {

    size_t vectorSize = vector.size();

    if (vectorSize == 0) {
        std::cout << "My tutor in Christ, this is empty! Imma give out a 0 tho: ";
        return 0;
    }

    if (vectorSize % 2 == 1) {
        std::sort(vector.begin(), vector.end());
        return vector[(vectorSize - 1) / 2];
    }

    std::sort(vector.begin(), vector.end());
    double median = vector[vectorSize / 2] + vector[(vectorSize - 1) / 2];
    return median / 2;
}

template<typename INT>
void writeSin(std::vector<INT> &vector) {

    for (size_t i = 0; i < vector.size(); i++) {
        vector[i] = std::sin(vector[i]);
    }

}

template<typename INT>
std::vector<INT> sums(std::vector<std::vector<INT>> &vector) {
    std::vector<INT> sumVector(vector.size(), 0);
    for (size_t i = 0; i < vector.size(); i++) {

        for (size_t j = 0; j < vector[i].size(); j++) {
            sumVector[i] += vector[i][j];
        }

    }

    return sumVector;
}

int main() {
    std::vector<double> testVector = {3, 2, 5, 1.57, -3};
    printVector(testVector);
    std::cout << "Median: " << getMedian(testVector) << std::endl;
    testVector.push_back(1);
    printVector(testVector);
    std::cout << "Median: " << getMedian(testVector) << std::endl;
    std::vector<double> testEmpty;
    std::cout << "Empty median: " << getMedian(testEmpty) << std::endl;

    writeSin(testVector);
    std::cout << "Write sinus: ";
    printVector(testVector);
    writeSin(testEmpty);
    std::cout << "Write sinus with empty vector: ";
    printVector(testEmpty);

    std::vector<std::vector<double>> emptySumTest;
    std::cout << "Empty sums test: ";
    printVector(sums(emptySumTest));
    std::vector<std::vector<double>> testSum;
    testSum.push_back({1});
    testSum.push_back({2.0, -3.0, 1.5});
    testSum.push_back({}); //Falls leer, Eintrag wird 0 sein
    std::cout << "Sums test with actual vector of vectors. 0 if subvector is empty: " << std::endl;
    printVector(sums(testSum));


    return 0;
}