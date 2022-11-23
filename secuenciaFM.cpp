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
    file >> numbersOfLines;
    cout << numbersOfLines << endl;
    while (!file.eof()) {
        getline(file, text);
        cout << text << endl;
    }

    file.close();

    return 0;
}
