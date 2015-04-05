#include <iostream>
#include <unordered_map>
#include <queue>
#include <fstream>

#include "HuffmanTree.h"
#include "Utils.h"


// Generate and return a map of all the characters in the input file
std::unordered_map<char, int> Utils::getCharMap(std::string inputFileName, std::vector<std::string> *inputStrings) {
    std::unordered_map<char, int> charMap;
    std::ifstream inFile(inputFileName);
    std::string line;

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
        std::cout << "Can't open file." << std::endl;
    }
    return charMap;
}

// Return the priority queue of HuffmanNodes.
std::priority_queue<MLLJET001::HuffmanNode, std::vector<MLLJET001::HuffmanNode>,
        CompareNode> Utils::makeNodeQueue(std::unordered_map<char, int> charMap) {
    std::priority_queue<MLLJET001::HuffmanNode,
            std::vector<MLLJET001::HuffmanNode>, CompareNode> nodeQueue;
    for (auto pair: charMap) {
        nodeQueue.push(MLLJET001::HuffmanNode(pair.first, pair.second));
    }
    return nodeQueue;
}

// Construct the HuffmanTree and return the its root node.
MLLJET001::HuffmanNode Utils::constructHuffmanTree(std::priority_queue<MLLJET001::HuffmanNode,
        std::vector<MLLJET001::HuffmanNode>, CompareNode> nodeQueue) {
    // Construct the HuffmanTree using the Priority Queue
    // Loop until just the root node is left in the priority queue.
    while (nodeQueue.size() > 1) {
        MLLJET001::HuffmanNode small1 = nodeQueue.top();
        nodeQueue.pop();

        MLLJET001::HuffmanNode small2 = nodeQueue.top();
        nodeQueue.pop();

        int totalFrequency = small1.getFrequency() + small2.getFrequency();

        MLLJET001::HuffmanNode newParent('\0', totalFrequency);

        newParent.left = std::make_shared<MLLJET001::HuffmanNode>(small1);
        newParent.right = std::make_shared<MLLJET001::HuffmanNode>(small2);

        nodeQueue.push(newParent);
    };
    return nodeQueue.top();
}
