#include <string>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>

std::string verstecken(std::string word) {
    int length = word.size();
    std::string hidden = "";            //Empty string
    for (int i = 0; i < length; i++) {
        hidden += '_';                    //Add _ for each letter in word
    }
    return hidden;
}

bool aufdecken(std::string &currentState, std::string word, char letter) {
    char lowerCaseLetter = std::tolower(letter);
    if (word[0] == letter or word[0] == std::toupper(letter) or
        word[0] == lowerCaseLetter) {     //check start of the word. Capital letter only comes up in the first letter
        currentState[0] = std::toupper(letter);
        for (int i = 1; i < word.size(); i++) {
            if (word[i] == lowerCaseLetter) {
                currentState[i] = lowerCaseLetter;
            }
        }
        return true;
    }
    if (word.find(lowerCaseLetter) == std::string::npos) {
        return false;
    }
    for (int i = 1; i <= word.size(); i++) {
        if (word[i] == lowerCaseLetter) {
            currentState[i] = lowerCaseLetter;
        }
    }
    return true;
}

bool istFertig(std::string currentState, std::string word) {     //the value of the bool expression is already enough
    return std::count(currentState.begin(), currentState.end(), '_') == std::count(word.begin(), word.end(), '_');
}

void showLives(int lives) {
    switch (lives) {
        case 5:
            std::cout << "Lives left: " << lives << std::endl;
            std::cout << " " << std::endl;
            break;
        case 4:
            std::cout << "Lives left: " << lives << std::endl;
            std::cout << " o" << std::endl;
            break;
        case 3:
            std::cout << "Lives left: " << lives << std::endl;
            std::cout << " o" << std::endl;
            std::cout << " |" << std::endl;
            break;
        case 2:
            std::cout << "Lives left: " << lives << std::endl;
            std::cout << " o" << std::endl;
            std::cout << " |" << std::endl;
            std::cout << " /\\ " << std::endl;
            break;
        case 1:
            std::cout << "Lives left: " << lives << std::endl;
            std::cout << " |---" << std::endl;
            std::cout << " o" << std::endl;
            std::cout << " |" << std::endl;
            std::cout << " /\\" << std::endl;
            break;
        case 0:
            std::cout << "RIP" << lives << std::endl;
            std::cout << " |---" << std::endl;
            std::cout << " o   |" << std::endl;
            std::cout << " |   |" << std::endl;
            std::cout << " /\\  |" << std::endl;
            break;

    }
}

void gameLoop(std::string word) {
    int lives = 5;
    char letter;
    std::string currentState = verstecken(word);
    while (true) {
        showLives(lives);
        std::cout << currentState << std::endl;
        std::cout << "Guess a letter: " << std::endl;
        std::cin >> letter;
        if (!aufdecken(currentState, word, letter)) {
            lives -= 1;
        }

        if (lives == 0) {
            std::cout << currentState << std::endl;
            std::cout << "Take the L" << std::endl;
            std::cout << "The word was: " << word << std::endl;
            break;
        } else if (istFertig(currentState, word)) {
            std::cout << "BIG W" << std::endl;
            break;
        }

    }
}

void readFiles(std::vector<std::string> &words) {
    std::ifstream file("blablabla.txt");
    if (file.is_open()) {
        words.clear(); // Clear the existing vector contents
        std::string word;
        while (file >> word) {
            words.push_back(word);
        }
        file.close();
    } else {
        std::cout << "Error 420: blablabla.txt not found" << std::endl;
    }
}

int main() {
    //Erkennung von ä, á funktioniert nicht tho. blablabla.txt ist hardcoded
    std::vector<std::string> words;
    readFiles(words); // Read words from the file into the vector

    if (words.empty()) {
        std::cout << "blablabla.txt is empty!" << std::endl;
        return 1;
    }

    std::srand(std::time(nullptr));
    int wordIndex = std::rand();
    gameLoop(words[wordIndex % words.size()]);

    return 0;

}