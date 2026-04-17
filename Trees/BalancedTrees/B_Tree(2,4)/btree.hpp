#include "node.hpp"
#include <iostream>
using namespace std;

class BTree {
	node* root;
	
	public:
	BTree() {
		root = nullptr;
	}

	bool insert(int num) {
		if (!root) {
			root = new node();
			root->insertKeyAt(num, 0);
			return true;
		}

		node* curr = root;

		while(curr->children_size != 0) {
			if (curr->contains(num)) return false;

			int i = 0;
			while (i < curr->size && num > curr->keys[i]) i++;

			curr = curr->children[i];
		}

		int pos = 0;
		while (pos < curr->size && num > curr->keys[pos]) pos++;
		curr->insertKeyAt(num, pos);

		if (curr->isFull()) split(curr);

		return true;
	}

	void split(node* curr) {
		int mid = curr->size / 2;
		int promote = curr->keys[mid];

		node* left = new node();
		node* right = new node();

		for (int i = 0; i < mid; i++) {
			left->insertKeyAt(curr->keys[i], i);
		}

		for (int i = mid + 1; i < curr->size; i++) {
			right->insertKeyAt(curr->keys[i], right->size);
		}

		if (curr->children_size != 0) {
            int i = 0;
            for (; i <= mid; i++) {
                left->children[i] = curr->children[i];
                if (left->children[i]) left->children[i]->parent = left;
            }
            left->children_size = i;

            int r_idx = 0;
            for (; i < curr->children_size; i++) {
                right->children[r_idx] = curr->children[i];
                if (right->children[r_idx]) right->children[r_idx]->parent = right;
                r_idx++;
            }
            right->children_size = r_idx;
        }

		if (curr->children_size != 0) {
            int i = 0;
            for (; i <= mid; i++) {
                left->children[i] = curr->children[i];
                if (left->children[i]) left->children[i]->parent = left;
            }
            left->children_size = i;

            int r_idx = 0;
            for (; i < curr->children_size; i++) {
                right->children[r_idx] = curr->children[i];
                if (right->children[r_idx]) right->children[r_idx]->parent = right;
                r_idx++;
            }
            right->children_size = r_idx;
        }

        if (curr == root) {
            node* parent = new node();
            parent->insertKeyAt(promote, 0);
            parent->children[0] = left;
            parent->children[1] = right;
            parent->children_size = 2;
            left->parent = parent;
            right->parent = parent;
            root = parent;
        } else {
            node* parent = curr->parent;
            
            int i = 0;
            while (i < parent->children_size && parent->children[i] != curr) i++;

            for (int j = parent->children_size; j > i + 1; j--) {
                parent->children[j] = parent->children[j - 1];
            }

            parent->children[i] = left;
            parent->children[i + 1] = right;
            left->parent = parent;
            right->parent = parent;
            parent->children_size++;

            int pos = 0;
            while (pos < parent->size && promote > parent->keys[pos]) pos++;
            parent->insertKeyAt(promote, pos);

            if (parent->isFull()) split(parent);
        }

        delete curr;
	}

	bool remove(int num) {
    if (!root) return false;

    bool res = removeNode(root, num);

    if (root->size == 0) {
        node* old = root;
        if (root->children_size > 0) {
            root = root->children[0];
            root->parent = nullptr;
        } else {
            root = nullptr;
        }
        delete old;
    }
    return res;
}
	
	void removeKey(node* curr, int idx) {
		for (int i = idx; i < curr->size - 1; i++) {
			curr->keys[i] = curr->keys[i + 1];
		}
		curr->size--;
	}

	bool removeNode(node* curr, int num) {
		int i = 0;
		while (i < curr->size && num > curr->keys[i]) i++;

		if (i < curr->size && curr->keys[i] == num) {
			if (curr->children_size == 0) {
				removeKey(curr, i); // Fix: use i, not 1
				return true;
			}
			
			node* predChild = curr->children[i];
			node* succChild = curr->children[i + 1];

			if (predChild->size > 1) {
				int pred = getPredecessor(predChild);
				curr->keys[i] = pred;
				return removeNode(predChild, pred);
			} else if (succChild->size > 1) {
				int succ = getSuccessor(succChild);
				curr->keys[i] = succ;
				return removeNode(succChild, succ);
			} else {
				fuse(curr, i);
				return removeNode(curr->children[i], num);
			}
		}

		if (curr->children_size == 0) return false; 

		if (curr->children[i]->size == 1) {
			fixChild(curr, i);
			if (i > curr->size) i = curr->size;
		}

		return removeNode(curr->children[i], num);
	}	

