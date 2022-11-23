#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> readNextLine(ifstream &file);
vector<int> readItems(ifstream &file, int numberOfItems);

int main() {
    ifstream file("secuencias.txt");
    int numbersOfLines;
    vector<int> line;

    if (file.fail()) {
        cout << "Error en archivo!" << endl;
        return 0;
    }

    file >> numbersOfLines;

    for (int i = 0; i < numbersOfLines; i++) {
        line = readNextLine(file);
    }

    file.close();

    return 0;
}

vector<int> readNextLine(ifstream &file) {
    vector<int> line;
    int numberOfItems;
    file >> numberOfItems;
    line = readItems(file, numberOfItems);
    return line;
}

vector<int> readItems(ifstream &file, int numberOfItems) {
    vector<int> line;
    for (int i = 0; i < numberOfItems; i++) {
        int number;
        file >> number;
        line.push_back(number);
    }
    return line;
}