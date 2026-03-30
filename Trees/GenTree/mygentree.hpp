#include "gentree.hpp"
#include <iostream>
#include <cstdlib>
#include <stdexcept>
using namespace std;

class MyGenTree : public GenTree {
    int size;
    node* root;
    
    public:
    MyGenTree() {
        size = 0;
        root = nullptr;
    }
    
    node* addRoot(int num){
        if (root){
            throw logic_error("Already has root");
        }
        
        root = new node;
        root->elem = num;
        root->parent = nullptr;
        root->children = nullptr;
        root->children = (node**)realloc(root->children, 10 * sizeof(node*));
        root->num_child = 0;
        size++;
        
        return root;
    }    
    
    node* addChild(node* parent, int num){
        node* child = new node;
        child->elem = num;
        child->parent = parent;
        child->children = (node**)malloc(10 * sizeof(node*));
        child->num_child = 0;
        
        parent->num_child++;
        parent->children = (node**)realloc(parent->children, parent->num_child * sizeof(node*));
        parent->children[parent->num_child - 1] = child;
        size++;
        
        return child;
    }
    
    void remove(node* n){
        if (n->num_child > 0){
            cout << to_string(n->elem) << " has children" << endl;
            return;
        }
        
        if (n == root){
            delete[] root->children;
            delete root;
            root = nullptr;
            size = 0;
            return;
        }
        
        node* parent = n->parent;
        int index = -1;
        for (int i = 0; i < parent->num_child; i++){
            if (parent->children[i] == n){
                index = i;
                break;
            }
        }
        
        if (index != -1){
            for (int i = index; i < parent->num_child - 1; i++){
                parent->children[i] = parent->children[i + 1];
            }
            parent->num_child--;
        }
        
        delete[] n->children;
        delete n;
        size--;
        
        return;
    }
    
    int getSize(){
        return size;
    }
    
    node* getRoot(){
        return root;
    }
};