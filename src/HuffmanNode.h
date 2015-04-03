#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <memory>

namespace MLLJET001 {
    class HuffmanNode {
    private:
        std::shared_ptr<HuffmanNode> left;
        std::shared_ptr<HuffmanNode> right;
    };
}

#endif
