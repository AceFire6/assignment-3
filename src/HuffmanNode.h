#ifndef HUFFMANNODE_H
#define HUFFMANNODE_H

#include <memory>
#include <string>

namespace MLLJET001 {
    class HuffmanNode {
    private:
        char character;
        int frequency;

    public:
        std::shared_ptr<HuffmanNode> left;
        std::shared_ptr<HuffmanNode> right;
        std::string text;

        // Default Constructor
        HuffmanNode() : character('\0') { };

        // Destructor
        ~HuffmanNode() { }

        // Parametrized Constructor
        HuffmanNode(char character, int charCount) : character(character), frequency(charCount) { };

        // Copy Constructor
        HuffmanNode(const HuffmanNode &rhs) :
                character(rhs.character), frequency(rhs.frequency), left(rhs.left), right(rhs.right) { };

        // Move Constructor
        HuffmanNode(HuffmanNode &&rhs) : character(rhs.character), frequency(rhs.frequency), left(std::move(rhs.left)),
                                         right(std::move(rhs.right)) { };

        // Copy Assignment
        HuffmanNode &operator=(const HuffmanNode &rhs) {
            if (this != &rhs) {
                character = rhs.character;
                frequency = rhs.frequency;

                left = rhs.left;
                right = rhs.right;
            }
            return *this;
        }

        // Move Assignment
        HuffmanNode &operator=(HuffmanNode &&rhs) {
            if (this != &rhs) {
                character = rhs.character;
                rhs.setCharacter('\0');
                frequency = rhs.frequency;
                rhs.setFrequency(0);

                left = std::move(rhs.left);
                right = std::move(rhs.right);
            }
            return *this;
        }

        // Overload the '<' operator to compare the frequency of the char
        bool operator<(const HuffmanNode node) const {
            return (this->frequency < node.frequency);
        }

        // Return the char held by this object
        char getCharacter() const;

        // Return the frequency the char held by this object appears in the
        // input
        int getFrequency() const;

        // Set the char held by this object
        void setCharacter(char character);

        // Set the frequency of the char held by this object
        void setFrequency(int count);
    };
}

#endif
