#include "node.hpp"
#include <iostream>
using namespace std;

class Tree {
    node* root;
    int size;

    public:
    Tree() {
        root = NULL;
        size = 0;
    }

    node* create_node(node* par, int num) {
        node* n = new node();
        n->parent = par;
        n->left = NULL;
        n->right = NULL;
        n->element = num;
        n->isRed = true;
        return n;
    } 

    bool insert(int num) {
        if (!root) {
            root = create_node(NULL, num);
            root->isRed = false;
            size++;
            return true;
        }

        return insert_node(root, num);
    }

    bool insert_node(node* curr, int num) {
        if (curr->element == num) return false;

        node* n = NULL;
        if (num > curr->element) {
            if (curr->right) {
                return insert_node(curr->right, num);
            } else {
                n = create_node(curr, num);
                curr->right = n;
                size++;
            }
        } else {
            if (curr->left) {
                return insert_node(curr->left, num);
            } else {
                n = create_node(curr, num);
                curr->left = n;
                size++;
            }
        }

        if (n) {
            handleDoubleRed(n);
        }

        return true;
    }

    bool search(int num) {
        return search_node(root, num);
    }

    bool search_node(node* curr, int num) {
        if (!curr) return false;
        if (curr->element == num) return true;

        if (num > curr->element) {
            return search_node(curr->right, num);
        } else {
            return search_node(curr->left, num);
        }
    }

    bool remove(int num) {
        return remove_node(root, num);
    }

    bool remove_node(node* curr, int num) {
        if (!curr) return false;

        if (num > curr->element) {
            return remove_node(curr->right, num);
        } else if (num < curr->element) {
            return remove_node(curr->left, num);
        } else {
            if (curr->left && curr->right) {
                node* succ = curr->right;
                while (succ->left) succ = succ->left;
                curr->element = succ->element;
                return remove_node(curr->right, succ->element);
            } else {
                node* child = (curr->left) ? curr->left : curr->right;

                if (!curr->isRed) {
                    if (child && child->isRed) {
                        child->isRed = false;
                    } else {
                        handleDoubleBlack(curr); 
                    }
                }

                if (curr->parent == NULL) {
                    root = child; 
                } else {
                    if (curr->parent->left == curr) {
                        curr->parent->left = child; 
                    } else {
                        curr->parent->right = child; 
                    }
                }

                if (child) {
                    child->parent = curr->parent; 
                }

                delete curr; 
                size--;
                return true;
            }
        }
        return true;
    }

    void handleDoubleBlack(node* curr) {
        if (curr == root) return;

        node* par = curr->parent;
        if (!par) return;

        node* sibling = (par->left == curr) ? par->right : par->left;

        if (!sibling) {
            if (!par->isRed) handleDoubleBlack(par);
            else par->isRed = false;    
            return;
        }

        if (sibling->isRed) {
            cout << "CASE 3 VIOLATION" << endl;
            par->isRed = true;
            sibling->isRed = false;

            if (par->left == curr) {
                zigleft(sibling);
            } else {
                zigright(sibling);
            }

            handleDoubleBlack(curr);
            return;
        }

        if (!sibling->isRed) {
            if ((sibling->left && sibling->left->isRed) || (sibling->right && sibling->right->isRed)) {
                cout << "CASE 1 VIOLATION" << endl;
                node* sibling_child = (sibling->left && sibling->left->isRed) ? sibling->left : sibling->right;

                bool oldParRed = par->isRed;
                node* res = restructure(sibling_child);
                res->isRed = oldParRed;

                if (res->left) res->left->isRed = false;
                if (res->right) res->right->isRed = false;
            } else {
                cout << "CASE 2 VIOLATION" << endl;
                sibling->isRed = true;
                if (!par->isRed) {
                    handleDoubleBlack(par);
                } else {
                    par->isRed = false;
                }
            }
        }
    }

    void zigleft(node* x) {
        node* y = x->parent;
        node* T2 = x->left;
        node* z = y->parent;

        if (root == y) root = x;
        else if (z->left == y) z->left = x;
        else z->right = x;

        x->parent = z;
        y->right = T2;
        if (T2) T2->parent = y;
        x->left = y;
        y->parent = x;
    }

