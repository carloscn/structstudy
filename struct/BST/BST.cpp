//
// Created by delvis on 2/28/19.
//

#include "BST.h"

BST::BST() {
    root = nullptr;
    size = 0;
}

int BST::size() {
    return size;
}

bool BST::isEmpty() {
    return size == 0;
}

void BST::add(int e) {
    // 如果当前的节点没有被开发利用，则创建一个节点。
    if (root == nullptr) {
        root = new Node(e);
        size ++;
    }
    // 如果当前节点是根节点，则进行比较放入左孩子节点或者右孩子节点
    else {
        add(root, e);
    }
}
// 传入参数为在某个节点插入变量e，规则：比根节点小的放在左孩子，比根节点大的放在右孩子
void BST::add(BST::Node *node, int e) {

    if (e == node->e)
        return;
    // 当前插入的值比根节点小，且左孩子空位 -> 直接把数值插入到左孩子
    // 递归终止条件
    else if (e < node->e && node->left == nullptr ) {
        node->left = new Node(e);
        size ++;
        return;
    }
    else if (e > node->e && node->right == nullptr ) {
        node->right = new Node(e);
        size ++;
        return;
    }
    // 如果没有满足上述的递归终止条件，则开始向下进行递归，直到满足递归条件为止。
    // 如果当前的值比根节点的数值小，则向左孩子添加
    if (e < node->e)
        add(node->left, e);
    // 如果当前的值比根节点的数值大，则向右孩子添加
    else
        add(node->right, e);

}

// 第二种方法
void BST::add_n(int e) {

    root = add_n(root, e);

}

BST::Node *BST::add_n(BST::Node *node, int e) {

    if (node == nullptr) {
        size ++;
        return new BST::Node(e);
    }

    if (e < node->e) {
        node->left = add_n(node->left, e);
        size ++;
    }
    else if (e > node->e) {
        node->right = add_n(node->right, e);
        size ++;
    }

    return node;
}

bool BST::contains(int e) {

    return contains(root, e);
}

bool BST::contains(BST::Node *node, int e) {

    if (node == nullptr)
        return false;
    // 当前根节点是该元素
    if (node->e == e)
        return true;
    // 当前值小于根节点元素值，且左孩子的值等于该元素
    // 递归条件
    else if (e < node->e) {
        contains(node->left,e);
        return true;
    }
    else if (e > node->e) {
        contains(node->right, e);
        return true;
    }
}





