#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <unordered_map>
#include <memory>
#include <vector>
#include <queue>
#include <string>
#include "HuffmanNode.h"

namespace MLLJET001 {
    class HuffmanTree {
    private:
        // The root of the Huffman Tree
        std::shared_ptr<HuffmanNode> rootNode;
        // The map of the character and its new bit code
        std::unordered_map<char, std::string> codeTable;

        // Populates the bit code map
        void populateMap(std::string bitCode, std::shared_ptr<HuffmanNode> parent);

    public:
        // Parametrized constructor
        HuffmanTree(HuffmanNode root);

        // Destructor
        ~HuffmanTree();

        // Returns the newly constructed char -> bit code map
        std::unordered_map<char, std::string> getCodeTable();

    };
}

#endif
