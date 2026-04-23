#include <cstdlib>
#include <iostream>
#include "binarytree.hpp"
using namespace std;

class MyBinaryTree : public BinaryTree {
	node* root;
	int size;

	node* create_node(int e, node* parent) {
		node* n = (node*) calloc( 1, sizeof(node) );
		n->elem = e;
		n->parent = parent;
		return n;
	}

	public:
	node* addRoot(int e) {
		if (root) {
			cout << "Root exists" << endl;
			return NULL;
		}
		node* n = create_node(e, NULL);
		root = n;
		size++;
		return n;
	}

	node* left(node* p) {
		return p->left;
	}

	node* right(node* p) {
		return p->right;
	}

	node* sibling(node* n) {
		node* par = n->parent;
		if (!par) {
			return NULL;
		}
		if (n == par->left) {
			return par->right;
		}
		return par->left;
	}

	node* addLeft(node* p, int e) {
		if (p->left) {
			cout << "Left of " << p->elem << " exists" << endl;
			return NULL;
		}
		node* n = create_node(e, p);
		p->left = n;
		size++;
		return n;
	}

	node* addRight(node* p, int e) {
		if (p->right) {
			cout << "Right of " << p->elem << " exists" << endl;
			return NULL;
		}
		node* n = create_node(e, p);
		p->right = n;
		size++;
		return n;
	}

    int remove(node* n) {
        int res = n->elem;
        if (left(n) && right(n)) {
            return -1;
        }
        if (!left(n) && !right(n)) {
            if (n->parent) {
                node* par = n->parent;
                if (left(par) == n) {
                    par->left = NULL;
                } else {
                    par->right = NULL;
                }
            } else {
                root = NULL;
            }
        } else {
            node* child;
            if (left(n)) {
                child = left(n);
            } else {
                child = right(n);
            }
            if (n->parent) {
                node* par = n->parent;
                if (left(par) == n) {
                    par->left = child;
                } else {
                    par->right = child;
                }
                child->parent = par;
            } else {
                root = child;
                child->parent = NULL;
            }
        }
        size--;
        free(n);
        return res;
    }

	node* getRoot() {
		return root;
	}

   // TODO copy your completed zigleft here
     void zigleft(node* curr) {
        node* par = curr->parent;
        if(!par) return;
        node* grandP = par->parent;
        
        if(root == par){
            root = curr;
        }else if(grandP->left == par){
            grandP->left = curr;
        }else{
            grandP->right = curr;
        }
        
        curr->parent = grandP;
        par->right = curr->left;
        if(curr->left) curr->left->parent = par;
        curr->left = par;
        par->parent = curr;
        
        
    }

    // TODO copy your completed zigright here
    void zigright(node* curr) {
        node* par = curr->parent;
        if(!par) return;
        node* grandP = par->parent;
        
        if(root == par){
            root = curr;
        }else if(grandP->right == par){
            grandP->right = curr;
        }else{
            grandP->left = curr;
        }
        
        curr->parent = grandP;
        par->left = curr->right;
        if(curr->right) curr->right->parent = par;
        curr->right = par;
        par->parent = curr;
  
    }

    void print() {
        printHelper(root, "", true);
    }

	void printHelper(node* root, string indent, bool last) {
        if (root != nullptr) { // Or root != T_Nil if using sentinels
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "   ";
            } else {
                cout << "L----";
                indent += "|  ";
            }
            
            // Print color and data
            string sColor = (root->isRed) ? "RED" : "BLACK";
            cout << root->elem << "(" << sColor << ")" << endl;
            
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }
};