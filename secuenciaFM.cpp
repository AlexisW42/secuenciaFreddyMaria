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
    cout << "numbersOfLines " << numbersOfLines << endl;

    for (int i = 0; i < numbersOfLines; i++) {
        int num;
        file >> num;
        cout << num << " ";
        for (int i = 0; i < num; i++) {
            int numero;
            file >> numero;
            cout << numero << " ";
        }
        cout << endl;
    }

    file.close();

    return 0;
}
