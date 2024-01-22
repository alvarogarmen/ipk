#include "tree.hh"
#include <iostream>

int main() {
    BinaryTreeNode<int> left(1);
    BinaryTreeNode<int> right(2);
    BinaryTreeNode<int> papa(0, &left, &right);
    std::cout << "Left child is leaf: " << left.isLeaf() << std::endl;
    std::cout << "Right child is leaf: " << right.isLeaf() << std::endl;
    std::cout << "Parent is leaf: " << papa.isLeaf() << std::endl;
    std::cout << "Parent's left child (1): " << papa.getLeft()->getValue() << std::endl;
    std::cout << "Parent's right child (2): " << papa.getRight()->getValue() << std::endl;
}