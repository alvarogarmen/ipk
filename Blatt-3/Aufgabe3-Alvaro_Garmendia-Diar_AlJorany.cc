#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>

std::vector<std::vector<bool>> readFieldFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<bool>> field;

    if (file.is_open()) {
        std::string line;
        std::vector<bool> row;

        while (std::getline(file, line)) {
            row.clear();
            for (char c : line) {
                if (c == 'O') { //This is a big o, not a "zero"
                    row.push_back(true); // Alive cell
                } else if (c == ' ') {
                    row.push_back(false); // Dead cell
                } else {
                    return {}; // Invalid character in file
                }
            }

            if (!field.empty() && row.size() != field[0].size()) {
                return {}; // Rows of different lengths
            }

            field.push_back(row);
        }
        file.close();
    }

    return field;
}

bool isInside(int x, int y, int width, int height) {
    return x >= 0 && x < width && y >= 0 && y < height;
}

int countLiveNeighbors(const std::vector<std::vector<bool>>& field, int x, int y) {
    int count = 0;
    int width = field[0].size();
    int height = field.size();
    int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int i = 0; i < 8; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isInside(newX, newY, width, height) && field[newY][newX]) {
            count++;
        }
    }

    return count;
}

void updateCell(std::vector<std::vector<bool>>& field, int x, int y) {
    int liveNeighbors = countLiveNeighbors(field, x, y);

    if (field[y][x] && (liveNeighbors < 2 || liveNeighbors > 3)) {
        field[y][x] = false; // Cell dies
    } else if (!field[y][x] && liveNeighbors == 3) {
        field[y][x] = true; // Cell becomes alive
    }
}

void updateField(std::vector<std::vector<bool>>& field) {
    int width = field[0].size();
    int height = field.size();
    std::vector<std::vector<bool>> newField(height, std::vector<bool>(width, false));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            updateCell(field, x, y);
        }
    }

    field = newField;
}

void printField(const std::vector<std::vector<bool>>& field) {
    for (const auto& row : field) {
        for (bool cell : row) {
            std::cout << (cell ? 'O' : ' ') << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    std::string filename = "field.txt";
    std::vector<std::vector<bool>> field = readFieldFromFile(filename);

    if (field.empty()) {
        std::cout << "Invalid field file or format!" << std::endl;
        return 1;
    }

    while (true) {      //I don´t know when it has to end
        std::cout << "\x1B[2J\x1B[H";
        printField(field);
        updateField(field);
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Adjust delay here
    }

    return 0;
}
