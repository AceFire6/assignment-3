#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <memory>
#include <string>

namespace MLLJET001 {
    class HuffmanNode {
    private:
        char character;
        int charCount;

    public:
        std::shared_ptr<HuffmanNode> left;
        std::shared_ptr<HuffmanNode> right;
        std::string text;

        // Default Constructor
        HuffmanNode() : character('\0') {};

        // Destructor
        ~HuffmanNode() { }

        // Parametrized Constructor
        HuffmanNode(char character, int charCount) : character(character), charCount(charCount) {};

        // Copy Constructor
        HuffmanNode(const HuffmanNode & rhs) :
                character(rhs.character), charCount(rhs.charCount), left(rhs.left), right(rhs.right) {};

        // Move Constructor
        HuffmanNode(HuffmanNode && rhs) : character(rhs.character), charCount(rhs.charCount),
                                          left(std::move(rhs.left)), right(std::move(rhs.right)) {};

        // Copy Assignment
        HuffmanNode & operator=(const HuffmanNode & rhs) {
            if (this != &rhs) {
                character = rhs.character;
                charCount = rhs.charCount;

                left = rhs.left;
                right = rhs.right;
            }
            return *this;
        }

        // Move Assignment
        HuffmanNode & operator=(HuffmanNode && rhs) {
            if (this != &rhs) {
                character = rhs.character;
                rhs.setCharacter('\0');
                charCount = rhs.charCount;
                rhs.setCharCount(0);

                left = std::move(rhs.left);
                right = std::move(rhs.right);
            }
            return *this;
        }

        bool operator<(const HuffmanNode node) const {
            return (this->charCount < node.charCount);
        }

        char getCharacter() const;

        int getFrequency() const;

        void setCharacter(char character);

        void setCharCount(int count);
    };
}

#endif
