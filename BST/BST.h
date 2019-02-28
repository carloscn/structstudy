//
// Created by delvis on 2/28/19.
//

#ifndef BST_BST_H
#define BST_BST_H


class BST {

private:

    class Node{

    public:
        int e;
        Node* left;
        Node* right;

    public:
        Node(int e) {
            this->e = e;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

private:
    Node* root;
    int size;

public:

    BST();
    int size();
    bool isEmpty();
    void add(int e);
    void add_n(int e);
    bool contains(int e);

private :
    void add(Node* node, int e);
    bool contains(Node* node, int e);
    Node* add_n(Node* node, int e);

};


#endif //BST_BST_H
