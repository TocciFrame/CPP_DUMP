#include "binarytree.hpp"
#include <string>
using namespace std;

class MyBinaryTree : public BinaryTree {
    node* root;
    int size;
    
    public:
    MyBinaryTree() {
        size = 0;
        root = nullptr;
    }
    
    node* addRoot(int e) {
        if (root != nullptr) {
            return nullptr; // Root already exists
        }
        
        root = new node;
        root->elem = e;
        root->parent = nullptr;
        root->left = nullptr;
        root->right = nullptr;
        size++;
        
        return root;
    }
    
    node* addLeft(node* p, int e) {
        if (p->left != nullptr) {
            return nullptr; // Left child already exists
        }
        
        node* leftChild = new node;
        leftChild->elem = e;
        leftChild->parent = p;
        leftChild->left = nullptr;
        leftChild->right = nullptr;
        
        p->left = leftChild;
        size++;
        
        return leftChild;
    }
    
    node* addRight(node* p, int e) {
        if (p->right != nullptr) {
            return nullptr; // Right child already exists
        }
        
        node* rightChild = new node;
        rightChild->elem = e;
        rightChild->parent = p;
        rightChild->left = nullptr;
        rightChild->right = nullptr;
        
        p->right = rightChild;
        size++;
        
        return rightChild;
    }
    
    int remove(node* n) {
        if (n->left != nullptr || n->right != nullptr) {
            return -1; // Node has children
        }
        
        if (n == root) {
            delete root;
            root = nullptr;
            return 0;
        }
        
        node* parent = n->parent;
        if (parent->left == n) {
            parent->left = nullptr;
        } else if (parent->right == n) {
            parent->right = nullptr;
        }
        
        delete n;
        size--;
        return 0;
    }
    
    node* getRoot() {
        return root;
    }
    
    node* left(node* n) {
        return n->left;
    }
    
    node* right(node* n) {
        return n->right;
    }

    node* sibling(node* n) {
        if (n->parent == nullptr) {
            return nullptr; // Root has no sibling
        }
        
        if (n->parent->left == n) {
            return n->parent->right;
        } else {
            return n->parent->left;
        }
    }

    int getSize() {
	    return size;
	}
    
    void print_node(string prefix, node* n, bool isLeft) {
        if (n != nullptr) {
            cout << prefix;

            cout << (isLeft ?"+-->L: " : "+-->R: ");
            cout << n->elem << endl;
            print_node(prefix + (isLeft ? "|   " : "    "), n->left, true);
            print_node(prefix + (isLeft ? "|   " : "    "), n->right, false);

        }
    }
    void print() {
        if (root == nullptr) {
            cout << "Size: " << size << endl;
            cout << "EMPTY" << endl;
            return;
        }
        cout << "Size: " << size << endl;

        print_node("", root, false);

        cout << "Status: " << (root->parent == nullptr ? "1" : "0") << endl;
    }
};