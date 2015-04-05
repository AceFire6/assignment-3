#include "Utils.h"
#include "HuffmanNode.h"
#include "HuffmanTree.h"

#define CATCH_CONFIG_MAIN

#include <unordered_map>
#include <vector>
#include <string>

#include "catch.hpp"

std::vector<std::string> inputStrings;
std::unordered_map<char, int> charMap = Utils::getCharMap("test1.txt", &inputStrings);
std::priority_queue<MLLJET001::HuffmanNode,
        std::vector<MLLJET001::HuffmanNode>, CompareNode> nodeQueue = Utils::makeNodeQueue(charMap);
MLLJET001::HuffmanNode rootNode = Utils::constructHuffmanTree(nodeQueue);
MLLJET001::HuffmanTree huffmanTree(rootNode);
std::unordered_map<char, std::string> codeTable = huffmanTree.getCodeTable();


TEST_CASE("CharMap is made correctly", "[char, map]") {
    REQUIRE(inputStrings.size() == 1);
    REQUIRE(charMap.size() == 5);
    REQUIRE(charMap['C'] == 2);
}


TEST_CASE("NodeQueue is made correctly", "[node, queue]") {
    REQUIRE(!nodeQueue.empty());
    REQUIRE(nodeQueue.size() == 5);
    REQUIRE(nodeQueue.top().getFrequency() == 1);
}


TEST_CASE("Node structure is made correctly", "[tree]") {
    REQUIRE(rootNode.getFrequency() == 9);
    REQUIRE(rootNode.getCharacter() == '\0');
}

TEST_CASE("Code Table is made correctly", "[tree, codeTable]") {
    REQUIRE(!codeTable.empty());
    REQUIRE(codeTable.size() == 5);
    REQUIRE(codeTable[' '] == "000");
    REQUIRE(codeTable['E'] == "001");
    REQUIRE(codeTable['C'] == "01");
    REQUIRE(codeTable['A'] == "10");
    REQUIRE(codeTable['R'] == "11");
}
