#include "gentree.hpp"
#include <iostream>
using namespace std;

class MyGenTree : public GenTree {
    node* root;
    int size;

    public:
    MyGenTree() {
        root = nullptr;
        size = 0;
    }

    node* addRoot(int num) {
        if (root != nullptr) {
            throw logic_error("Already has a root.");
        }
        root = (node*)calloc(1, sizeof(node));
        root->elem = num;
        root->left = nullptr;
        root->right = nullptr;
        root->parent = nullptr;
        size++;
        return root;
    }

    node* addLeft(node* n, int num) {
        if (n->left != nullptr) {
            throw logic_error("Left child already exists.");
        }
        node* newNode = (node*)calloc(1, sizeof(node));
        newNode->elem = num;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent = n;
        n->left = newNode;
        size++;
        return newNode;
    }

    node* addRight(node* n, int num) {
        if (n->right != nullptr) {
            throw logic_error("Right child already exists.");
        }

        node* newNode = (node*)calloc(1, sizeof(node));
        newNode->elem = num;
        newNode->left = nullptr;
        newNode->right = nullptr;
        newNode->parent = n;
        n->right = newNode;
        size++;
        return newNode;
    }

    void remove(node* n){
        if (n->left != nullptr && n->right != nullptr){
            throw logic_error("Node has children, cannot remove.");
        }

        if (n->parent != nullptr){
            if (n->parent->left == n){
                n->parent->left = nullptr;
            } else if (n->parent->right == n){
                n->parent->right = nullptr;
            }
        } else {
            root = nullptr;
        }
        size--;
        delete n;
    }
};