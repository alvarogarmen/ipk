#ifndef HUFFMAN_HH
#define HUFFMAN_HH

#include <map>
#include <vector>
#include <memory>

template<typename T>
class BinaryTreeNode {
    T value;
    std::unique_ptr<BinaryTreeNode> leftChild;
    std::unique_ptr<BinaryTreeNode> rightChild;
public:
    T getValue() { return this->value; }

    BinaryTreeNode *getLeft() { return this->leftChild.get(); }

    BinaryTreeNode *getRight() { return this->rightChild.get(); }

    bool isLeaf() const {
        return !leftChild && !rightChild;
    }

    BinaryTreeNode(T startValue) {
        this->value = startValue;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }

    BinaryTreeNode(T startValue, BinaryTreeNode *left, BinaryTreeNode *right) {
        this->value = startValue;
        this->leftChild.reset(left);
        this->rightChild.reset(right);
    }
};

// Function to count character frequency
std::map<char, int> countCharacterFrequency(const std::string &);

// Type Aliases
template<typename T>
using HuffmanNode = BinaryTreeNode<T>;

template<typename T>
using HuffmanPointer = std::shared_ptr<HuffmanNode<T>>;

template<typename T>
using WeightedHuffmanPointer = std::pair<int, HuffmanPointer<T>>;

using BitVector = std::vector<bool>;
using CodeMap = std::map<char, BitVector>;

// Comparison function template
template<typename T>
bool isWeightGreater(const WeightedHuffmanPointer<T> &lhs, const WeightedHuffmanPointer<T> &rhs) {
    return lhs.first > rhs.first;
}

#endif // HUFFMAN_HH
