#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <memory>

namespace MLLJET001 {
    class HuffmanNode {
    private:
        char character;
        int charCount;

    public:
        std::shared_ptr<HuffmanNode> left;
        std::shared_ptr<HuffmanNode> right;

        HuffmanNode(char character, int charCount) : character(character), charCount(charCount) {};

        char getCharacter();

        int getFrequency();

        bool operator<(const HuffmanNode node) const {
            return (this->charCount < node.charCount);
        }
    };
}

#endif
