#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <memory>

namespace MLLJET001 {
    class HuffmanNode {
    private:
        std::shared_ptr<HuffmanNode> left;
        std::shared_ptr<HuffmanNode> right;
        char character;
        int charCount;

    public:
        HuffmanNode(char character, int charCount) : character(character), charCount(charCount) {};
        bool operator<(const HuffmanNode node) const {
            return (this->charCount < node.charCount);
        }
    };
}

#endif
