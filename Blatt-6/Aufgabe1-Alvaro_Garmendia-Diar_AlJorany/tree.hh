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

    bool isLeaf() {
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


