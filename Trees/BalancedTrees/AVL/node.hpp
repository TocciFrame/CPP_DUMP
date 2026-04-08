#include <algorithm>
using namespace std;

struct node {
    int elem;
    node* parent;
    node* left;
    node* right;
    int height;

    node(int k) {
        this->elem = k;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->height = 0;
    }

    int getHeight(node* n) {
        return n ? n->height : -1;
    }

    int getBalanceFactor(node* n) {
        return getHeight(n->left) - getHeight(n->right);
    }

    void updateHeight(node* n) {
        int left = getHeight(n->left);
        int right = getHeight(n->right);
        if (n) {
            n->height = 1 + max(left, right);
        }
    }

    node* rotateRight(node* y) { 
        node* x = y->left;
        node* T3 = x->right;

        x->right = y;
        y->left = T3;

        if (T3) T3->parent = y;
        x->parent = y->parent;
        y->parent = x;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    node* rotateLeft(node* x) {
        node* y = x->right;
        node* T2 = y->left;

        y->left = x;
        x->right = T2;

        if (T2) T2->parent = x;
        y->parent = x->parent;
        x->parent = y;

        updateHeight(x);
        updateHeight(y);

        return y;
    }
};