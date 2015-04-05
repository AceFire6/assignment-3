#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

#include "HuffmanNode.h"
#include "HuffmanTree.h"

using namespace std;

// The comparator used by the priority queue
class CompareNode {
public:
    bool operator()(const MLLJET001::HuffmanNode& a,
                    const MLLJET001::HuffmanNode& b) {
        // If a < b. a comes after b. The largest value gets highest priority.
        return !(a < b);
    }
};


unordered_map<char, int> generateCharMap(string inputFileName,
                                         vector<string> * inputStrings) {
    unordered_map<char, int> charMap;
    ifstream inFile(inputFileName);
    string line;

    // Read in and count the frequency of each character
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            inputStrings->push_back(line);
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
    }
    return charMap;
}

priority_queue<MLLJET001::HuffmanNode, vector<MLLJET001::HuffmanNode>, CompareNode> makeNodeQueue(unordered_map<char, int> charMap) {
    priority_queue<MLLJET001::HuffmanNode,
            vector<MLLJET001::HuffmanNode>, CompareNode> nodeQueue;
    for (auto pair: charMap) {
        nodeQueue.push(MLLJET001::HuffmanNode(pair.first, pair.second));
    }
    return nodeQueue;
}


MLLJET001::HuffmanNode constructHuffmanTree(
        priority_queue<MLLJET001::HuffmanNode,
                vector<MLLJET001::HuffmanNode>, CompareNode> nodeQueue) {
    // Construct the HuffmanTree using the Priority Queue
    // Loop until just the root node is left in the priority queue.
    while (nodeQueue.size() > 1) {
        MLLJET001::HuffmanNode small1 = nodeQueue.top();
        nodeQueue.pop();

        MLLJET001::HuffmanNode small2 = nodeQueue.top();
        nodeQueue.pop();

        int totalFrequency = small1.getFrequency() + small2.getFrequency();

        MLLJET001::HuffmanNode newParent('\0', totalFrequency);

        newParent.left = make_shared<MLLJET001::HuffmanNode>(small1);
        newParent.right = make_shared<MLLJET001::HuffmanNode>(small2);

        nodeQueue.push(newParent);
    };
    return nodeQueue.top();
}


int main(int argc, const char* argv[]) {
    if (argc < 2) {
        cout << "Too few arguments." << endl;
        cout << "Required: huffmanencode <input_file> <output_file>" << endl;
    }

    string inputFileName = argv[1];
    string outputFileName = argv[2];
    vector<string> inputStrings;

    unordered_map<char, int> charMap = generateCharMap(inputFileName,
                                                       &inputStrings);

    // Construct the priority queue from the characters and their frequencies
    MLLJET001::HuffmanNode rootNode =
            constructHuffmanTree(makeNodeQueue(charMap));

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

