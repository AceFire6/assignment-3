#include <memory>
#include "HuffmanTree.h"

namespace MLLJET001 {

    HuffmanTree::HuffmanTree(HuffmanNode root) {
        this->rootNode = std::make_shared(root);
    }

    HuffmanTree::~HuffmanTree() {
        rootNode = nullptr;
    }
}