    void zigright(node* x) {
        node* y = x->parent;
        node* T2 = x->right;
        node* z= y->parent;

        if (root == y) root = x;
        else if (z->left == y) z->left = x;
        else z->right = x;

        x->parent = z;
        y->left = T2;
        if (T2) T2->parent = y;
        x->right = y;
        y->parent = x;
    }

    node* restructure(node* x) {
        node* y = x->parent;
        node* z = y->parent;

        bool ztoy_right = false;
        if (z->right == y) {
            ztoy_right = true;
        }

        bool ytox_right = false;
        if (y->right == x) {
            ytox_right = true;
        }

        if (ztoy_right && ytox_right) {
            cout << "ZIGLEFT" << endl;
            zigleft(y);
            return y;
        } else if (ztoy_right && !ytox_right) {
            cout << "ZIGZAGLEFT" << endl;
            zigright(x);
            zigleft(x);
            return x;
        } else if (!ztoy_right && !ytox_right) {
            cout << "ZIGRIGHT" << endl;
            zigright(y);
            return y;
        } else {
            cout << "ZIGZAGRIGHT" << endl;
            zigleft(x);
            zigright(x);
            return x;
        }
    }

    void handleDoubleRed(node* x) {
        node* y = x->parent;
        if (!y || !y->isRed) return;

        node* z = y->parent;
        node* uncle = getUncle(y);

        if (uncle && uncle->isRed) {
            cout << "CASE 2 VIOLATION" << endl;
            y->isRed = false;
            if (uncle) uncle->isRed = false;
            z->isRed = true;

            if (z == root) {
                z->isRed = false;
            } else {
                handleDoubleRed(z);
            }
            
        } else {
            cout << "CASE 1 VIOLATION" << endl;
            node* res = restructure(x);
            res->isRed = false;
            
            if (res->left) res->left->isRed = true;
            if (res->right) res->right->isRed = true;
        }
    }

    node* getUncle(node* par) {
        node* gp = par->parent;
        if (!gp) return NULL;
        
        node* uncle = NULL;
        if (gp->left == par) {
            uncle = gp->right;
        } else {
            uncle = gp->left;
        }
        return uncle;
    }

    void print() {
        if (isEmpty()) {
            cout << "EMPTY" << endl;
            return;
        }
        cout << "PRE-ORDER: ";
        print_preorder(root);
        cout << endl << "IN-ORDER: ";
        print_inorder(root);
        cout << endl << "POST-ORDER: ";
        print_postorder(root);
        cout << endl << "STATUS: " << check_parent(root, NULL) << endl;
    }

    bool isEmpty() {
        return size == 0;
    }

    void print_preorder(node* curr) {
        cout << curr->element << (curr->isRed ? "(R)" : "(B)") << " ";
        if (curr->left != NULL) {
            print_preorder(curr->left);
        }
        if (curr->right != NULL) {
            print_preorder(curr->right);
        }
    }

    void print_inorder(node* curr) {
        if (curr->left != NULL) {
            print_inorder(curr->left);
        }
        cout << curr->element << (curr->isRed ? "(R)" : "(B)") << " ";
        if (curr->right != NULL) {
            print_inorder(curr->right);
        }
    }

    void print_postorder(node* curr) {
        if (curr->left != NULL) {
            print_postorder(curr->left);
        }
        if (curr->right != NULL) {
            print_postorder(curr->right);
        }
        cout << curr->element << (curr->isRed ? "(R)" : "(B)") << " ";
    }

    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            if (!curr->parent) {
                cout << "Illegal parent of " << curr->element << ": NULL -- must be " << par->element << endl;
            } else if (!par) {
                cout << "Illegal parent of " << curr->element << ": " << curr->parent->element << "must be NULL" << endl;
            } else {
                cout << "Illegal parent of " << curr->element << ": " << curr->parent->element << " -- must be " << par->element << endl;
            }
            return false;
        }
        return check_parent(curr->left, curr) && check_parent(curr->right, curr);
    }
};