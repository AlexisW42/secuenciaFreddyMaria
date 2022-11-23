#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void readLines(ifstream &file, int numbersOfLines);
vector<int> readItems(ifstream &file, int numberOfItems);

int main() {
    ifstream file("secuencias.txt");
    string text;
    int numbersOfLines;

    if (file.fail()) {
        cout << "Error!" << endl;
        return 0;
    }
    file >> numbersOfLines;
    cout << "numbersOfLines " << numbersOfLines << endl;

    readLines(file, numbersOfLines);

    file.close();

    return 0;
}

void readLines(ifstream &file, int numbersOfLines) {
    for (int i = 0; i < numbersOfLines; i++) {
        int numberOfItems;
        vector<int> line;
        file >> numberOfItems;
        cout << numberOfItems << " ";
        line = readItems(file, numberOfItems);
        cout << endl;
        
    }
}

vector<int> readItems(ifstream &file, int numberOfItems) {
    vector<int> line;
    for (int i = 0; i < numberOfItems; i++) {
        int number;
        file >> number;
        line.push_back(number);
        cout << number << " ";
    }
    return line;
}