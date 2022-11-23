#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream file("secuencias.txt");
    string text;
    int numbersOfLines;

    if (file.fail()) {
        cout << "Error!" << endl;
        return 0;
    }
    file>>numbersOfLines;
    cout << numbersOfLines << endl;
    while (!file.eof()) {
        getline(file, text);
        cout << text << endl;
    }

    file.close();

	int a=5;
	int b=2;
	
	int suma= a+b;
	cout << suma;
	
    return 0;
}
