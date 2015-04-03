#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <memory>
#include <vector>
#include "HuffmanNode.h"

namespace MLLJET001 {
    class HuffmanTree {
    private:
        std::shared_ptr<HuffmanNode> rootNode;
        std::vector<HuffmanNode> nodes;

    public:
        ~HuffmanTree();

    };
}

#endif
