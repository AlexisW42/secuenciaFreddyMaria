#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream file("secuencias.txt");
    string text;
    int numbersOfLines;

    if (file.fail()) {
        cout << "Error!" << endl;
        return 0;
    }
    getline(file, text);
    numbersOfLines = stoi(text);
    cout << numbersOfLines << endl;

    for (int i = 0; i < numbersOfLines; i++) {
        getline(file, text);
        cout << "linea leida: " << text << endl;
    }

    file.close();

    return 0;
}
