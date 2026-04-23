#include <algorithm>
using namespace std;

struct node {
    node* parent;
    node* left;
    node* right;
    int elem;
    bool isRed = true;

    int height() {
        int lh = left ? left->height() : -1;
        int rh = right ? right->height() : -1;
        return 1 + max(lh, rh);
    }
};