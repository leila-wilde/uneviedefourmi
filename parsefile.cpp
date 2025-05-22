/* Program to parse the anthill text files */

#include <iostream>
#include <fstream> // use to read and write to a file

using namespace std;

int main() {

    string filename = "fourmiliere_zero.txt";
    ifstream input;

    input.open(filename);

    if(input.is_open()) {
        return 1;
    }

    while(input) {
        string line;

        getline(input, line, '=');

        int numAnts;
        input >> numAnts;

        cout <<  line << " -- " << numAnts << endl;
    }

    input.close();

    return 0;
    
}