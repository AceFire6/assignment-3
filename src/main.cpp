#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cout << "Too few arguments. Required: huffmanencode <input_file> <output_file>" << endl;
    }
    string inputFileName = argv[1];
    string outputFileName = argv[2];

    cout << inputFileName << "\t" << outputFileName << endl;

    unordered_map<char, int> charMap;
    ifstream inFile(inputFileName);
    string line;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            for (char c: line) {
                if (charMap.find(c) != charMap.end()) {
                    charMap.at(c) += 1;
                } else {
                    charMap.insert({c, 1});
                }
            }
        }
    }

    return 0;
}