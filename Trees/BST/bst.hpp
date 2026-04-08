#include "mybinarytree.hpp" // already implemented, though hidden

class BST {
	BinaryTree* tree;
	int* arr;
	int index;
	int in;
	
	bool search(node* curr, int num){
	    if (curr == nullptr){
	        return false;
	    }	
	    
	    if (num == curr->elem){
	        return true;
	    } else if (num < curr->elem){
	        return search(tree->left(curr), num);
	    } else {
	        return search(tree->right(curr), num);
	    }
	}
	
	node* insert(node* curr, int num){
	    if (curr == nullptr){
	        return nullptr;
	    }
	    
	    if (num == curr->elem){
	        return nullptr;
	    }
	    
	    if (num < curr->elem){
	        if (curr->left == nullptr){
	            return curr;
	        }
	        return insert(curr->left, num);
	    } else {
	        if (curr->right == nullptr){
	            return curr;
	        } 
	        return insert(curr->right, num);
	    }
	}

	node* remove(node* curr, int num){
	    if (curr == nullptr){
	        return nullptr;
	    }
	    
	    if (num < curr->elem){
	        curr->left = remove(curr->left, num);
	    } else if (num > curr->elem){
	        curr->right = remove(curr->right, num);
	    } else {
	        if (curr->left == nullptr){
	            node* temp = curr->right;
	            tree->remove(curr);
	            return temp;
	        } else if (curr->right == nullptr){
	            node* temp = curr->left;
	            tree->remove(curr);
	            return temp;
	        }
	        
	        node* succ = curr->right;
	        while(succ->left != nullptr){
	            succ = succ->left;
	        }
	    
	        curr->elem = succ->elem;
	        curr->right = remove(curr->right, succ->elem);
	    }
	    
	    return curr;
	}

	public:
	BST() {
	    tree = new MyBinaryTree();
		index = 0;
		in = 0;
	}

	void treeToArray(node* n){
	    arr[index++] = n->elem;
        
        if (n->left){
            treeToArray(tree->left(n));
        } 
        if (n->right){
            treeToArray(tree->right(n));
        }
	}
	
	void sortArray(int* arr){
	    
	    for (int i = 0; i < tree->getSize(); i++){
	        for (int j = i + 1; j < tree->getSize() ; j++){
	            if (arr[i] > arr[j]){
	                int temp = arr[i];
	                arr[i] = arr[j];
	                arr[j] = temp;
	            }
	        }
	    }
	}
	
	void convertHelper(node* n){
	    n->elem = arr[in];
	    in++;
	    
	    if (n->left != nullptr){
	        convertHelper(n->left);
	        
	    }
	    if (n->right != nullptr){
	        convertHelper(n->right);
	    }
	    
	    
	}
	
	void convertToHeap() {
        arr = (int*)calloc(0, sizeof(int));
        treeToArray(tree->getRoot());
        sortArray(arr);
        
        convertHelper(tree->getRoot());
	}

	bool search(int num) { // TODO implement me
	    if (tree == nullptr || tree->getRoot() == nullptr){
	        return false;
	    }
	    
	    return search(tree->getRoot(), num);
	}

	bool insert(int num) { // TODO implement me
	    
        if (tree->getRoot() == nullptr){
            tree->addRoot(num);
            return true;
        }
        
        node* par = insert(tree->getRoot(), num);
        
        if (par == nullptr){
            return false;
        }
        
        if (num < par->elem){
            tree->addLeft(par, num);
        } else {
            tree->addRight(par, num);
        }
        
        return true;
	}

	bool remove(int num) {
        if (tree->getRoot() == nullptr || !search(num)){
            return false;
        }
        
        node* n = remove(tree->getRoot(), num);
        
        return true;
    }

	void print() { // DO NOT MODIFY
		tree->print();
	}
};