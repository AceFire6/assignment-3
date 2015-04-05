#include "Utils.h"

#define CATCH_CONFIG_MAIN

#include <unordered_map>
#include <vector>
#include <string>

#include "catch.hpp"

std::vector<std::string> inputStrings;
std::unordered_map<char, int> charMap = Utils::getCharMap("test1.txt", &inputStrings);
std::priority_queue<MLLJET001::HuffmanNode,
        std::vector<MLLJET001::HuffmanNode>, CompareNode> nodeQueue = Utils::makeNodeQueue(charMap);

TEST_CASE("CharMap is made correctly", "[char, map]" ) {
    REQUIRE(inputStrings.size() == 1);
    REQUIRE(charMap.size() == 5);
    REQUIRE(charMap['C'] == 2);
}


TEST_CASE("NodeQueue is made correctly", "[node, queue]" ) {
    REQUIRE(!nodeQueue.empty());
    REQUIRE(nodeQueue.size() == 5);
    REQUIRE(nodeQueue.top().getFrequency() == 1);
}


TEST_CASE("HuffmanTree is made correctly", "[tree]" ) {
    MLLJET001::HuffmanNode rootNode = Utils::constructHuffmanTree(nodeQueue);
    REQUIRE(rootNode.getFrequency() == 9);
    REQUIRE(rootNode.getCharacter() == '\0');
}