	int getPredecessor(node* curr) {
		while (curr->children_size != 0) {
			curr = curr->children[curr->children_size - 1];
		}	
		return curr->keys[curr->size - 1];
	}

	int getSuccessor(node* curr) {
		while (curr->children_size != 0) {
			curr = curr->children[0];
		}
		return curr->keys[0];
	}

	void fixChild(node* parent, int i) {

		if (i > 0 && parent->children[i - 1]->size > 1) {
			borrowFromLeft(parent, i);
			return;
		}

		if (i < parent->size && parent->children[i + 1]->size > 1) {
			borrowFromRight(parent, i);
			return;
		}

		if (i < parent->size) {
			fuse(parent, i);
		} else {
			fuse(parent, i - 1);
		}
	}
	
	void borrowFromLeft(node* parent, int i) {
		node* child = parent->children[i];
		node* left = parent->children[i - 1];

		for (int j = child->size; j > 0; j -- ) {
			child->keys[j] = child->keys[j-1];
		}

		child->keys [0] = parent->keys[i-1];
		child->size++;

		parent->keys[i - 1] = left->keys[left->size- 1];
		left->size --;
	}

	void borrowFromRight(node* parent, int i) {
		node* child = parent->children[i];
		node* right = parent->children[i + 1];

		child->keys[child->size++] = parent->keys[i];

		parent->keys[i] = right->keys[0];

		for (int j = 0; j < right->size - 1; j++) {
			right->keys[j] = right->keys[j+1];
		}

		right->size --;
	}

	void fuse(node* parent, int i) {
		if (!parent || i < 0 || i + 1 >= parent->children_size) return;

		node* left = parent->children[i];
		node* right = parent->children[i + 1];

		if (!left || !right) return;

		left->keys [left->size++] = parent->keys[i];

		for (int j = 0; j < right->size; j++) {
			left->keys[left->size++] = right->keys[j];
		}

		if (right->children_size > 0) {
			for (int j = 0; j < right->children_size; j++) {
				if (right->children[j]) {
					left->children[left->children_size++] = right->children[j];
					right->children[j]->parent = left;
				}
			}		
		}

		for (int j = i; j < parent->size - 1; j++) {
			parent->keys[j] = parent->keys[j + 1];
		}

		for (int j = i + 1; j < parent->children_size - 1; j++) {
			parent->children[j] = parent->children[j + 1];
		}

		parent->children[parent->children_size - 1] = nullptr;

		parent->size--;
		parent->children_size--;

		delete right;
	}


	// WARNING. Do not modify these methods.
    // Doing so will nullify your score for this activity.
	void print_node(string s, node* n) {
		cout << s << ": ";
		for (int i = 0; i < n->size; i++) {
			cout << n->keys[i] << " ";
		}
		cout << endl;
		for (int i = 0; i <= n->size; i++) {
			if (n->children[i]) {
				print_node("Child " + to_string(i+1) + " of " + s,n->children[i]);
			}
		}
	}
    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            if (!curr->parent) {
                cout << "Illegal parent of [" << curr->keys[0] << ",...]: NULL -- must be [" << par->keys[0] << ",...]" << endl;
            } else if (!par) {
                cout << "Illegal parent of [" << curr->keys[0] << ",...]: [" << curr->parent->keys[0] << ",...] -- must be NULL" << endl;
            } else {
                cout << "Illegal parent of [" << curr->keys[0] << ",...]: [" << curr->parent->keys[0] << ",...] -- must be [" << par->keys[0] << ",...]" << endl;
            }
            return false;
        }
        bool res = true;
        for (int i = 0; i < curr->size; i++) {
        	res &= check_parent(curr->children[i], curr);
		}
        return res;
    }

	void print() {
		print_node("Root", root);
		check_parent(root, NULL);
	}
};