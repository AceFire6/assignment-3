#include "HuffmanNode.h"

char MLLJET001::HuffmanNode::getCharacter() const {
    return character;
}

int MLLJET001::HuffmanNode::getFrequency() const {
    return frequency;
}

void MLLJET001::HuffmanNode::setCharacter(char character) {
    this->character = character;
}

void MLLJET001::HuffmanNode::setFrequency(int count) {
    frequency = count;
}
