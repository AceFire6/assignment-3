#include <fstream>
#include <iostream>
#include <queue>
#include <unordered_map>

#include "HuffmanNode.h"
#include "HuffmanTree.h"
#include "Utils.h"

using namespace std;


int main(int argc, const char *argv[]) {
    if (argc < 3) {
        cout << "Too few arguments." << endl;
        cout << "Required: huffmanencode <input_file> <output_file>" << endl;
        return 0;
    }

    string inputFileName = argv[1];
    string outputFileName = argv[2];
    vector<string> inputStrings;

    unordered_map<char, int> charMap = Utils::getCharMap(inputFileName, &inputStrings);

    // Construct the priority queue from the characters and their frequencies
    MLLJET001::HuffmanNode rootNode = Utils::constructHuffmanTree(Utils::makeNodeQueue(charMap));

    cout << "Character Count: " << rootNode.getFrequency() << endl;
    cout << "\nCode Table:\n-----------" << endl;

    // Initialise the HuffmanTree structure with the root node
    MLLJET001::HuffmanTree huffmanTree(rootNode);

    // Generate and get the bit code table for the characters and their
    // encoding.
    unordered_map<char, std::string> codeTable = huffmanTree.getCharMap();

    // Write out the "binary" string of the input
    ofstream outFile(outputFileName);
    if (outFile.is_open()) {
        for (auto inputString : inputStrings) {
            for (auto character : inputString) {
                outFile << codeTable[character];
            }
            outFile << endl;
        }
        outFile.close();
    }

    // Construct the file name for the header file
    size_t index = outputFileName.find('.');
    if (index != string::npos) {
        outputFileName = outputFileName.substr(0, index) + ".hdr";
    }

    // Write out the bit code table
    outFile.open(outputFileName);
    if (outFile.is_open()) {
        outFile << codeTable.size() << endl;
        for (auto pair : codeTable) {
            outFile << pair.first << '\t' << pair.second << endl;
        }
        outFile.close();
    }

    return 0;
}

