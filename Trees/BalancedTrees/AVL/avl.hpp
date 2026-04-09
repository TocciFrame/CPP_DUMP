#include <iostream>
#include "list.hpp"

class AVL : public List {
    node* root;
    int size;

    node* restructure(node* z) {
        z->updateHeight(z);
        int balanceFactor = z->getBalanceFactor(z);

        if (balanceFactor > 1) {
            if (z->left->getBalanceFactor(z->left) >= 0) {
                return z->rotateRight(z); // ZR
            } else {
                z->left = z->rotateLeft(z->left); // ZZR
                return z->rotateRight(z);
            }
        } else if (balanceFactor < -1) {
            if (z->right->getBalanceFactor(z->right) <= 0) {
                return z->rotateLeft(z);
            } else {
                z->right = z->rotateRight(z->right);
                return z->rotateLeft(z);
            }
        }
        return z;
    }

    node* insert(node* curr, int num) {

        if (!curr) {
            node* newNode = new node(num);
            size++;
            return newNode;
        }

        if (num == curr->elem) {
            return nullptr;
        }   

        if (num < curr->elem) {
            curr->left = insert(curr->left, num);
        } else if (num > curr->elem) {
            curr->right = insert(curr->right, num);
        }

        curr = restructure(curr);

        // curr->updateHeight(curr);
        // int balanceFactor = curr->getBalanceFactor(curr);


        // // Rotations
        // if (balanceFactor > 1) {
        //     if (num < curr->left->elem) {
        //         return curr->rotateRight(curr); // ZR
        //     } else {
        //         curr->left = curr->rotateLeft(curr->left); // ZZR
        //         return curr->rotateRight(curr);
        //     }
        // } else if (balanceFactor < -1) {
        //     if (num > curr->right->elem) {
        //         return curr->rotateLeft(curr);
        //     } else {
        //         curr->right = curr->rotateRight(curr->right);
        //         return curr->rotateLeft(curr);
        //     }
        // }

        return curr;
    }

    node* remove(node* curr, int num) {
        if (!curr) return nullptr;

        if (num < curr->elem) {
            curr->left = remove(curr->left, num);
        } else if (num > curr->elem) {
            curr->right = remove(curr->right, num);
        } else {
            if (!curr->left || !curr->right) {
                node* temp;
                if (curr->left) {
                    temp = curr->left;
                } else {
                     temp = curr->right;
                }

                if (!temp) {
                    delete curr;
                    return nullptr;
                } else {
                    node* toDelete = curr;
                    curr = temp;
                    delete toDelete;
                    size--;
                }
            } else {
                node* temp = curr->right;
                while (temp->left) {
                    temp = temp->left;
                }
                curr->elem = temp->elem;
                curr->right = remove(curr->right, temp->elem);
                size--;
            }
        }

        if (!curr) return nullptr;
        curr = restructure(curr);

        // curr->updateHeight(curr);
        // int balanceFactor = curr->getBalanceFactor(curr);

        // if (balanceFactor > 1) {
        //     if (curr->left->getBalanceFactor(curr->left) >= 0) {
        //         return curr->rotateRight(curr);
        //     } else {
        //         curr->left = curr->rotateLeft(curr->left);
        //         return curr->rotateRight(curr);
        //     }
        // } else if (balanceFactor < -1) {
        //     if (curr->right->getBalanceFactor(curr->right) <= 0) {
        //         return curr->rotateLeft(curr);
        //     } else {
        //         curr->right = curr->rotateRight(curr->right);
        //         return curr->rotateLeft(curr);
        //     }
        // }

        return curr;
    }

    bool search(node* curr, int num) {
        if (!curr) return false;

        if (num == curr->elem) return true;
        else if (num < curr->elem) {
            return search(curr->left, num);
        } else {
            return search(curr->right, num);
        }

        return false;
    }

    public:
    AVL() {
        root = nullptr;
        size = 0;
    }

    bool insert(int num) {
        int prevSize = size;
        root = insert(root, num);
        return size > prevSize;
    }

    bool remove(int num) {
        int prevSize = size;
        root = remove(root, num);
        return size < prevSize;
    }

    bool search(int num) {
        return search(root, num);
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