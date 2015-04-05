#include <memory>
#include <string>
#include <iostream>
#include "HuffmanTree.h"

namespace MLLJET001 {

    HuffmanTree::HuffmanTree(HuffmanNode root) {
        rootNode = std::make_shared<HuffmanNode>(root);
    }

    HuffmanTree::~HuffmanTree() {
        rootNode = nullptr;
    }

    std::unordered_map<char, std::string> HuffmanTree::getCodeTable() {
        populateMap("", rootNode);
        return codeTable;
    }

    void HuffmanTree::populateMap(std::string bitCode,
                                  std::shared_ptr<HuffmanNode> parent) {
        if (parent->left != nullptr) {
            if (parent->left->getCharacter() == '\0') {
                populateMap(bitCode + "0", parent->left);
            } else {
                std::cout << parent->left->getCharacter() << '\t' << bitCode << "0" << std::endl;
                codeTable.insert({parent->left->getCharacter(), bitCode + "0"});
            }
        }

        if (parent->right != nullptr) {
            if (parent->right->getCharacter() == '\0') {
                populateMap(bitCode + "1", parent->right);
            } else {
                std::cout << parent->right->getCharacter() << '\t' << bitCode << "1" << std::endl;
                codeTable.insert({parent->right->getCharacter(), bitCode + "1"});
            }
        }
    }
}
