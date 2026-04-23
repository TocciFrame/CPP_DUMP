#include "mybinarytree.hpp"

class BST {
	BinaryTree* tree = new MyBinaryTree();

	public:
	bool search(int num) {
		return search_node(tree->getRoot(), num);
	}

	bool search_node(node* n, int num) {
		if (n == NULL) {
			return false;
		}
		if (n->elem == num) {
			return true;
		}
		if (num > n->elem) {
			// proceed to right
			return search_node(n->right, num);
		} else {
			return search_node(n->left, num);
		}
	}
    
	node* insert(int num) {
		node* n = tree->getRoot();
		if (n == NULL) {
			node* res = tree->addRoot(num);
            res->isRed = false;
            return res;
		}
		return insert_node(n, num);
	}
	
    node* insert_node(node* n, int num) {
        if (n->elem == num) return NULL;

        node* newNode = nullptr;
        if (num > n->elem) {
            if (n->right == nullptr) {
                newNode = tree->addRight(n, num);
            } else {
                return insert_node(n->right, num);
            }
        } else {
            if (n->left == nullptr) {
                newNode = tree->addLeft(n, num);
            } else {
                return insert_node(n->left, num);
            }
        }

        if (newNode) {
            newNode->isRed = true;
            handleDoubleRed(newNode);
        }
        return newNode;
    }

    void handleDoubleRed(node* curr) {
        node* par = curr->parent;
        if (!par || !par->isRed) return;

        node* gp = par->parent;
        if (!gp) {
            par->isRed = false;
            return;
        }

        node* uncle = getUncle(par);

        if (uncle && uncle->isRed) {
            par->isRed = false;
            uncle->isRed = false;
            gp->isRed = true;

            if (gp == tree->getRoot()) {
                gp->isRed = false;
            } else {
                handleDoubleRed(gp);
            }

        } else {
            node* res = restructure(gp);
            res->isRed = false;
            if (res->left) res->left->isRed = true;
            if (res->right) res->right->isRed = true;    
        }
    }

    node* getUncle(node* curr) {
        node* par = curr->parent;
        if (!par) return nullptr;

        if (curr == par->left)
            return par->right;
        else if (curr == par->right)
            return par->left;

        return nullptr;    
    }

    // // TODO perform post-processing by checking for violation after deletion
    // // from the parent of the node removed until the root
    // bool remove(int num) {
    //     return remove_node(tree->getRoot(), num);
    // }

    // bool remove_node(node* n, int num) {
    //     if (n == NULL) return false;
    
    //     if (num > n->elem) {
    //         return remove_node(n->right, num);
    //     } 
    //     else if (num < n->elem) {
    //         return remove_node(n->left, num);
    //     } 
    //     else {
    //         node* par = n->parent; 
    
    //         if (n->left && n->right) {
    //             node* r = n->right;
    //             while (r->left) {
    //                 r = r->left;
    //             }
    //             int rem = r->elem; 
    //             remove_node(r, rem);
    
    //             n->elem = rem;
                
    //             return true;
    //         } 
    //         else {
    //             tree->remove(n);
                
    //             node* curr = par;
    //             while (curr) {
    //                 int lh = curr->left ? curr->left->height() : -1;
    //                 int rh = curr->right ? curr->right->height() : -1;
    
    //                 if (abs(lh - rh) > 1) {
    //                     restructure(curr); 
    //                 }
    //                 curr = curr->parent;
    //             }
    //             return true;
    //         }
    //     }
    //     return false;
    // }


    // TODO copy and paste your completed restructure method here
    node* restructure(node* gp) {
        
        node* par; // parent      
        // TODO find parent
        int plh = par->left ? par->left->height() : -1;
        int prh = par->right ? par->right->height() : -1;

        if (plh > prh) {
            par = gp->left;
        } else {
            par = gp->right;
        }
        
        // This is an indicator of the placement of grandparent to parent (gtop)
        bool gtop_right = false;
        if (gp->right == par) {
            gtop_right = true;
        }

        node* child;
        // TODO find child
        //x

        int clh = par->left ? par->left->height() : -1;
        int crh = par->right ? par->right->height() : -1;

        if (clh > crh) {
            child = par->left;
        } else {
            child = par->right;
        }
        
        // This is an indicator of the placement of parent to child (ptoc)
        bool ptoc_right = false;
        if (par->right == child) {
            ptoc_right = true;
        }

        // FOR THE FOLLOWING: Write in each of the if statements a console output
        // on its corresponding operation (ZIGLEFT, ZIGRIGHT, ZIGZAGLEFT, or ZIGZAGRIGHT)

        // z
        //  \
        //   y
        //    \
        //     x
        if (gtop_right && ptoc_right) {
            // TODO call to either zigleft or zigright or both
            
            cout << "ZIGLEFT" << endl;
            return zigleft(par);
        }

        // z
        //   \
        //     y
        //    /
        //   x
        else if (gtop_right && !ptoc_right) {
            // TODO call to either zigleft or zigright or both
            cout << "ZIGZAGLEFT" << endl;
            zigright(child);
            return zigleft(child);
        }

        //      z
        //     /
        //    y
        //   /
        //  x
        else if (!gtop_right && !ptoc_right) {
            // TODO call to either zigleft or zigright or both
            cout << "ZIGRIGHT" << endl;
            return zigright(par);
        }

        //       z
        //     /
        //    y
        //     \
        //      x
        else {
            // TODO call to either zigleft or zigright or both
            zigleft(child);
            zigright(child);
            cout << "ZIGZAGRIGHT" << endl;
        }

        return child;
    }

    node* zigleft(node* curr) {
        tree->zigleft(curr);
        return curr;
    }

    node* zigright(node* curr) {
        tree->zigright(curr);
        return curr;
    }

	void print() {
		tree->print();
	}
};