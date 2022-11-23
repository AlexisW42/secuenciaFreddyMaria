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
        int acumulador = 1;
        vector<int> longitudes;
        for (long unsigned int i = 0; i < line.size(); i++) {
            if (i + 1 < line.size()) {
                cout << " i: " << i << " "
                     << "\"contador: \"" << acumulador << "." << endl;
                if (i % 2 == 0) {
                    if (line[i] > line[i + 1]) {
                        acumulador++;
                    } else {
                        longitudes.push_back(acumulador);
                        acumulador = 0;
                    }
                }
                if (i % 2 != 0) {
                    if (line[i] < line[i + 1]) {
                        acumulador++;
                    } else {
                        longitudes.push_back(acumulador);
                        acumulador = 0;
                    }
                }
            } else {
                if (acumulador != 1) {
                    longitudes.push_back(acumulador);
                    acumulador = 1;
                }

                for (long unsigned int j = 0; j < longitudes.size(); j++) {
                    cout << "'" << longitudes[j] << "' ";
                }
                break;
            }
        }

        cout << endl;
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