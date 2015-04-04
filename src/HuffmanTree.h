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
        std::shared_ptr<HuffmanNode> rootNode;
        std::unordered_map<char, std::string> codeTable;

    public:
        HuffmanTree(HuffmanNode root);
        ~HuffmanTree();
        std::unordered_map<char, std::string> getCharMap();
        void populateMap(std::string bitCode, std::shared_ptr<HuffmanNode> parent);

    };
}

#endif
