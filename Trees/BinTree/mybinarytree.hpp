#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "binarytree.hpp"
using namespace std;

class MyBinaryTree : public BinaryTree {
	node* root;
	int size;

	node* create_node(int e, node* parent) {
	    // TODO this helper method
	    node* n = new node;
	    n->elem = e;
	    n->parent = parent;
	    n->left = nullptr;
	    n->right = nullptr;
	    size++;
	    return n;
	}

	public:
	node* addRoot(int e) {
        // TODO this method
        if (root != nullptr){
            throw logic_error("Already has root");
        }
        
        root = create_node(e, nullptr);
        
		return root;
	}

	node* addLeft(node* p, int e) {
        // TODO this method
        
        if (p->left != nullptr){
            throw logic_error(to_string(p->elem) + " already has left child");
        }
        
        p->left = create_node(e, p);
        
		return p->left;
	}

	node* addRight(node* p, int e) {
        // TODO this method
        
        if (p->right != nullptr){
            throw logic_error(to_string(p->elem) + " already has right child");
        }
        
        p->right = create_node(e, p);
        
        return p->right;
	}

    node* sibling(node* n){
        if (n == root){
            return nullptr;
        }
        
        if (n->parent->left == n){
            return n->parent->right;
        } else {
            return n->parent->left;
        }
    }

    int remove(node* n){
        node* par = n->parent;
        int val = n->elem;
        
        if (n->left == nullptr && n->right == nullptr){
            if (!par){
                root = nullptr;
            } else if (n == par->left){
                par->left = nullptr;
            } else {
                par->right = nullptr;
            }
        } else if (n->left == nullptr || n->right == nullptr){
            
            node* temp;
            if (n->left != nullptr){
                temp = n->left;
            }else {
                temp = n->right;
            }
            
            if (!par){
                root = temp;
            } else if (n == par->left){
                par->left = temp;
            } else {
                par->right = temp;
            }
            
            temp->parent = par;
        } else {
            throw logic_error("Cannot remove " + to_string(n->elem) + " for it has 2 children");
        }
        
        free(n);
        size--;
        
        return val;
    }

    int getSize() {
        return size;
    }

	node* getRoot() {
		return root;
	}
};