#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace std;

class CompareNode {
public:
    bool operator()(const MLLJET001::HuffmanNode& a, const MLLJET001::HuffmanNode& b) {
        // If a < b. a comes after b. The largest value gets highest priority.
        return !(a < b);
    }
};

int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cout << "Too few arguments." << endl;
        cout << "Required: huffmanencode <input_file> <output_file>" << endl;
    }

    string inputFileName = argv[1];
    string outputFileName = argv[2];
    vector<string> inputStrings;

    unordered_map<char, int> charMap;
    ifstream inFile(inputFileName);
    string line;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            inputStrings.push_back(line);
            for (char character: line) {
                if (charMap.find(character) != charMap.end()) {
                    charMap.at(character) += 1;
                } else {
                    charMap.insert({character, 1});
                }
            }
        }
        inFile.close();
    } else {
        cout << "Can't open file." << endl;
        return 0;
    }

    priority_queue<MLLJET001::HuffmanNode, vector<MLLJET001::HuffmanNode>, CompareNode> nodeQueue;
    for (auto pair: charMap) {
//        cout << pair.first << '\t' << pair.second << endl;
        nodeQueue.push(MLLJET001::HuffmanNode(pair.first, pair.second));
    }

    while (nodeQueue.size() > 1) {
//        cout << "LOOPING" << '\t' << nodeQueue.size() << endl;
        MLLJET001::HuffmanNode small1 = nodeQueue.top();
        nodeQueue.pop();
//        cout << small1.getText() << '\t' << small1.getFrequency() << endl;

        MLLJET001::HuffmanNode small2 = nodeQueue.top();
        nodeQueue.pop();
//        cout << small2.getText() << '\t' << small2.getFrequency() << endl;

        int totalFrequency = small1.getFrequency() + small2.getFrequency();

        MLLJET001::HuffmanNode newParent('\0', totalFrequency);

        newParent.left = make_shared<MLLJET001::HuffmanNode>(small1);
        newParent.right = make_shared<MLLJET001::HuffmanNode>(small2);

        nodeQueue.push(newParent);
    };

    cout << "Character Count: " << nodeQueue.top().getFrequency() << endl;
    cout << "\nCode Table:\n-----------" << endl;

    MLLJET001::HuffmanTree huffmanTree(nodeQueue.top());

    unordered_map<char, std::string> codeTable = huffmanTree.getCharMap();

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

    size_t index = outputFileName.find('.');
    if (index != string::npos) {
        outputFileName = outputFileName.substr(0, index) + ".hdr";
    }

    outFile.open(outputFileName);
    if (outFile.is_open()) {
        outFile << codeTable.size() << endl;
        for (auto pair : codeTable) {
            outFile << pair.second << '\t' << pair.first << endl;
        }
    }

    return 0;
}

