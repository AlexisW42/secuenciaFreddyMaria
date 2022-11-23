#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> readNextLine(ifstream &file);
vector<int> readItems(ifstream &file, int numberOfItems);
int lookLargestNumber(vector<int> array);

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
        int count = 1;
        vector<int> longitudes;
        for (long unsigned int i = 0; i < line.size(); i++) {
            if (i + 1 < line.size()) {
                // cout << " i: " << i << " "
                //      << "\"count: \"" << count << "." << endl;
                if (i % 2 == 0) {
                    if (line[i] > line[i + 1]) {
                        count++;
                    } else {
                        longitudes.push_back(count);
                        count = 0;
                    }
                }
                if (i % 2 != 0) {
                    if (line[i] < line[i + 1]) {
                        count++;
                    } else {
                        longitudes.push_back(count);
                        count = 0;
                    }
                }
            } else {
                if (count != 1) {
                    longitudes.push_back(count);
                    count = 1;
                }
                // for (long unsigned int j = 0; j < longitudes.size(); j++) {
                cout << lookLargestNumber(longitudes) << endl;
                // }
                break;
            }
        }
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

int lookLargestNumber(vector<int> array) {
    int largest = 0;

    for (long unsigned int i = 0; i < array.size(); i++) {
        if (array[i] > largest)
            largest = array[i];
    }
    return largest;
}