#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string fileName;
    int wordCount = 0;
    string word;
    ifstream inFile;

    cout << "Enter file name: ";
    cin >> fileName;

    inFile.open(fileName);

    if (!inFile) {
        cout << "Unable to open file";
        exit(1);
    }

    while (inFile >> word) {
        wordCount++;
    }

    cout << "Number of words in file: " << wordCount << endl;

    inFile.close();

    return 0;
}
