#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <queue>
#include <unordered_map>

#include "HuffmanNode.h"

// The comparator used by the priority queue
class CompareNode {
public:
    bool operator()(const MLLJET001::HuffmanNode &a, const MLLJET001::HuffmanNode &b) {
        // If a < b. a comes after b. The largest value gets highest priority.
        return !(a < b);
    }
};

class Utils {
public:
    // Generate and return a map of all the characters in the input file
    static std::unordered_map<char, int> getCharMap(std::string inputFileName, std::vector<std::string> *inputStrings);

    // Return the priority queue of HuffmanNodes.
    static std::priority_queue<MLLJET001::HuffmanNode, std::vector<MLLJET001::HuffmanNode>, CompareNode>
            makeNodeQueue(std::unordered_map<char, int> charMap);

    // Construct the HuffmanTree and return the its root node.
    static MLLJET001::HuffmanNode constructHuffmanTree(std::priority_queue<MLLJET001::HuffmanNode,
            std::vector<MLLJET001::HuffmanNode>, CompareNode> nodeQueue);
};

#endif
